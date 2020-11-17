#include <iostream>
void FillArray(int* const arr[], const int ROWS, const int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = rand() % 200 - 100;
		}
	}
}
void PrintArray(const int* const arr[], const int ROWS, const int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			printf("%4.d ", arr[i][j]);
			if (arr[i][j] == 0)
			{
				printf("\b\b0 ");
			}
		}
		printf("\n");
	}
	printf("\b");
}
int PositiveInRow(int* const Arr[], const int ROWS, const int COLLS, int row) {
	int n = 0;
	for (int j = 0; j < COLLS; j++)
	{
		if (Arr[row][j] > 0)
		{
			n++;
		}
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int rows, colls;
	printf("Введите размерность матрицы Arr:\n\tСтроки > ");
	scanf_s("%d", &rows);
	printf("\tСтолбцы > ");
	scanf_s("%d", &colls);

	int** Arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		Arr[i] = new int[colls];

	FillArray(Arr, rows, colls);
	PrintArray(Arr, rows, colls);
	for (int i = 0; i < rows; i++)
	{
		printf("\n%d row: %d", i + 1, PositiveInRow(Arr, rows, colls, i));
	}

	for (int i = 0; i < rows; i++) delete[] Arr[i];
	delete[]Arr;
}