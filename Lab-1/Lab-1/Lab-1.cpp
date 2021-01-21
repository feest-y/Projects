/********************************************************/
/*             Лабораторная  работа №1                  */
/*            Типы данных и ввод-вывод                  */
/*			   	      Вариант №16						*/
/*		    Солтус Андрей Евгениевич 320-В				*/
/********************************************************/
#include "../../Header/Header.h"
#include <String>

#define zxc printf("|")

struct Company
{
	string name = "N";
	char type = name[0];
	float area = 0;
	int workers = 0;

	void SetCompany() {
		name[0] = rand() % (122 - 65) + 65;
		//cout << "Company name > ";
		//cin >> name;
		//cout << "Company type > ";
		//cin >> type;
		//cout << "Company workers > ";
		//cin >> workers;
		//cout << "Company area > ";
		//cin >> area;
	}

	void PrintCompany() {
		zxc;
		cout.width(11);
		cout << name;
		zxc;
		cout.width(7);
		cout << type;
		zxc;
		cout.width(10);
		cout << workers;
		zxc;
		cout.width(13);
		cout << area;
		zxc;
		printf("\n");
		cout.width(1);
	}
}A[10];

void PrintS(Company All, int n = 10) {

	cout << "\n\n";
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
}

//
//int sort() {
//	int A[10] = {};
//	int col = 0;
//	int temp = 0;
//	for (int i = 0; i < col; i++)
//		for (int j = 0; i < col; j++) {
//			if (A[j] > A[j + 1]) {
//				temp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = A[j];
//			}
//		}
//	return 0;
//}
//
//void SortSs(Company All) {
//	Company Buffer = A[0];
//	short n = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		Buffer = A[i];
//		for (int j = i; j < 10; j++) {
//			if (Buffer.name[0] > A[j].name[0])
//			{
//				n = j;
//				Buffer = A[j];
//			}
//			//Buffer.PrintCompany();
//			A[n] = A[i];
//			A[i] = Buffer;
//		}
//	}
//
//}

void SortS(Company All) {
	Company temp = A[0];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (A[j].name > A[j + 1].name) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = A[j];
			}
		}
}

int main() {
	Standart();
	Company All;
	short n = 10;

	for (short i = 0; i < n; i++)
	{
		if (i != 0) cout << "\n";
		cout << "Company " << i + 1 << ":\n";
		A[i].SetCompany();
	}

	PrintS(All);

	SortS(All);

	PrintS(All);
	r0;
}