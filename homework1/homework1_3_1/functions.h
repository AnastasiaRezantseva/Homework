#ifndef  _FUNCTIONS_H_
#define  _FUNCTIONS_H_

void CreateArray(int& n, int*& arr);

int FindMin(int n, int* arr);
int FindMax(int n, int* arr);
void FillArrayByZero(int n, int* arr);

int GetNumberOfUniques(int n, int* arr, int sizeCount, int* count, int min);
int* RemoveRepeats(int sizeCount, int* count, int n, int* arr, int countUniqes, int min);

void Print(int n, int* arr);

#endif

