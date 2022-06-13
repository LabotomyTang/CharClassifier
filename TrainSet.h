#pragma once
#include "InputChar.h"

const int trainSetSize = 100;
const int valueSet[100][26] = {
	{
		1, 1, 1, 1, 0,
		1, 0, 0, 1, 0,
		1, 0, 0, 1, 0,
		1, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		0
	},
	{
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 1,
		0, 1, 0, 0, 1,
		0, 1, 0, 0, 1,
		0, 1, 1, 1, 1,
		0
	},
	{
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		1, 0, 0, 0, 0,
		1
	},
	{
		0, 1, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 1, 0, 0, 0,
		1
	},
	{
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		1
	},
	{
		0, 0, 0, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 1, 0,
		1
	},
	{
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		1
	},
	{
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		1, 0, 0, 0, 0,
		1, 1, 1, 1, 0,
		2
	},
	{
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 0,
		0, 1, 1, 1, 1,
		2
	},
	{
		1, 1, 1, 0, 0,
		0, 0, 1, 0, 0,
		1, 1, 1, 0, 0,
		0, 0, 1, 0, 0,
		1, 1, 1, 0, 0,
		3
	},
	{
		0, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		0, 1, 1, 1, 0,
		3
	},
	{
		0, 0, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 0, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 0, 1, 1, 1,
		3
	},
	{
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		3
	},
	{
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 1, 1, 1, 1,
		3
	},
	{
		1, 0, 0, 1, 0,
		1, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 1, 0,
		4
	},
	{
		0, 1, 0, 0, 1,
		0, 1, 0, 0, 1,
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		4
	},
	{
		1, 1, 1, 1, 0,
		1, 0, 0, 0, 0,
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		5
	},
	{
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 0,
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 1, 1, 1, 1,
		5
	},
	{
		1, 1, 1, 0, 0,
		1, 0, 0, 0, 0,
		1, 1, 1, 1, 0,
		1, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		6
	},
	{
		0, 1, 1, 1, 0,
		0, 1, 0, 0, 0,
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 1,
		0, 1, 1, 1, 1,
		6
	},
	{
		1, 1, 1, 1, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 1, 0, 0, 0,
		0, 1, 0, 0, 0,
		7
	},
	{
		0, 1, 1, 1, 1,
		0, 0, 0, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		7
	},
	{
		1, 1, 1, 1, 0,
		1, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		1, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		8
	},
	{
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 1,
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 1,
		0, 1, 1, 1, 1,
		8
	},
	{
		1, 1, 1, 1, 0,
		1, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		1, 1, 1, 1, 0,
		9
	},
	{
		0, 1, 1, 1, 1,
		0, 1, 0, 0, 1,
		0, 1, 1, 1, 1,
		0, 0, 0, 0, 1,
		0, 1, 1, 1, 1,
		9
	}
};

void initInputArr(InputChar* inputArr, int length) {
	for (int i = 0; i < trainSetSize && i < length; ++i) {
		inputArr[i] = InputChar(valueSet[i], valueSet[i][25]);
	}
}