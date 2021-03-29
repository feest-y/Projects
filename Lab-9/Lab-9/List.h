#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _LINE_ printf("-----------------------------------------------\n")
#include "Company.h"
void PrintHead() {/*
	char line[48]{};
	for (int i = 0; i < sizeof(line); i++)
		line[i] = '|';
	printf("%s", line);*/
	_LINE_;
	printf("|      Сельскохозяйственные предприятия       |\n");
	_LINE_;
	printf("|  Название  |  Вид  |Количество|   Площадь   |\n");
	printf("|            |       |работников|   земли (га)|\n");
	printf("|------------|-------|----------|-------------|\n");

}

struct List
{
	Company data;
	List* next = nullptr;
	List* prev = nullptr;
};

List* head = nullptr; // адрес головы списка
short ListElements = 0;
List* Create(List* head, short n = 1) //функция создания списка (возвращает адрес его головы)
{
	if (n <= 0)
	{
		cout << "Wrong amount of elements !\n";
		return head;
	}

	if (head != nullptr)
		free(head);

	List* p, * pred;
	head = p = pred = (List*)malloc(sizeof(List));
	head->data.SetCompany(true);

	for (short i = 1; i < n; i++) {
		p = (List*)malloc(sizeof(List));
		p->data.SetCompany(1);

		pred->next = p; //ссылка из предыдущей записи на текущую
		pred = p;	// сохранение адреса текущей записи в поле предыдущей
					// текущая запись становится предыдущей
	}

	ListElements = n;
	p->next = nullptr;
	return head;
}

List* CreateFromFile(char* filename, int elements = ListElements) {

	elements = InputSize("Amount of elements > ");

	if (head != nullptr)
		free(head);

	List* p, * pred;
	head = p = pred = (List*)malloc(sizeof(List));
	head->data.SetFromFile(filename);

	for (short i = 2; i <= elements; i++) {
		p = (List*)malloc(sizeof(List));
		p->data.SetFromFile(filename, i);

		pred->next = p; //ссылка из предыдущей записи на текущую
		pred = p;	// сохранение адреса текущей записи в поле предыдущей
					// текущая запись становится предыдущей
	}

	ListElements = elements;
	p->next = nullptr;
	return head;
}

bool PrintCriterion(List* head, int criterion = 0)
{
	if (head == nullptr)
		return false;
	List* current = head;
	char counter = 0;
	PrintHead();
	while (current != nullptr) {

		if (current->data.workers == criterion)
		{
			current->data.Print();
			counter++;
		}

		current = current->next;
	}
	_LINE_;
	if (counter == 0)
	{
		system("cls");
		cout << "There is no companies with " << criterion << " workers !\n";
	}

	return true;
}

bool AddInList(int position) {
	if (position > ListElements + 1) {
		cout << "Too big position\n";
		system("pause");
		return false;
	}
	else if (head == nullptr)
		return false;

	List* NewElement = (List*)malloc(sizeof(List));
	NewElement->data.SetCompany(0);

	if (position <= 1)
	{
		NewElement->next = head;
		head = NewElement;
	}
	else {
		List* current = head;

		for (int i = 2; i < position; i++)
			current = current->next;

		NewElement->next = current->next;

		current->next = NewElement;

	}
	ListElements++;
	return true;
}

bool DeleteInList(int position) {
	if (position > ListElements) {
		cout << "Too big position\n";
		system("pause");
		return false;
	}
	else if (head == nullptr)
		return false;

	List* clean;

	if (position <= 1) {
		clean = head;
		head = head->next;
		delete clean;
	}
	else {
		List* current = head;

		for (int i = 2; i < position; i++)
			current = current->next;

		clean = current->next;
		current->next = current->next->next;
		//delete clean;
	}
	ListElements--;
	return true;
}

bool SortList()
{
	if (head == nullptr)
		return false;

	List* NewHead, * current = head, * Newcurrent = (List*)malloc(sizeof(List));
	NewHead = Newcurrent;
	bool isMIn;
	List Min;
	int counter = 1, position = ListElements, backup = ListElements;

	for (int i = 0; i < backup; i++)
	{
		current = head;

		Min.data.workers = _I32_MAX;
		counter = 1;
		isMIn = false;
		while (current != nullptr) {

			if (Min.data.workers >= current->data.workers) {
				Min.data = current->data;
				position = counter;
				isMIn = true;
			}

			current = current->next;
			counter++;
		}

		if (isMIn)
		{
			Newcurrent->data = Min.data;

			Newcurrent->next = (List*)malloc(sizeof(List));

			Newcurrent = Newcurrent->next;

			Newcurrent->next = nullptr;

			DeleteInList(position);
		}
	}
	Newcurrent = nullptr;
	current = head = NewHead;

	while (current != nullptr)
	{
		if (current->next->next == nullptr)
		{
			delete current->next;
			current->next = nullptr;
		}
		current = current->next;
	}
	ListElements = backup;
	return true;
}

bool PrintList(List* head)
{
	if (head == nullptr)
		return false;
	List* current = head;
	PrintHead();
	while (current != nullptr) {
		current->data.Print();
		current = current->next;
	}
	_LINE_;
	cout << "Elements > " << ListElements << endl;
	return true;
}

bool ListToFile(List* head, char* filename)
{
	if (head == nullptr)
		return false;
	remove(filename);
	short notes = 0;
	List* current = head;
	while (current != nullptr)
	{
		current->data.CompanyToFile(filename, notes);
		current = current->next;
	}
	return true;
}