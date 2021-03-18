#define _CRT_SECURE_NO_WARNINGS
#define _CLS_
#include "..\..\Header\Header.h"
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
	cout << "2. Печать списка.\n";
	cout << "3. Поиск по количеству сотрудников.\n";
	cout << "4. Добавление элемента (в любое заданное место).\n";
	cout << "5. Удаление элемента по номеру.\n";
	cout << "6. Сортировка.\n";
	cout << "7. Запись нового списка в файл.\n";
	cout << "8. Создание нового списка из файла.\n";
	cout << "9. Выход из программы.\n";


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
		PrintList(head);
		_getch();
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 3: {
#ifdef _CLS_ 
		system("cls");
#endif 
		cout << "Workers criterion > ";
		cin >> N;
		if (!PrintCriterion(head, N))
			cout << "head = nullptr !\n";
		system("pause");
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 4: {
#ifdef _CLS_ 
		system("cls");
#endif 
		cout << "Position > ";
		cin >> N;
		AddInList(N);
		//_getch();
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 5: {
#ifdef _CLS_ 
		system("cls");
#endif 
		cout << "Position > ";
		cin >> N;
		DeleteInList(N);
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 6: {
#ifdef _CLS_
		system("cls");
#endif 
		SortList();
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 7: {
#ifdef _CLS_
		system("cls");
#endif 
		remove(filename);
		ListToFile(head, filename);
		cout << "Done !\n";
		Sleep(250);
		goto tryAgain;
	}
	case 8: {
#ifdef _CLS_
		system("cls");
#endif 
		head = CreateFromFile(head, filename, ListElements);
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

	case -45: return 0;
	case 27 - 48: return 0;

	default:goto tryAgain;
	}

	r0;
}
