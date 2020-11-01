#include <iostream>
#include<cmath>
void FillArray(int* const arr, const int SIZE = 8)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}
}
void FillArray(int* const arr[], const int ROWS = 3, const int COLLS = 3)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = rand() % 99 + 1;
		}
	}
}
void PrintArray(const int* const arr, const int size = 8)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void PrintArray(const int* const arr[], const int ROWS = 3, const int COLLS = 3)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			printf("%2.d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\b");
}

void ArrayToMatrix(const int* const Arr, const int* const Brr[], const int SIZE = 8) {

}
int main()
{
	int ROWS = 3, COLLS = 3, SIZE = 8;
	int* Arr = new int[SIZE];
	int** Brr = new int* [ROWS];
	for (int i = 0; i < COLLS; i++)
		Brr[i] = new int[COLLS];

	FillArray(Arr);
}