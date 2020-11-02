#include <iostream>
#include <ctime>
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

	int** Arr = new int* [colls_A];
	for (int i = 0; i < colls_A; i++) Arr[i] = new int[rows_A];


	int** Brr = new int* [colls_B];
	for (int i = 0; i < colls_B; i++) Brr[i] = new int[rows_B];


	FillArray(Arr,rows_A,colls_A);
	FillArray(Brr,rows_B,colls_B);
	printf("\nArr:\n");
	PrintArray(Arr, rows_A, colls_A);
	printf("\n");
	printf("\n");
	printf("Brr:\n");
	PrintArray(Brr, rows_B, colls_B);



}