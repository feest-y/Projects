#include <iostream>
#include <ctime>
using namespace std;

void FillArray(int** const arr, const int ROWS, const int COLLS, const int min = 1, const int max = 99) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++) {
			arr[i][j] = rand() % (max - min) + min;
		}
	}
}

void PrintArray(int** const arr, const int ROWS, const int COLLS) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			printf("%2.d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\b");
}

int** TurnArrayLeft(int** arr, int& rows, int& colls)
{
	int a = rows;
	rows = colls;
	colls = a;

	int** NewArr = new int* [rows];
	for (int i = 0; i < rows; i++)
		NewArr[i] = new int[colls];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
		{
			NewArr[i][j] = arr[j][rows - i - 1];
			//cout << arr[j][rows - i - 1] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	
	for (int i = 0; i < colls; i++)
		delete[] arr[i];
	delete arr;

	return NewArr;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int rows, colls;
	cout << "rows > ";
	cin >> rows;
	cout << "colls > ";
	cin >> colls;

	int** Arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		Arr[i] = new int[colls];
	FillArray(Arr, rows, colls);
	printf("Original Array:\n");
	PrintArray(Arr, rows, colls);
	printf("\n");
	printf("\n");

	Arr = TurnArrayLeft(Arr, rows, colls);

	printf("Turned Array:\n");
	PrintArray(Arr, rows, colls);

	for (int i = 0; i < rows; i++)
		delete[] Arr[i];

	delete[] Arr;
	return 0;
}