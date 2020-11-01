#include <iostream>
#include <time.h>
#include <math.h>
void PrintArray(const int* const Arr, const int size = 100)
{
	for (int i = 0; i < size; i++)
	{
		printf("Arr[%d] = %d\n", i, Arr[i]);
	}
	printf("\n");
}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	const int n = 100;
	int Arr[n], a = 0;

	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100 - 50;
	}
	PrintArray(Arr);
	a = Arr[0];
		for (int i = 0; i < n; i++)
	{
		if (Arr[i] < a)
		{
			a = Arr[i];
			if (a == -50)
			{
				i = 100;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] > 0)
		{
			Arr[i] = abs(a);
		}
	}
	PrintArray(Arr);
}