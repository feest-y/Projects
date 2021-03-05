#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

void FillArray(int* const arr, const int size, const int min = 0, const int max = 9) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min) + min;
	}
}

int main()
{
	FILE* file;
	int Arr[10], a[10];

	FillArray(a, 10);


	if ((file = fopen("test", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	if (fwrite(&a, sizeof(int), 1, file) != 10) {
		if (feof(file)) printf("End of file.");
		else printf("Read error.");
	}
	fclose(file);

	if ((file = fopen("test", "r")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	if (fread(Arr, sizeof(int), 10, file) != 10) {
		if (feof(file)) printf("End of file.");
		else printf("Read error.");
	}

	fclose(file);
	return 0;
}