#include "functions1.h"
#include <iostream>
#include <math.h>

void CreateArray(int& n, float*& arr) 
{
	std::cout << "Enter n \n";
	std::cin >> n;
	arr = new float[n];
	std::cout << "Enter elements \n";
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
};

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

void Print(int n, float* arr)
{
	std::cout << "New array \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] <<" ";
	}
};
