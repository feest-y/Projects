#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#define _CLS_
#include <conio.h>
#include <windows.h>
#include "Company.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	short notes = 0;
	char* filename = new char[255]{};
	strcpy(filename, "Company.txt");
	remove(filename);
	remove(1 + filename);
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
	switch (N - 48)
	{
	case 1: {
#ifdef _CLS_ 
		system("cls");
#endif 
		Company A;
		cout << "Количество записей > "; cin >> N;
		for (int i = 1; i <= N; i++)
		{
			printf("\n%d: \n", i);
			A.SetCompany();
			A.CompanyToFile(filename, notes, 2);
		}
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
		A.CompanyToFile(filename, notes, 2);
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
		A.CompanyToFile(filename, notes, 1);
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
		A.CompanyToFile(filename, notes);
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 5: {
#ifdef _CLS_ 
		system("cls");
#endif 
		short n = 0;
		do 
		{
			system("cls");
			cout << "N > ";
			cin >> n;
		} 		while (n > notes || n < 0);
		Company A;
		A.PrintFromFile(filename, notes, n);
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
		for (int i = 1; i <= notes; i++)
		{
			A.PrintFromFile(filename, notes, i);
		}
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
	delete[] filename;
	return 0;
}
