#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "functions3.h"

void main()
{
	int n;
	int* arr = NULL;
	int* new_arr = NULL;
	CreateArray(n, arr);
	try {
		QuickSort(n, arr);
		int resultCount = GetNumberOfUniques(n, arr);
		new_arr = RemoveRepeats(n, arr, resultCount);
		Print(resultCount, new_arr);
	}
	catch (const char* ex) {
		std::cout << ex;
	}
	delete[]arr;
	delete[]new_arr;
}