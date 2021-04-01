#include "..\..\Functions\Functions.h"


void TaskA(int* Arr, const int size, int& sumOfNegatives, int& amountOfNegatives) {
	amountOfNegatives = sumOfNegatives = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(Arr + i) < 0)
		{
			sumOfNegatives += *(Arr + i);
			amountOfNegatives++;
		}
	}
}

void TaskБ(int* Arr, const int size, int& sumOfNegatives, int& amountOfNegatives) {
	amountOfNegatives = sumOfNegatives = 0;
	int* Pointer = Arr;

	for (int i = 0; i < size; i++, Pointer++)
	{
		if (*Pointer < 0)
		{
			sumOfNegatives += *Pointer;
			amountOfNegatives++;
		}
	}
}

void TaskВ(int* Arr, const int size, int& sumOfNegatives, int& amountOfNegatives) {
	amountOfNegatives = sumOfNegatives = 0;

	for (int* Pointer = Arr; Pointer < Arr + size; Pointer++)
	{
		if (*Pointer < 0)
		{
			sumOfNegatives += *Pointer;
			amountOfNegatives++;
		}
	}
}

void TaskГ(int* Arr, const int size, int& sumOfNegatives, int& amountOfNegatives) {
	amountOfNegatives = sumOfNegatives = 0;

	int* Pointer[8];

	for (int i = 0; i < size; i++)
		Pointer[i] = &Arr[i];

	for (int i = 0; i < size; i++)
	{
		if (*Pointer[i] < 0)
		{
			sumOfNegatives += *Pointer[i];
			amountOfNegatives++;
		}
	}
}

void TaskД(int* Arr, const int size, int& sumOfNegatives, int& amountOfNegatives) {
	amountOfNegatives = sumOfNegatives = 0;

	int** MainPointer = new int*;
	int* Pointer = Arr;
	*MainPointer = Pointer;
	for (int i = 0; i < size; i++)
	{
		if (*(*MainPointer + i) < 0)
		{
			sumOfNegatives += *(*MainPointer + i);
			amountOfNegatives++;
		}
	}
}


int main()
{
	Standart();
	int size = 8, * Arr = new int[size];
	int sumOfNegatives = 0, AmountOfNegatives = 0;
	FillArray(Arr, size, -10, 10);
	PrintArray(Arr, size);

	TaskД(Arr, size, sumOfNegatives, AmountOfNegatives);

	printf("Sum Of Negatives > %d\nAmount Of Negatives > %d", sumOfNegatives, AmountOfNegatives);
}