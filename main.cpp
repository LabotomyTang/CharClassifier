#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<ctime>
#include<cmath>
#include<iostream>
#include<conio.h>

#include "InputChar.h"
#include "TrainSet.h"

#include "Classifier0.h"
#include "Classifier1.h"
#include "Classifier2.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand((unsigned)time(NULL));

	InputChar* inputArr = new InputChar[trainSetSize];
	initInputArr(inputArr, trainSetSize);

	Classifier0 classifier;
	classifier.train(inputArr, trainSetSize);

	InputChar charR = inputArr[rand() % 20];
	
	classifier.classify(charR);
	classifier.inputChar.print();
	classifier.printOutput();
	system("pause");
	bool exit = false;

	while (!exit) {
		charR = inputArr[rand() % 20];
		for (int j = 0; j < 25; ++j) {
			if (rand() % 16) continue;
			charR.value[j] = 1 - charR.value[j];
		}
		classifier.classify(charR);
		classifier.inputChar.print();
		classifier.printOutput();
		printf("\n按x键退出，否则继续\n");
		if (_getch() == 'x') {
			exit = true;
		}
	}
	return 0;
}