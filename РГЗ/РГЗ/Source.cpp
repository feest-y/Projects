#include "Header.h"

int velich_razr(int num, int razr)
{
	while (razr > 1)
	{
		num /= 10;
		razr--;
	}
	return num % 10;
}

//void sort_razr(int* arr, int razr, const int size)
//{
//	int** Buff = new int* [size]; for (int i = 0; i < size; i++) Buff[i] = new int[size];
//	int* BuffCol = new int[size];
//	int temp = 0;
//
//	for (int i = 0; i < size; i++) {
//		BuffCol[i] = 0;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		int a = velich_razr(arr[i], razr);
//		Buff[BuffCol[a]][a] = arr[i];
//		BuffCol[a]++;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < BuffCol[i]; j++)
//		{
//			arr[temp] = Buff[j][i];
//			temp++;
//		}
//	}
//
//	DeleteArray(Buff, size);
//	DeleteArray(BuffCol);
//}

double RadixSort(int* arr, int size) {
	int razr = 0;
	int** Buff = new int* [size]; for (int i = 0; i < size; i++) Buff[i] = new int[size];
	int* BuffCol = new int[size];
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		if (CountDigits(arr[i]) > razr)
		{
			razr = CountDigits(arr[i]);
		}
	}
	auto start = chrono::high_resolution_clock::now();
	for (int k = 1; k <= razr; k++) {
	//	sort_razr(arr, i, size);
		temp = 0;
		for (int i = 0; i < size; i++) {
			BuffCol[i] = 0;
		}

		for (int i = 0; i < size; i++)
		{
			int a = velich_razr(arr[i], k);
			Buff[BuffCol[a]][a] = arr[i];
			BuffCol[a]++;
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < BuffCol[i]; j++)
			{
				arr[temp] = Buff[j][i];
				temp++;
			}
		}
	}
	chrono::duration <double> duration = chrono::high_resolution_clock::now() - start;
	DeleteArray(Buff, size);
	DeleteArray(BuffCol);
	return duration.count();
}
int main()
{
	Standart();
	int size = InputSize(), razr = 0,max;
	int* Arr = new int[size];
	cout << "Input max value in array > ";
	cin >> max;
	FillArray(Arr, size,0,max);
	//PrintArray(Arr, size);
	printf("RadixSort  - Затраченое время > %.8lfs", RadixSort(Arr, size));
	//PrintArray(Arr, size);
	FillArray(Arr, size,0, max);
	//PrintArray(Arr, size);
	printf("ShakerSort - Затраченое время > %.8lfs", ShakerSort(Arr, size));
	//PrintArray(Arr, size);
	DeleteArray(Arr);
	return 0;
}