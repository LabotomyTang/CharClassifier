#include "Classifier2.h"

Classifier2::Classifier2() {
	for (int i = 0; i < 10; ++i) {
		output[i] = 0;
		outputDouble[i] = 0;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			weight[i][j] = rand01() * 2 - 1;
		}
	}
	speed = 0.01;
}

void Classifier2::train(InputChar* inputArr, int length) {
	int** outputArr = new int* [length];
	for (int i = 0; i < length; ++i) {
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

	double error = 0;

	while (true) {
		error = 0;
		for (int i = 0; i < length; ++i) {
			classify(inputArr[i], outputArr[i]);
		}
		for (int i = 0; i < length; ++i) {
			for (int i1 = 0; i1 < 10; ++i1) {
				for (int i2 = 0; i2 < 10; ++i2) {
					error += (expectedArr[i][i1] - outputArr[i][i1]) * (expectedArr[i][i1] - outputArr[i][i1]);
					weight[i2][i1] += speed * (expectedArr[i][i1] - outputArr[i][i1]) * inputArr[i][i2];
				}
			}
		}
		if (error < 1) break;
	}

	printf("\nÑµÁ·Íê±Ï\n");

	for (int i = 0; i < length; ++i) {
		delete[] outputArr[i];
		delete[] expectedArr[i];
	}
	delete[] outputArr;
	delete[] expectedArr;
}

void Classifier2::classify(const InputChar& input) {
	inputChar = input;
	int param[10] = { 0 };
	for (int i = 0; i < 25; ++i) {
		if (inputChar[i]) {
			param[i / 5] += exp(2, i % 5);
			param[i % 5] += exp(2, i / 5);
		}
	}
	for (int i = 0; i < 10; ++i) {
		outputDouble[i] = 0.0;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			outputDouble[j] += param[i] * weight[i][j];
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (outputDouble[i] >= 0) {
			output[i] = 1;
		}
		else {
			output[i] = 0;
		}
	}
}

void Classifier2::classify(const InputChar& input, int* _output) {
	int param[10] = { 0 };
	for (int i = 0; i < 25; ++i) {
		if (input[i]) {
			param[i / 5] += exp(2, i % 5);
			param[i % 5] += exp(2, i / 5);
		}
	}
	double outputD[10];
	for (int i = 0; i < 10; ++i) {
		outputD[i] = 0.0;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			outputD[j] += param[i] * weight[i][j];
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (outputD[i] >= 0) {
			_output[i] = 1;
		}
		else {
			_output[i] = 0;
		}
	}
}

void Classifier2::printOutput() {
	printf("\n");
	bool onlyOne = false;
	int index = 0;
	bool moreThanOne = false;
	for (int i = 0; i < 10; ++i) {
		printf("%6d", i);
	}
	printf("\n");
	/*for (int i = 0; i < 10; ++i) {
		printf("%6.2f", outputDouble[i]);
	}*/
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