#include <iostream>
#include <ctime>

void FillArray(int* const arr, const int SIZE = 8)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}
}
void FillArray(int* const arr[], const int ROWS = 9, const int COLLS = 9)
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
void PrintArray(const int* const arr[], const int ROWS = 9, const int COLLS = 9)
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

void TurnArrayLeft(int* const arr[], const int ROWS = 9, const int COLLS = 9)
{
	int Buffer[9][9] = {};
	for (int i = 0; i < ROWS; i++)
	{

		for (int j = 0; j < COLLS; j++)
		{
			Buffer[i][j] = arr[j][ROWS-i-1];
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = Buffer[i][j];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int ROWS = 9, COLLS = 9;
	int** Arr = new int* [ROWS];
	for (int i = 0; i < COLLS; i++)
		Arr[i] = new int[COLLS];
	FillArray(Arr);
	printf("Original Array:\n");
	PrintArray(Arr);
	printf("\n");
	printf("\n");
	TurnArrayLeft(Arr);
	printf("Turned Array:\n");
	PrintArray(Arr);
	return 0;
}