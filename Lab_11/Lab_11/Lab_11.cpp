#include "..\..\РГЗ\РГЗ\Header.h"

int Di(const int* const Arr, const int size, int position = 0, int counter = 0) {
	if (Arr[position] > position) counter++;
	position++;

	if (position < size)
	{
		return Di(Arr, size, position,counter);
	}

	return counter;
}

int main()
{
	Standart();
	int size = 10;
	int* Arr = new int[size];
	FillArray(Arr, size, 0, 10);
	cout << Di(Arr, size);
	DeleteArray(Arr);
}
