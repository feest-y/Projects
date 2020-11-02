#include <iostream>
#include <ctime>

void FillArray(int* const arr, const int SIZE = 9)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
}
void FillArray(int* const arr[], const int ROWS = 9, const int COLLS = 9)
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

int main()
{
	srand(time(NULL));
	int ROWS = 3, COLLS = 3;
	int** Arr = new int* [ROWS];
	for (int i = 0; i < COLLS; i++) Arr[i] = new int[COLLS];
	int Buff = 10, index = 0, k = 0;
	FillArray(Arr, ROWS, COLLS);
	PrintArray(Arr, ROWS, COLLS);
	for (int i = 0; i < ROWS; i++)
	{
		Buff = 0;
		for (int j = 0; j < COLLS; j++)
		{
			if (Arr[i][j] > Buff)
			{
				Buff = Arr[i][j];
				index = j;
			}
		}
		Arr[i][0] = Arr[i][index];
	}
	printf("\nMax in ROWS");
	printf("\n");
	PrintArray(Arr, ROWS, COLLS);
	Buff = 10;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			if (Arr[j][i] < Buff)
			{
				Buff = Arr[j][i];
				index = i;
			}
		}
		Buff[index][i] = Buff[9][i];
	}

	printf("\nMin in COLLS");
	printf("\n");
	PrintArray(Arr, ROWS, COLLS);


	for (int i = 0; i < ROWS; i++) delete[] Arr[i];
	delete[]Arr;
	return 0;
}