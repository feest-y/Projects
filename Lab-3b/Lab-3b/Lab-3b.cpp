#include "..\..\Header\Header.h"

int main()
{
	Standart();
	int size = InputSize(), n = 0, p = 0, z = 0;
	int* Arr = new int[size] {};
	//PrintArray(Arr, size);
	FillArray(Arr, size, -10, 10);
//	PrintArray(Arr, size);
	n = CountNegativeDigits(Arr, size);
	p = CountPossitiveDigits(Arr, size);
	z = size - n - p;

	DescendingSort(Arr, size);

	PrintArray(Arr, size);

	int* Nrr = new int[n] {};
	for (int i = 0; i < n; i++)
	{
		Nrr[i] = Arr[size - n + i];
	}

	int* Prr = new int[p] {};
	for (int i = 0; i < p; i++)
	{
		Prr[i] = Arr[i];
	}

	int* Zrr = new int[z] {};
	for (int i = 0; i < z; i++)
	{
		Zrr[i] = Arr[p+i];
	}

	PrintArray(Prr,p);
	PrintArray(Zrr,z);
	PrintArray(Nrr,n);

	DeleteArray(Arr);
	DeleteArray(Zrr);
	DeleteArray(Nrr);
	r0;
}
