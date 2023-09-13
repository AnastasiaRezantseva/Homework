#include "functions1.h"
#include <iostream>
#include <math.h>

void Replace(int n, float* arr) 
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 10)
		{
			arr[i] = sqrt(arr[i]);
		}
	}
};
