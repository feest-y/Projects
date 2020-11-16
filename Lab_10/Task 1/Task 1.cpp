#include <iostream>
#include<cmath>
#include<ctime>
void FillArray(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
}
void FillArray(int* const arr[], const int ROWS, const int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = rand() % 9 + 1;
		}
	}
}
void PrintArray(const int* const arr, int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void PrintArray(const int* const arr[], const int ROWS, const int COLLS)
{
	printf("\n");
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
void ConvertArray(int* const Brr[], const int ROWS, const int COLLS)
{
	int* Buff = new int[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		Buff[i] = Brr[i][ROWS - i - 1];
	}
	for (int i = 0; i < ROWS; i++)
	{

		Brr[i][0] *= Buff[i];
	}
}
void ArrayToMatrix(int* const Arr, int* const Brr[], const int SIZE) {
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
void MatrixToArray(int* const Brr[], int* const Arr, const int ROWS, const int COLLS) {
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
	printf("Введите размерость одномерного массива > ");
	scanf_s("%d", &size);
	while (((int)(sqrt(size))) != sqrt(size))
	{
		system("cls");
		printf("Вы ввели некорректное значение, так его квадратный корень не целое цисло > \n");
		printf("Введите размерость массива > ");
		scanf_s("%d", &size);
	}

	colls = rows = (int)sqrt(size);

	int* Arr = new int[size];
	int** Brr = new int* [colls];
	for (int i = 0; i < colls; i++)
		Brr[i] = new int[colls];

	printf("\nОдномерный массив >");
	FillArray(Arr, size);
	PrintArray(Arr, size);
	printf("\nПреобразование массива в матрицу >");
	ArrayToMatrix(Arr, Brr, size);
	PrintArray(Brr, rows, colls);
	printf("\nПосле операций над матрицой >");
	ConvertArray(Brr, rows, colls);
	PrintArray(Brr, rows, colls);
	printf("\nПреобразование матрицы обратно в массив >");
	MatrixToArray(Brr, Arr, rows, colls);
	PrintArray(Arr, size);
	delete[]Arr;
	for (int i = 0; i < colls; i++) delete[] Brr[i];
	delete[]Brr;
	return 0;
}