#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void PrintArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}
}
void push_back(int*& arr, int& size, const int value)
{
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

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size = 0,
		i = 1,
		* Arr = new int[size],
		value = 0,
		number = 0;
	printf("Введите число > ");
	scanf_s("%d", &number);
	while (number != 0)
	{
		value = number % (int)pow(10, i);
		number -= value;
		value = value / (int)pow(10, i - 1);
		push_back(Arr, size, value);
		i++;
	}
	i--;
	value = 0;
	for (short j = 0; j < i; j++)
	{
		value += Arr[j];
	}
	PrintArray(Arr, size);

	printf("\nSum > %d", value);

	printf("\nКоличество цифр > %d", i);
	delete[] Arr;
}