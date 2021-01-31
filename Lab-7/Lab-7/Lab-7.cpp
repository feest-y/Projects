#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#define _CLS_
#define PRINT_TYPE
#include <conio.h>
#include <windows.h>
#include "Company.h"
#include "Functions.h"
#include "Debug.h"

int main()
{
	setlocale(LC_ALL, "ru");

tryAgain:
	system("cls");
	cout << "1. Ввод с экрана и запись в файл.\n";
	cout << "2. Ввод случайным образом и запись в файл.\n";
	cout << "3. Добавить запись в начало файла.\n";
	cout << "4. Добавить запись в конец файла.\n";
	cout << "5. Печать одной записи из файла по номеру.\n";
	cout << "6. Печать всех записей из файла.\n";
	cout << "7. Выход из программы.\n";

	int N = _getch();

#ifdef DEBUG
	cout << N << endl;
#endif 

	switch (N - 48)
	{
	case 1: {
#ifdef _CLS_ 
		system("cls");
#endif 
		Company A;
		A.SetCompany();
		A.CompanyToFile("Company.txt");
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 2: {
#ifdef _CLS_ 
		system("cls");
#endif 
		Company A;
		A.SetCompany(1);
		A.CompanyToFile("Company.txt");

		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 3: {
#ifdef _CLS_ 
		system("cls");
#endif 
		Company A;
		A.SetCompany();
		A.CompanyToFile("Company.txt", 1);
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 4: {
#ifdef _CLS_ 
		system("cls");
#endif 
		Company A;
		A.SetCompany();
		A.CompanyToFile("Company.txt", 2);
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 5: {
#ifdef _CLS_ 
		system("cls");
#endif 
		short n = 0;
		cout << "N > ";
		cin >> n;
		Company A;
		A.PrintFromFile("Company.txt", n);
		system("pause");
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 6: {
#ifdef _CLS_
		system("cls");
#endif 
		Company A;
		A.PrintFromFile("Company.txt");
		system("pause");
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 7: {
#ifdef _CLS_
		system("cls");
#endif 

		cout << "Done !\n";
		Sleep(250);
		break;
	}

	case -45: return 0;
	case 27 - 48: return 0;

	default:goto tryAgain;
	}
	return 0;
}
