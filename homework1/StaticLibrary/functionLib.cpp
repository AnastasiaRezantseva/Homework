#include "functionLib.h"
#include <iostream>

void CreateArrayFloat(int& n, float*& arr)
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

void PrintFloat(int n, float* arr)
{
	std::cout << "New array \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
};

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
void CreateArrayInt(int& n, int*& arr)
{
	std::cout << "Enter n \n";
	std::cin >> n;
	arr = new int[n];
	std::cout << "Enter elements \n";
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
};

void PrintInt(int n, int* arr)
{
	std::cout << "New array \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
};
