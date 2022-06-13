#include "InputChar.h"

InputChar::InputChar() {
	for (int i = 0; i < 25; ++i) {
		value[i] = 0;
	}
	value[25] = 1;
	type = -1;
}

InputChar::InputChar(const int* _value, const int _type) {
	for (int i = 0; i < 25; ++i) {
		value[i] = (_value[i]) ? 1 : 0;
	}
	value[25] = 1;
	type = _type;
}

int& InputChar::operator[](int index) {
	return value[index];
}

int InputChar::operator[](int index) const {
	return value[index];
}

InputChar& InputChar::operator=(const InputChar& another) {
	for (int i = 0; i < 26; ++i) {
		value[i] = another.value[i];
		type = another.type;
	}
	return *this;
}

void InputChar::setValue(const int* _value, const int _type) {
	for (int i = 0; i < 25; ++i) {
		value[i] = (_value[i]) ? 1 : 0;
	}
	value[25] = 1;
	type = _type;
}

void InputChar::print() {
	printf("\n");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (value[i * 5 + j]) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");
}