/********************************************************/
/*             Лабораторная  работа №1                  */
/*            Типы данных и ввод-вывод                  */
/*			   	      Вариант №16						*/
/*		    Солтус Андрей Евгениевич 320-В				*/
/********************************************************/

#include <iostream>
#include <String>

using namespace std;

#define zxc printf("|")
//#define DEBUG
#define PRINT_TYPE
#define _CRT_SECURE_NO_WARNINGS

struct Company
{
	string name = "N";
	char type = name[0];
	float area = 0;
	int workers = 0;

	void SetCompany(bool x = 0);
	void PrintCompany();
}A[10];

void Company::SetCompany(bool x) {
	if (x)
	{
		name[0] = rand() % (122 - 65) + 65;
		type = rand() % (122 - 65) + 65;
		workers = rand() % 12700;
		area = (float)(rand() % 1270);
	}
	else {
		cout << "Company name > ";
		cin >> name;
		cout << "Company type > ";
		cin >> type;
		cout << "Company workers > ";
		cin >> workers;
		cout << "Company area > ";
		cin >> area;
	}

}

void Company::PrintCompany() {
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

void SortS(Company All, int n = 10) {

	Company Buffer = A[0];
	for (int i = 0; i < n - 1; i++) {
		if (A[i].name > A[i + 1].name) {
			Buffer = A[i + 1];
			A[i + 1] = A[i];
			A[i] = Buffer;
			i = 0;
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
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	Company All;
	short n = 10;

	for (short i = 0; i < n; i++)
	{
#ifdef PRINT_TYPE
		A[i].SetCompany(true);
#else
		if (i != 0)  cout << "\n";
		cout << "Company " << i + 1 << ":\n";
		A[i].SetCompany(false);
#endif 

	}

	PrintS(All);

	SortS(All);

	PrintS(All);

	return 0;
	}
