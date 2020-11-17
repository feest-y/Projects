#include <iostream>
#include <ctime>
using namespace std;
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
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int ROWS = 3, COLLS = 3;
	int** Arr = new int* [ROWS];
	for (int i = 0; i < COLLS; i++) Arr[i] = new int[COLLS];
	int Buff = 10, index = 0, k = 0;
	FillArray(Arr, ROWS, COLLS);
	printf("Original Array:\n");
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
		Arr[i][index] = Arr[i][0];
		Arr[i][0] = Buff;
	}



	printf("\nMax in ROWS:\n");
	PrintArray(Arr, ROWS, COLLS);


	//for (int j = 0; j < COLLS; j++)
	//{
	//	Buff = Arr[0][j];
	//	for (int i = 0; i < ROWS; i++)
	//	{
	//		if (Arr[i][j] < Buff)
	//		{
	//			Buff = Arr[i][j];
	//			index = i;
	//		}
	//	}
	//	//cout << "Минимальное значение в " << j + 1 << " столбце " << "и в " << index+1<< " строке " << Buff << endl;
	//}

	for (int i = 0; i < ROWS; i++)
	{
		Buff = 1000;
		for (int j = 0; j < COLLS; j++)
		{
			if (Buff > Arr[j][i])
			{
				Buff = Arr[j][i];
				index = j;
			}
		}
		Arr[index][i] = Arr[2][i];
		Arr[2][i] = Buff;
	}

	printf("\nMin in COLLS\n");
	PrintArray(Arr, ROWS, COLLS);


	for (int i = 0; i < ROWS; i++) delete[] Arr[i];
	delete[]Arr;
	return 0;
}