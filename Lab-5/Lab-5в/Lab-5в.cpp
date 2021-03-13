#include <iostream>
using namespace std;

template <typename T>
void DeleteArray(T* arr) {
	delete[] arr;
}

template <typename T>
void DeleteArray(T** arr, const int rows) {
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}

void SwapWithPrevious(int* arr, int position) {
	int buff;
	buff = arr[position];
	arr[position] = arr[position - 1];
	arr[position - 1] = buff;
}

void ShakerSort(int* arr, int size) {
	int leftMark = 1, rightMark = size - 1;

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

void RadixSort(int* arr, int size) {

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
	DeleteArray(Buff, size);
	DeleteArray(BuffCol);
}

void DescendingSort(int* arr, int size) {
	ShakerSort(arr, size);
	int* Buff = new int[size];
	for (int i = 0; i < size; i++)
	{
		Buff[i] = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = Buff[size - i - 1];
	}
}

void FillArray(int* const arr, const int size, const int min = 1, const int max = 99) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min) + min;
	}
}

template <typename T>
void PrintArray(const T* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\n";
	}
	printf("\n");
}

void Sort(int* arr, int size, void(*Function)(int* arr, int size)) {
	Function(arr, size);
}



int main()
{
	srand(time(0));
	int size = 10;
	int* Arr = new int[size] {};
	FillArray(Arr, size);
	PrintArray(Arr, size);

	Sort(Arr, size, ShakerSort);
	cout << "Sorted >\n";
	PrintArray(Arr, size);
	return 0;
}