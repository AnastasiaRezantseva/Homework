#include "functions3.h"
#include <iostream>

void CreateArray(int& n, int*& arr)
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

void QuickSort(int n, int* arr) //quick sort (Hoar)
{
	int tmp, i = 0;
	int j = n - 1;
	int mid = (i + j) / 2;
	int pivot = arr[mid];

	do
	{
		while (arr[i] < pivot)
		{
			i++;
		}

		while (arr[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		QuickSort(j + 1, arr);
	}
	if (i < n)
	{
		QuickSort(n - i, &arr[i]);
	}

}

int GetNumberOfUniques(int n, int* arr) {
	int count = 1;
	int current = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] != current) {
			count++;
			current = arr[i];
		}
	}
	return count;
}

int* RemoveRepeats(int& n, int*& arr, int count)
{
	int* result = new int[count];
	result[0] = arr[0];
	int resultIndex = 1;
	int current = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] != current) {
			current = arr[i];
			result[resultIndex] = arr[i];
			resultIndex++;
		}
	}
	return result;
}

void Print(int n, int* arr)
{
	std::cout << "New array \n";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
};
