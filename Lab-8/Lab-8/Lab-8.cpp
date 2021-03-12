#define _CRT_SECURE_NO_WARNINGS
#include "..\..\Header\Header.h"
#include <conio.h>
#include <windows.h>
#include "Company.h"

int main()
{
	Standart();
	char* filename = new char[255]{};
	strcpy(filename, "Company.txt");
	remove(filename);
	remove(1 + filename);
tryAgain:
	system("cls");
	cout << "1. Создание списка.\n";
	cout << "2. Печать списка.\n";
	cout << "3. Поиск по критерию (*критерий*).\n";
	cout << "4. Добавление элемента (в любое заданное место).\n";
	cout << "5. Удаление элемента по номеру.\n";
	cout << "6. Сортировка.\n";
	cout << "7. Запись нового списка в файл.\n";
	cout << "8. Печать нового списка из файла.\n";
	cout << "9. Выход из программы.\n";


	int N = _getch();
	switch (N - 48)
	{
	case 1: {
#ifdef _CLS_ 
		system("cls");
#endif 

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

		cout << "Done !\n";
		Sleep(250);
		break;
}

	case -45: return 0;
	case 27 - 48: return 0;

	default:goto tryAgain;
	}

	delete[] filename;
	r0;
}
