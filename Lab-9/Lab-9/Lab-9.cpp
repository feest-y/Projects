﻿#define _CRT_SECURE_NO_WARNINGS
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
	system("cls");
	cout << "1. Создание списка.\n";
	cout << "2. Печать списка с начала.\n";
	cout << "3. Поиск по количеству сотрудников.\n";
	cout << "4. Поиск по критерию с начала списка.\n";
	cout << "5. Поиск по критерию с конца списка.\n";
	cout << "6. Добавление элемента (в любое заданное место).\n";
	cout << "7. Удаление  любого элемента.\n";
	cout << "8. Сортировка.\n";
	cout << "9. Запись нового списка в файл.\n";
	cout << "10. Создание нового списка файла.\n";
	cout << "0. Выход из программы.\n";
	

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
		
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 3: {
#ifdef _CLS_ 
		system("cls");
#endif 
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 4: {
#ifdef _CLS_ 
		system("cls");
#endif 
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 5: {
#ifdef _CLS_ 
		system("cls");
#endif 
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 6: {
#ifdef _CLS_
		system("cls");
#endif 
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
		
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 9: {
#ifdef _CLS_
		system("cls");
#endif 
		cout << "Done !";
		Sleep(250);
		break;
	}
	case 0: {
#ifdef _CLS_
		system("cls");
#endif 
		cout << "Done !";
		Sleep(250);
		break;
	}

	case -45: return 0;
	case 27 - 48: return 0;

	default:goto tryAgain;
	}

	r0;
}
