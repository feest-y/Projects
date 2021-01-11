#pragma once
#include<iostream>
#include<chrono>
#include<cmath>
#include<ctime>
using namespace std;
void Standart() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
}

void FillArray(int* const arr, const int size, const int min = 1, const int max = 99) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}

void FillArray(int** const arr, const int ROWS, const int COLLS, const int min = 1, const int max = 99) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = rand() % (max - min) + min;
		}
	}
}
template <typename T>
void PrintArray(const T* const arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
	printf("\n");
}

void PrintArray(const int** const arr, const int ROWS, const int COLLS) {
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

template <typename T>
T AverageInArray(const T* const arr, const int size, const short first = 0, const int last = size) {
	T Sum = 0;

	for (int i = first; i < last; i++)
	{
		Sum += arr[i];
	}

	return Sum / (last - first);
}

template <typename T>
void FillArrayDirect(T* const arr, const int size) {

	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

template <typename T>
void FillArrayReverse(T* const arr, const int size) {

	for (int i = 0; i < size; i++)
	{
		arr[i] = size - i - 1;
	}
}

int InputSize() {
	setlocale(LC_ALL, "ru");
	int size = 0;
	cout << "Input amount of element in Array > ";
	cin >> size;
	return size;
}
//void push_inside(int*& arr, unsigned int& size, const int value, const unsigned int position){
//	int x = 0;
//	if (position > size)
//	{
//		x += position - size;
//	}
//	int* newArray = new int[size + 1 + x];
//
//	for (unsigned int i = 0; i < position; i++)
//	{
//		newArray[i] = arr[i];
//	}
//	newArray[position] = value;
//	for (unsigned int i = position; i < size; i++)
//	{
//		newArray[i + 1] = arr[i];
//	}
//	for (unsigned int i = size; i < position; i++)
//	{
//		newArray[i] = 0;
//	}
//	size = size + 1 + x;
//	delete[] arr;
//	arr = newArray;
//}

//void pop_inside(const int*& const arr, unsigned int& size, int position){
//	size--;
//	int* newArray = new int[size];
//	for (int i = 0; i < position; i++)
//	{
//		newArray[i] = arr[i];
//	}
//
//	for (unsigned int i = position; i < size; i++)
//	{
//		newArray[i] = arr[i + 1];
//	}
//
//	delete[] arr;
//	arr = newArray;
//	newArray = nullptr;
//}

void PushBack(int*& arr, int& size, const int value) {
	int* newArray = new int[size + 1];

	for (short i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;

	size++;

	delete[] arr;

	arr = newArray;
}

void TurnArrayLeft(int* const arr[], const int ROWS = 9, const int COLLS = 9) {
	int Buffer[9][9] = {};
	for (int i = 0; i < ROWS; i++)
	{

		for (int j = 0; j < COLLS; j++)
		{
			Buffer[i][j] = arr[j][ROWS - i - 1];
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

template <typename T>
void DeleteArray(T* arr) {
	delete[] arr;
}

template <typename T>
void DeleteArray(T** arr, const int rows) {
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}

template <typename T>
void Bin(T num = 0) {
	if (num != 0)
	{
		unsigned int size = 0, i = 0;
		int* Arr = new int[size];
		while (num)
		{
			push_inside(Arr, size, num % 2, i);
			num /= 2;
		}
		printf(" ( ");
		for (int i = size - 1; i >= 0; i--)
		{
			printf("%d", Arr[i]);
		}
		printf(" ) ");
		delete[] Arr;
	}
	else printf(" ( 0 ) ");
}

template <typename T>
void SwapWithPrevious(T* const arr, const int position) {
	T buff;
	buff = arr[position];
	arr[position] = arr[position - 1];
	arr[position - 1] = buff;
}

template <typename T>
double ShakerSort(T* const arr, const int size) {
	int leftMark = 1, rightMark = size - 1;

	auto start = chrono::high_resolution_clock::now();
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) SwapWithPrevious(arr, i);
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) SwapWithPrevious(arr, i);
		rightMark--;
		//cout << "\nИтерация: " << leftMark - 1; // просмотр количества итераций
	}
	chrono::duration <double> duration = chrono::high_resolution_clock::now() - start;
	return duration.count();
}

int CountDigits(int number) {

	int n = 1;

	while (((int)(number / 9)) > 0)
	{
		number /= 10;
		n++;
	}
	return n;
}

int RadixSort_VelichRazr(int num, int razr)
{
	while (razr > 1)
	{
		num /= 10;
		razr--;
	}
	return num % 10;
}

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
			int a = RadixSort_VelichRazr(arr[i], k);
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