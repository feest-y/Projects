#include "..\..\Header\Header.h"
using namespace std;

int Sum(int* Arr, const int size = 5) {
	int x = 0;

	for (int i = 0; i < size; i++)
	{
		if (Arr[i] >= 0)
			x += Arr[i];
	}

	return x;
}

int Mul(int* Arr, const int size = 5) {
	int x = 1;

	for (int i = 0; i < size; i++)
	{
		if (Arr[i] < 0)
			x *= Arr[i];
	}

	return x;
}

int main()
{
	Standart();
	int size = 5;
	int* Arr = new int[size] {};
	int(*Pointer)(int*, const int);

	FillArray(Arr, size, -10, 10);
	PrintArray(Arr, size);
	Pointer = Sum;
	cout << "\nSum >" << Pointer(Arr, size);


	Pointer = Mul;
	cout << "\nMul >" << Pointer(Arr, size) << "\n";
}