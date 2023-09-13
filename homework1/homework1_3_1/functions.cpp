#include "functions.h"
#include <iostream>



int FindMin(int n, int* arr)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int FindMax(int n, int* arr)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void FillArrayByZero(int n, int* arr)
{
	for (int i = 0; i < n; ++i) {
		arr[i] = 0;
	}
}

int GetNumberOfUniques(int n, int* arr, int sizeCount, int* count, int min) {
	int countUniqes = 0;
	for (int i = 0; i < n; i++)
	{
		if (count[arr[i] - min] == 0) {
			countUniqes++;
			count[arr[i] - min] = 1;
		}
	}
	FillArrayByZero(sizeCount, count);
	return countUniqes;
}

int* RemoveRepeats(int sizeCount, int* count, int n, int* arr, int countUniqes, int min)
{
	int* result = new int[countUniqes];
	int resultIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (count[arr[i] - min] == 0) {
			result[resultIndex++] = arr[i];
			count[arr[i] - min] = 1;
		}
	}
	return result;
}


