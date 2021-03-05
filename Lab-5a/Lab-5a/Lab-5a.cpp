#include <iostream>
#include "..\..\Header\Header.h"
using namespace std;


int* Sum(int** Arr, int* MinColls = 0, int* MaxRows = 0, const int rows = 9, const int colls = 9, int* SumGD = 0, int* MulPD = 0) {
	int* result = new int[2];
	int min = _I32_MAX;
	int max = _I32_MIN;
	SumGD = new int[1]{};
	MulPD = new int[1]{ 1 };

	MinColls = new int[colls];
	MaxRows = new int[rows];
	for (int i = 0; i < rows; i++)//минималные в колонках
	{
		min = _I32_MAX;
		for (int j = 0; j < colls; j++)
		{
			if (min > Arr[j][i])
			{
				min = Arr[j][i];
			}
		}
		MinColls[i] = min;
	}
	cout << endl << "Colls > ";

	for (int i = 0; i < colls; i++)
		cout << MinColls[i] << " ";

	for (int i = 0; i < rows; i++)//максимальные в строках
	{
		max = _I32_MIN;
		for (int j = 0; j < colls; j++)
		{
			if (max < Arr[i][j])
			{
				max = Arr[i][j];
			}
		}
		MaxRows[i] = max;
	}

	cout << endl << "Rows > ";
	for (int i = 0; i < rows; i++)
		cout << MaxRows[i] << " ";
	cout << endl << endl;

	for (int i = 0; i < colls; i++)
	{
		*SumGD += Arr[i][i];
	}


	//int* Check = new int [colls] {};

	for (int i = colls - 1; i >= 0; i--)
	{
		*MulPD *= Arr[i][colls - i - 1];
		//Check[i] = Arr[i][colls - i - 1];
	}

	//PrintArray(Check, colls);

	result[0] = *SumGD; result[1] = *MulPD;
	return result;
}


int main()
{
	Standart();
	int rows = 3, colls = 3;
	int** Arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		Arr[i] = new int[colls];

	FillArray(Arr, rows, colls, 1, 9);
	PrintArray(Arr, rows, colls);

	int* MinInColls = 0, * MaxInrows = 0;
	int* result = new int[2];

	result = Sum(Arr, MinInColls, MaxInrows, rows, colls);
	printf("Sum > %d\nMul > %d", result[0], result[1]);

	for (int i = 0; i < rows; i++)
		delete[] Arr[i];
	delete[] Arr;
	return 0;
}