#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


int StrToInt(char* b) {
	int x = 0, counter = 0;
	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] >= 48 && b[i] <= 57 && counter == 0)
		{
			x *= 10;
			x += (b[i] - 48);
		}
	}
	return x;
}

void FillFiles(FILE* file, FILE* file2) {
	char* A = new char;
	short counter;
	for (int i = 0; i < 20; i++)
	{
		counter = rand() % 3 + 1;

		for (int j = 0; j < counter; j++)
		{
			*A = rand() % 9 + 48 + 1;
			fwrite(A, 1, 1, file);
			fwrite(A, 1, 1, file2);
		}
		for (int j = 0; j <= 3 - counter; j++)
		{
			fseek(file, 1, SEEK_CUR);
			fseek(file2, 1, SEEK_CUR);
		}

	}
	delete A;
}


int CheckFile(FILE* file) {
	char* A = new char[4]{};
	int min = INT32_MAX;
	int counter;
	for (int i = 0; i < 20; i++)
	{
		fread(A, 1, 3, file);
		fseek(file, 1, SEEK_CUR);
		if (StrToInt(A) < min)
		{
			min = StrToInt(A);
			counter = i;
		}
	}
	delete[] A;
	return counter * 4;
}

int Sum(FILE* file) {
	int sum = 0, num = 0;

	char* A = new char[4]{};

	for (int i = 0; i <= 20; i++)
	{
		fread(A, 1, 3, file);
		fseek(file, 1, SEEK_CUR);
		num = StrToInt(A);

		if (num == 2 || num == 5 || num == 9)
			sum += num;
	}

	return sum;
}
int main()
{
	srand(time(0));
	FILE* file, * buff;

	if ((file = fopen("file.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	if ((buff = fopen("buff.txt", "w")) == NULL) {
		printf("Cannot open buff file.\n");
		exit(1);
	}

	FillFiles(file, buff);
	fclose(buff);


	if ((buff = fopen("file.txt", "r")) == NULL) {
		printf("Cannot open buff file.\n");
		exit(1);
	}

	int position = CheckFile(buff);
	fclose(buff);


	fseek(file, position, SEEK_SET);
	fprintf(file, "999");
	fclose(file);

	if ((file = fopen("file.txt", "r")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	std::cout << Sum(file);

	fclose(file);
	//delete file;
	//delete buff;
	return 0;
}