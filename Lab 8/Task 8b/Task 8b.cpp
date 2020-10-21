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
void push_inside(int*& arr, int& size, const int value, int position)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
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
	srand(time(NULL));
	int size = 10;
	int* Arr = new int[size];
	FillArray(Arr, size);
	PrintArray(Arr, size);
	delete[] Arr;
}