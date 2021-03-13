#include "..\..\Header\Header.h"

int* Sum(int** Arr, int* MinColls, int* MaxRows, int* SumGD, int* MulPD, const int rows = 9, const int colls = 9) {
	int* result = new int[2];
	int min = _I32_MAX;
	int max = _I32_MIN;



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
	int* SumGD = new int, * MulPD = new int;

	*SumGD = 0;
	*MulPD = 1;

	result = Sum(Arr, MinInColls, MaxInrows, SumGD, MulPD, rows, colls);
	printf("Sum > %d\nMul > %d", result[0], result[1]);

	delete SumGD;
	delete MulPD;
	SumGD = nullptr;
	MulPD = nullptr;
	delete[] result;
	for (int i = 0; i < rows; i++)
		delete[] Arr[i];
	delete[] Arr;
	Arr = nullptr;
	r0;
}