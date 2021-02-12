#include <iostream>
#include <ctime>
using namespace std;

void FillArray(int* const arr, const int ROWS, const int COLLS, const int min = 1, const int max = 99) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
			*((arr + j) + (i * COLLS)) = rand() % (max - min) + min;
	}
}

void PrintArray(int* const arr, const int ROWS, const int COLLS) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			printf("%2.d ", *((arr + j) + (i * COLLS)));
		}
		printf("\n");
	}
	printf("\b");
}

int* TurnArrayLeft(int* arr, int& rows, int& colls)
{
	int a = rows;
	rows = colls;
	colls = a;
	int x = 0;
	int* NewArr = new int[rows * colls]{};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
		{
			x = *(arr + (j * colls + (rows - 1 - i)));
			*((NewArr + j) + (i * colls)) = *((arr - ((colls - rows)*j))+(j * colls + (rows - 1 - i)));//arr[j][rows - i - 1
		}
	}

	delete arr;
	return NewArr;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int rows = 9, colls = 5;
	cout << "rows > ";
	cin >> rows;
	cout << "colls > ";
	cin >> colls;

	int* Arr = new int[rows * colls];

	FillArray(Arr, rows, colls);
	printf("Original Array:\n");
	PrintArray(Arr, rows, colls);
	printf("\n");
	printf("\n");

	Arr = TurnArrayLeft(Arr, rows, colls);

	printf("Turned Array:\n");
	PrintArray(Arr, rows, colls);

	delete[] Arr;
	return 0;
}