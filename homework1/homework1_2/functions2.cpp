#include "functions2.h"
#include <iostream>

void CreateArray(int& n, float*& arr)
{
	std::cout << "Enter n - even number \n";
	std::cin >> n;

	while (n % 2 != 0)
	{
		std::cout << "Please, enter n - even number \n";
		std::cin >> n;
	}
	arr = new float[n];
	std::cout << "Enter elements \n";
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
};

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

void Print(int n, float* arr)
{
	std::cout << "New array \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
};
