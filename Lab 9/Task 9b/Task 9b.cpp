#include <iostream>
#include <ctime>
void FillArray(int* const arr[], const int ROWS, const int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = rand() % 5 + 1;
		}
	}
}
void PrintArray(const int* const arr[], const int ROWS, const int COLLS)
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
void MatrixMultiply(int* const Arr[], const int rows_A, const int colls_A, int* const Brr[], const int rows_B, const int colls_B) {
	int rows_C = rows_A, colls_C = colls_B;
	int** Crr = new int* [rows_C];
	for (int i = 0; i < rows_C; i++)
		Crr[i] = new int[colls_C];

	for (int i = 0; i < rows_C; i++)
	{
		for (int j = 0; j < colls_C; j++)
		{
			Crr[i][j] = 0;
			for (int a = 0; a < colls_A; a++)
			{
				Crr[i][j] += Arr[i][a] * Brr[a][j];
			}
		}
	}

	//Вывод
	
	for (int i = 0; i < rows_C; i++)
	{
		for (int j = 0; j < colls_C; j++)
		{
			printf("%3.d ", Crr[i][j]);
		}
		printf("\n");
	}
	printf("\b");
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int rows_A, rows_B, colls_A, colls_B;

	printf("Введите размерность матрицы А:\n\tСтроки > ");
	scanf_s("%d", &rows_A);
	printf("\tСтолбцы > ");
	scanf_s("%d", &colls_A);

	printf("\nВведите размерность матрицы B:\n\tСтроки > ");
	scanf_s("%d", &rows_B);
	printf("\tСтолбцы > ");
	scanf_s("%d", &colls_B);

	while (colls_A != rows_B)
	{
		printf("Умножение матриц невозможно, длина первой должна соответствовать ширине второй");
		printf("\nВведите размерность матрицы А:\n\tСтроки > ");
		scanf_s("%d", &rows_A);
		printf("\tСтолбцы > ");
		scanf_s("%d", &colls_A);

		printf("\nВведите размерность матрицы B:\n\tСтроки > ");
		scanf_s("%d", &rows_B);
		printf("\tСтолбцы > ");
		scanf_s("%d", &colls_B);
	}

	int** Arr = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
		Arr[i] = new int[colls_A];

	int** Brr = new int* [rows_B];
	for (int i = 0; i < rows_B; i++)
		Brr[i] = new int[colls_B];

	FillArray(Arr, rows_A, colls_A);
	FillArray(Brr, rows_B, colls_B);
	printf("\nArr:\n");
	PrintArray(Arr, rows_A, colls_A);
	printf("\n\nBrr:\n");
	PrintArray(Brr, rows_B, colls_B);
	printf("\n\nArr*Brr:\n");
	MatrixMultiply(Arr,rows_A,colls_A,Brr,rows_A,colls_B);
	return 0;
}