#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "functions2.h"

void main()
{
	int n;
	float* arr = NULL;
	CreateArray(n, arr);
	try {
		SwapArray(n, arr);
		Print(n, arr);
	}
	catch (const char* ex) {
		std::cout << ex;
	}
	delete[]arr;
}