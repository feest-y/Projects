#include <iostream>
#include <ctime>

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void PrintArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void push_inside(int*& arr, unsigned int& size, const int value, const int position)
{
	int x = 0;
	if (position > size)
	{
		x += position - size;
	}
	int* newArray = new int[size + 1 + x];

	for (int i = 0; i < position; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[position] = value;
	for (int i = position; i < size; i++)
	{
		newArray[i + 1] = arr[i];
	}
	for (int i = size; i < position; i++)
	{
		newArray[i] = 0;
	}
	size = size + 1 + x;
	delete[] arr;
	arr = newArray;
}
void pop_inside(int*& arr, unsigned int& size, int position)
{
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < position; i++)
	{
		newArray[i] = arr[i];
	}

	for (int i = position; i < size; i++)
	{
		newArray[i] = arr[i + 1];
	}

	delete[] arr;
	arr = newArray;
	newArray = nullptr;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	unsigned int position = 0, size = 10, n = 0, m = 0;
	int value = 0;
	int* Arr = new int[size];
	FillArray(Arr, size);
	PrintArray(Arr, size);

	printf("Сколько чисел вы хотите вставить > ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("value > ");
		scanf_s("%d", &value);
		printf("position > ");
		scanf_s("%d", &position);

		while (position > size)
		{
			printf("Invalid position.\n");
			printf("position > ");
			scanf_s("%d", &position);
		}
		push_inside(Arr, size, value, position);
		PrintArray(Arr, size);
	}
	printf("Сколько чисел вы хотите удалить > ");
	scanf_s("%d", &n);
	while (n > size)
	{
		printf("Invalid amount.\n");
		printf("Сколько чисел вы хотите удалить > ");
		scanf_s("%d", &n);
	}
	for (int i = 0; i < n; i++)
	{
		printf("position > ");
		scanf_s("%d", &position);
		while (position >= size)
		{
			printf("Invalid position.\n");
			printf("position > ");
			scanf_s("%d", &position);
		}
		pop_inside(Arr, size, position);
		PrintArray(Arr, size);
	}
	delete[] Arr;
}