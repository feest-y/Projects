#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#define _CLS_
#include <windows.h>
#include <iostream>

using namespace std;

int CharToInt(char a) {
	int x = a;

	return x;
}
void FillArray(int* const arr, const int size, const int min = 0, const int max = 9) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min) + min;
	}
}

int main()
{
	srand(time(0));
	char filename[255]{};
	char line[255]{};
	int Arr[10];
	int Brr[10]{};
	strcpy(filename, "file1.txt");
	remove(filename);

	FillArray(Arr, 10);

	FILE* file = fopen(filename, "a");

	for (int i = 0; i < 10; i++)
		fprintf(file, "%d ", Arr[i]);
	fclose(file);

	strcpy(filename, "file2.txt");
	file = fopen(filename, "w");

	cout << "Brr: ";
	int j = 0;
	for (int i = 0; i < 255; i++)
	{
		if (i >= 48 && i <= 57)
		{
			Arr[j] += CharToInt(line[i]);
			cout << Arr[j] << " ";
			fprintf(file, "%d ", Arr[j]);
			j++;
		}
	}
	fclose(file);
	cout << "\nx:   ";

	char x;
	file = fopen(filename, "r");
	for (int i = 0; i < 25; i++)
	{
		fscanf(file, "%c", &x);
		cout << x;
	}

	return 0;
}
