#include <iostream>
#include <stdio.h>
#include "functions.h"
#include "functionLib.h"
void main()
{
	int n;
	int* arr = NULL;
	int* count = NULL;
	int* new_arr = NULL;
	CreateArrayInt(n, arr);
	try {
		int min = FindMin(n, arr);
		int max = FindMax(n, arr);
		int SizeCountArray = max - min + 1;
		count = new int[SizeCountArray];

		FillArrayByZero(SizeCountArray, count);
		int resultCount = GetNumberOfUniques(n, arr, SizeCountArray, count, min);
		new_arr = RemoveRepeats(SizeCountArray, count, n, arr, resultCount, min);
		PrintInt(resultCount, new_arr);
	}
	catch (const char* ex) {
		std::cout << ex;
	}
	delete[]arr;
	delete[]count;
	delete[]new_arr;
}