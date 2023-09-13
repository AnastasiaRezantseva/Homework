#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "functions1.h"
#include "functionLib.h"

void main()
{
	int n;
	float* arr = NULL;
	CreateArrayFloat(n, arr);
	try {
		Replace(n, arr);
		PrintFloat(n, arr);
	}
	catch (const char* ex) {
		std::cout << ex;
	}
	delete []arr;
}