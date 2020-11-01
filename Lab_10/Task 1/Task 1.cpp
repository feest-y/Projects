#include <iostream>
#include<cmath>
#include<ctime>
void FillArray(int* const arr, const int SIZE = 9)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
}
void FillArray(int* const arr[], const int ROWS = 3, const int COLLS = 3)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = rand() % 9 + 1;
		}
	}
}
void PrintArray(const int* const arr, const int size = 9)
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

void ArrayToMatrix(int* const Arr, int* const Brr[], const int SIZE = 9) {
	int rNc = (int)ceil(sqrt(SIZE)), k = 0, a = 0;
	for (int i = 0; i < rNc; i++)
	{
		k = rNc * i;
		for (int j = 0; j < rNc; j++)
		{
			if (a < SIZE) {
				Brr[i][j] = Arr[j + k];
			}
			else Brr[i][j] = 0;
			a++;
		}
	}
}
void MatrixToArray(int* const Arr, int* const Brr[], const int ROWS = 3, const int COLLS = 3, const int SIZE = 9) {
	int k = 0;
	for (int i = 0; i < ROWS; i++)
	{
		k = ROWS * i;
		for (int j = 0; j < COLLS; j++)
		{
			Arr[j + k] = Brr[i][j];
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int rows, colls, size;
	printf("Введите размерость массива > ");
	scanf_s("%d", &size);
	colls = (int)ceil(sqrt(size));
	rows = size / colls;

	int* Arr = new int[size];
	int** Brr = new int* [colls];
	for (int i = 0; i < colls; i++)
		Brr[i] = new int[colls];

	FillArray(Brr, rows, colls);
	PrintArray(Brr, rows, colls);
	delete[]Arr;
	for (int i = 0; i < colls; i++) delete[] Brr[i];
	delete[]Brr;
}