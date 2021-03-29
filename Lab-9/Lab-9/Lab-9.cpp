#define _CRT_SECURE_NO_WARNINGS
#define _CLS_
#include "..\..\Functions\Functions.h"
#include "List.h"
#include <conio.h>
#include <windows.h>

int main()
{
	Standart();
	char filename[10]{};
	strcpy(filename, "List.txt");
tryAgain:
	{
		system("cls");
		cout << "1. Создание списка.\n";
		cout << "2. Печать списка с начала.\n";
		cout << "3. Печать списка с конца.\n";
		cout << "4. Поиск по количеству сотрудников с начала списка.\n";
		cout << "5. Поиск по количеству сотрудников с конца списка.\n";
		cout << "6. Добавление элемента (в любое заданное место).\n";
		cout << "7. Удаление  любого элемента.\n";
		cout << "8. Сортировка.\n";
		cout << "9. Запись нового списка в файл.\n";
		cout << "0. Создание нового списка файла.\n";
		cout << "<ESC> Выход из программы <ESC>\n";
	}


	int N = _getch();
	switch (N - 48)
	{
	case 1: {
#ifdef _CLS_ 
		system("cls");
#endif 

		cout << "Количество строк > "; cin >> N;
		head = Create(head, N);
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 2: {
#ifdef _CLS_ 
		system("cls");
#endif 
		if (!PrintList(head))
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-Empty-_-_-_-_-_-_-_-_-_-_-_-_-\n";
		system("pause");

		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 3: {
#ifdef _CLS_ 
		system("cls");
#endif 
		if (!PrintList(tail))
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-Empty-_-_-_-_-_-_-_-_-_-_-_-_-\n";
		system("pause");
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 4: {
#ifdef _CLS_ 
		system("cls");
#endif 

		N = InputSize("workers > ");
		if (!PrintCriterion(head, N))
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-Empty-_-_-_-_-_-_-_-_-_-_-_-_-\n";
		system("pause");

		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 5: {
#ifdef _CLS_ 
		system("cls");
#endif 

		N = InputSize("workers > ");
		if (!PrintCriterion(tail, N))
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-Empty-_-_-_-_-_-_-_-_-_-_-_-_-\n";
		system("pause");

		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 6: {
#ifdef _CLS_
		system("cls");
#endif 
		N = InputSize("position > ");
		AddInList(N);
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
		goto tryAgain;
	}
	case 8: {
#ifdef _CLS_
		system("cls");
#endif 
		cout << "Not yet!\n";
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 9: {
#ifdef _CLS_
		system("cls");
#endif 
		
		remove(filename);
		ListToFile(head, filename);
		cout << "Done !";
		Sleep(250);
	}
	case 0: {
#ifdef _CLS_
		system("cls");
#endif 
		cout << "Not yet!\n";

		cout << "Done !";
		Sleep(250);
	}

	case -45: return 0;
	case 27 - 48: return 0;

	default:goto tryAgain;
	}

	r0;
}
