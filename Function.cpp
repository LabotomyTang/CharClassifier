#include "Function.h"

double rand01() {
	double result = (double)rand() / 32768.0;
	return result;
}

int exp(int basis, int exp) {
	int result = 1;
	for (int i = 0; i < exp; ++i) {
		result *= basis;
	}
	return result;
}