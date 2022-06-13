#include "Classifier1.h"

Classifier1::Classifier1() {
	for (int i = 0; i < 20; ++i) {
		mid0_1[i] = 0;
	}
	for (int i = 0; i < 10; ++i) {
		output[i] = 0;
		outputDouble[i] = 0;
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 20; ++j) {
			weight0[i][j] = rand01() * 2 - 1;
		}
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			weight1[i][j] = rand01() * 2 - 1;
		}
	}
	speed = 0.01;
}

void Classifier1::train(InputChar* inputArr, int length) {

	double** mid0_1Arr = new double* [length];
	int** outputArr = new int* [length];
	for (int i = 0; i < length; ++i) {
		mid0_1Arr[i] = new double[20];
		outputArr[i] = new int[10];
	}

	int** expectedArr = new int* [length];
	for (int i = 0; i < length; ++i) {
		expectedArr[i] = new int[10];
		for (int j = 0; j < 10; ++j) {
			expectedArr[i][j] = 0;
		}
		expectedArr[i][inputArr[i].type] = 1;
	}

	double preError = 0;
	double error = 0;
	int delta = 0;

	int count = 0;
	while (true) {
		preError = error;
		error = 0;

		count++;
		for (int i = 0; i < length; ++i) {
			classify(inputArr[i], outputArr[i], mid0_1Arr[i]);
			for (int i1 = 0; i1 < 10; ++i1) {
				delta = expectedArr[i][i1] - outputArr[i][i1];
				error += delta * delta;
				for (int i2 = 0; i2 < 20; ++i2) {
					for (int i3 = 0; i3 < 26; ++i3) {
						weight0[i3][i2] += speed * delta * inputArr[i][i3];
					}
					weight1[i2][i1] += speed * delta * mid0_1Arr[i][i2];
				}
			}
		}
		
		if (error <= 20) break;
	}

	printf("\nÑµÁ·Íê±Ï£ºcount = %d; last error = %.0f\n", count, error);

	for (int i = 0; i < length; ++i) {
		delete[] mid0_1Arr[i];
		delete[] outputArr[i];
		delete[] expectedArr[i];
	}
	delete[] mid0_1Arr;
	delete[] outputArr;
	delete[] expectedArr;
}


double Classifier1::activate0_1(double input) {
	double result = 1 / (1 + exp(-input));
	return result;
}

double Classifier1::activate1_2(double input) {
	double result = 2 / (1 + exp(-input)) - 1;
	return result;
}

void Classifier1::classify(const InputChar& input) {
	inputChar = input;
	for (int i = 0; i < 20; ++i) {
		mid0_1[i] = 0;
		for (int j = 0; j < 26; ++j) {
			mid0_1[i] += inputChar[j] * weight0[j][i];
		}
		mid0_1[i] = activate0_1(mid0_1[i]);
	}
	for (int i = 0; i < 10; ++i) {
		outputDouble[i] = 0;
		output[i] = 0;
		for (int j = 0; j < 20; ++j) {
			outputDouble[i] += mid0_1[j] * weight1[j][i];
		}
		if (outputDouble[i] >= 0) {
			output[i] = 1;
		}
		else {
			output[i] = 0;
		}
	}
}

void Classifier1::classify(const InputChar& input, int* _output, double* _mid0_1) {
	double tmpMid0_1[20] = { 0 };
	double tmpOutputDouble[10] = { 0 };
	for (int i = 0; i < 20; ++i) {
		tmpMid0_1[i] = 0;
		for (int j = 0; j < 26; ++j) {
			tmpMid0_1[i] += inputChar[j] * weight0[j][i];
		}
		tmpMid0_1[i] = activate0_1(tmpMid0_1[i]);
		_mid0_1[i] = tmpMid0_1[i];
	}
	for (int i = 0; i < 10; ++i) {
		tmpOutputDouble[i] = 0;
		_output[i] = 0;
		for (int j = 0; j < 20; ++j) {
			tmpOutputDouble[i] += tmpMid0_1[j] * weight1[j][i];
		}
		if (tmpOutputDouble[i] >= 0) {
			_output[i] = 1;
		}
		else {
			_output[i] = 0;
		}
	}
}

void Classifier1::printOutput() {
	printf("\n");
	bool onlyOne = false;
	int index = 0;
	bool moreThanOne = false;
	for (int i = 0; i < 10; ++i) {
		printf("%6d", i);
	}
	printf("\n");
	for (int i = 0; i < 10; ++i) {
		printf("%6.2f", outputDouble[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; ++i) {
		printf("%6d", output[i]);
		if (output[i] == 1) {
			if (onlyOne == true) {
				onlyOne = false;
				moreThanOne = true;
			}
			if (moreThanOne == false) {
				onlyOne = true;
				index = i;
			}
		}
	}
	printf("\n=> ");
	if (onlyOne) {
		printf("%d", index);
	}
	else {
		printf("not classified");
	}
	printf("\n");
}