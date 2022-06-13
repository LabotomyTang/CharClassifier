#pragma once
#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<ctime>
#include<cmath>
#include<iostream>
#include<conio.h>

#include "Function.h"
#include "InputChar.h"

using namespace std;

class Classifier1 {
public:
	InputChar inputChar;
	double mid0_1[20];
	int output[10];
	double outputDouble[10];

	double weight0[26][20];
	double weight1[20][10];
	double speed;

	Classifier1();

	void train(InputChar* inputArr, int length);

	double activate0_1(double input);

	double activate1_2(double input);

	void classify(const InputChar& input);

	void classify(const InputChar& input, int* _output, double* _mid0_1);

	void printOutput();
};

