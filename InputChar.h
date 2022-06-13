#pragma once
#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<ctime>
#include<cmath>
#include<iostream>

#include<vector>

using namespace std;

class InputChar {
public:

	int value[26];
	int type;

	InputChar();

	InputChar(const int* _value, const int _type);

	int& operator[](int index);

	int operator[](int index) const;

	InputChar& operator=(const InputChar& another);

	void setValue(const int* _value, const int _type);

	void print();
};