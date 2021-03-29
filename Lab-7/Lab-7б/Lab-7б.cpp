#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

template <typename T>
void PrintArray(const T* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << "\n";
	}
	printf("\n");
}

void FillArray(int* const arr, const int size, const int min = 0, const int max = 9) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min) + min;
	}
}

void IntToChar(char* Destination, int* Source, const int size = 10) {
	for (int i = 0; i < size; i++)
		*(Destination + i) = (*(Source + i) + 48);
}

void CharToInt(char* Source, int* Destination, const int size = 10) {
	for (int i = 0; i < size; i++)
		*(Destination + i) = (*(Source + i) - 48);
}
int main()
{
	srand(time(0));
	FILE* file;
	const int size = 10;
	int Arr[10], Brr[size];
	char* Buffer = new char[size];
	FillArray(Arr, size);

	IntToChar(Buffer, Arr, size);


	if ((file = fopen("test.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	fwrite(Buffer, 1, size, file);
	fclose(file);

	if ((file = fopen("test.txt", "r")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	delete[] Buffer;
	Buffer = new char[size];
	
	fread(Buffer, 1, size, file);
	
	CharToInt(Buffer, Brr);

	PrintArray(Brr, size);
	return 0;
}