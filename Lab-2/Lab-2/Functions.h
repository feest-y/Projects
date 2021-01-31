#pragma once
#include "Company.h"
#include "Debug.h"

void PrintS(Company All, int n = 10);
void SortS(Company All, int n = 10);

void PrintS(Company All, int n) {

	std::cout << "\n\n";
	printf("---------------------------------------------\n");
	printf("|      Сельскохозяйственные предприятия      |\n");
	printf("|--------------------------------------------|\n");
	printf("|  Название |  Вид  |Количество|   Площадь   |\n");
	printf("|           |       |работников|   земли (га)|\n");
	printf("|-----------|-------|----------|-------------|\n");

	for (short i = 0; i < n; i++)
	{
		A[i].PrintCompany();
	}

	printf("----------------------------------------------\n");

#ifdef DEBUG
	std::cout << __FILE__ << " > " << __FUNCTION__ << ": ";
	Debug();
#endif // DEBUG
}

void SortS(Company All, int n) {

	Company Buffer = A[0];
	for (int i = 0; i < n - 1; i++) {
		if (A[i].name > A[i + 1].name) {
			Buffer = A[i + 1];
			A[i + 1] = A[i];
			A[i] = Buffer;
			i = -1;
		}
	}

	/*int Arr[10] = { 1,424,4124,5,124,5,547,123,24,12 };
	int buff = Arr[0];
	for (int i = 0; i < 9; i++){
		if (Arr[i]>Arr[i+1]){
			buff = Arr[i + 1];
			Arr[i + 1] = Arr[i];
			Arr[i] = buff;
			i = 0;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << endl;
	}*/

#ifdef DEBUG
	std::cout << __FILE__ << " > " << __FUNCTION__ << ": ";
	Debug();
#endif // DEBUG
}