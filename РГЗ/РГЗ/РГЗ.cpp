#include "Header.h"

int main()
{
	Standart();

	int size = 0;
	double time = 0;
	cout << "Размер массива: ";
	cin >> size;
	int* Arr = new int[size];

	for (int k = 0; k < size; k++)
	{
		Arr[k] = size - k; // запись значений по убыванию
	}
	PrintArray(Arr, size);

	time = ShakerSort(Arr, size); // сортировка

	cout << "\nМассив после сортировки:\n";

	PrintArray(Arr, size);
	printf("\nВремя на сортировку: %.8lf", time);

	DeleteArray(Arr);
	return 0;
}