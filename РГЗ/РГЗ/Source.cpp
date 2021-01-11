#include<iostream>
#include<chrono>
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

void FillArray(int* const arr, const int size, const int min = 1, const int max = 99) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
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
int main()
{
	setlocale(LC_ALL, "ru");
	int size_f = 500;
	int step = 500;
	int stepAmount = 10;
	int max = 1000;
	double RadixTime[100] = {}, ShakerTime[100] = {}, RadixAvgTime[9] = {}, ShakerAvgTime[9] = {};

	int size_ofR = sizeof(RadixTime) / sizeof(RadixTime[0]);
	int size_ofS = sizeof(RadixTime) / sizeof(RadixTime[0]);

	//cout << "Input max value in array > ";
	//cin >> max;
	max = 100;

	//cout << "Input first size > ";
	//cin >> size_f;
	size_f = 500;
	int size = size_f;

	//cout << "Input step > ";
	//cin >> step;
	step = 500;
	//cout << "Input amount of steps > ";
	//cin >> stepAmount;
	stepAmount = 8;
	cout.setf(ios::fixed);
	cout.precision(8);

	cout << "Упорядоченный массив > \n";
	for (short n = 0; n < stepAmount; n++)
	{
		int* Arr = new int[size];
		for (short i = 0; i < 100; i++)
		{
			FillArrayDirect(Arr, size);
			RadixTime[i] = RadixSort(Arr, size);
			FillArrayDirect(Arr, size);
			ShakerTime[i] = ShakerSort(Arr, size);
		}
		ShakerSort(RadixTime, size_ofR);
		ShakerSort(ShakerTime, size_ofS);
		RadixAvgTime[n] = AverageInArray(RadixTime, size_ofR, 10, 90);
		ShakerAvgTime[n] = AverageInArray(ShakerTime, size_ofS, 10, 90);

		cout << "RadixAvgTime  (" << size << ") > ";
		cout << RadixAvgTime[n] << "\n";
		cout << "ShakerAvgTime (" << size << ") > ";
		cout << ShakerAvgTime[n] << "\n";

		size += step;
		DeleteArray(Arr);
	}

	size = size_f;
	cout << "\nМассив, упорядоченный в обратном порядке > \n";
	for (short n = 0; n < stepAmount; n++)
	{
		int* Arr = new int[size];
		for (short i = 0; i < 100; i++)
		{
			FillArrayReverse(Arr, size);
			RadixTime[i] = RadixSort(Arr, size);
			FillArrayReverse(Arr, size);
			ShakerTime[i] = ShakerSort(Arr, size);
		}
		ShakerSort(RadixTime, size_ofR);
		ShakerSort(ShakerTime, size_ofS);
		RadixAvgTime[n] = AverageInArray(RadixTime, size_ofR, 10, 90);
		ShakerAvgTime[n] = AverageInArray(ShakerTime, size_ofS, 10, 90);
		cout << "RadixAvgTime  (" << size << ") > ";
		cout << RadixAvgTime[n] << "\n";
		cout << "ShakerAvgTime (" << size << ") > ";
		cout << ShakerAvgTime[n] << "\n";
		size += step;
		DeleteArray(Arr);
	}

	size = size_f;
	cout << "\nНеупорядоченный массив > \n";
	for (short n = 0; n < stepAmount; n++)
	{
		int* Arr = new int[size];
		for (short i = 0; i < 100; i++)
		{
			FillArray(Arr, size);
			RadixTime[i] = RadixSort(Arr, size);
			FillArray(Arr, size);
			ShakerTime[i] = ShakerSort(Arr, size);
		}
		ShakerSort(RadixTime, size_ofR);
		ShakerSort(ShakerTime, size_ofS);
		RadixAvgTime[n] = AverageInArray(RadixTime, size_ofR, 10, 90);
		ShakerAvgTime[n] = AverageInArray(ShakerTime, size_ofS, 10, 90);
		cout << "RadixAvgTime  (" << size << ") > ";
		cout << RadixAvgTime[n] << "\n";
		cout << "ShakerAvgTime (" << size << ") > ";
		cout << ShakerAvgTime[n] << "\n";
		size += step;
		DeleteArray(Arr);
	}

	return 0;
}