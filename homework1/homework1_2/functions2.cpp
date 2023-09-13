#include "functions2.h"
#include <iostream>



void SwapArray(int n, float* arr)
{
	int j = n / 2;

	for (int i = 0; i < (n / 2); i++)
	{
		Swap(arr[i], arr[i + j]);
	}

	
};

void Swap(float& a, float& b)
{
	float tmp = a;
	a = b;
	b = tmp;
}
