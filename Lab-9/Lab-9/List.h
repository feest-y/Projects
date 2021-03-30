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

	List() {
		next = nullptr;
		prev = nullptr;
	}
};

List* head = nullptr; // адрес головы списка
List* tail = nullptr; // адрес хвоста списка
short ListElements = 0;

List* Create(List* head, short n = 1)
{
	if (n <= 0)
	{
		cout << "Wrong amount of elements !\n";
		return head;
	}

	if (head != nullptr)
		free(head);

	List* current;
	head = current = (List*)malloc(sizeof(List));
	current->data.SetCompany(true);
	head->prev = nullptr;

	for (short i = 1; i < n; i++) {
		current->next = (List*)malloc(sizeof(List));
		current->next->prev = current;
		current = current->next;
		current->data.SetCompany(true);
	}

	ListElements = n;
	current->next = nullptr;
	tail = current;
	return head;
}

List* CreateFromFile(char* filename, int elements = ListElements) {

	elements = InputSize("Amount of elements > ");

	if (head != nullptr)
		free(head);
	head = (List*)malloc(sizeof(List));
	List* current = head;
	head->prev = nullptr;
	head->data.SetFromFile(filename);

	for (int i = 2; i <= elements; i++)
	{
		current->next = (List*)malloc(sizeof(List));
		current->next->prev = current;
		current = current->next;
		current->data.SetFromFile(filename, i);
	}
	tail = current;
	ListElements = elements;
	current->next = nullptr;
	return head;
}

bool PrintCriterion(List* element, int criterion = 0)
{
	if (element == nullptr)
		return false;
	List* current = element;
	char counter = 0;
	PrintHead();

	if (element->prev == nullptr)
	{

		while (current != nullptr) {

			if (current->data.workers == criterion)
			{
				current->data.Print();
				counter++;
			}

			current = current->next;
		}
	}
	else if (element->next == nullptr) {
		while (current != nullptr) {

			if (current->data.workers == criterion)
			{
				current->data.Print();
				counter++;
			}

			current = current->prev;
		}
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
	List* current;

	if (position <= 1)
	{
		head->prev = NewElement;
		NewElement->next = head;
		head = NewElement;
	}
	else if (position > ListElements) {
		current = tail;
		NewElement->next = nullptr;
		NewElement->prev = tail;
		tail->next = NewElement;
		tail = NewElement;
	}
	else {
		current = head;
		for (int i = 2; i < position; i++)
			current = current->next;

		NewElement->next = current->next;
		NewElement->prev = current;
		current->next->prev = NewElement;
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
		head->prev->next = nullptr;
		head->prev = nullptr;
		delete clean;
	}
	else if (position == ListElements) {
		clean = tail;

		tail = tail->prev;
		tail->next->prev = nullptr;
		tail->next = nullptr;
		delete clean;
	}
	else {
		List* current = head;

		for (int i = 2; i <= position; i++)
			current = current->next;

		current->next->prev = current->next->prev->prev;
		current->prev->next = current->next;
		current->next = nullptr;
		current->next = nullptr;
		delete current;
	}
	ListElements--;
	return true;
}

bool SortList() {
	if (head == nullptr)
		return false;
	Company buff;
	List* current = head, * current2, * addressOfMin = head;
	int min = INT32_MAX, counter = 0;
	bool isMin = true;
	while (isMin && !(counter >= ListElements))
	{
		current = head;
		isMin = false;
		min = INT32_MAX;
		for (int i = 0; i < counter /*&& current2->next != nullptr*/; i++)
			current = current->next;

		while (current != nullptr)
		{
			if (current->data.workers < min)
			{
				isMin = true;
				min = current->data.workers;
				buff = current->data;
				addressOfMin = current;
			}

			current = current->next;
		}
		current2 = head;
		for (int i = 0; i < counter /*&& current2->next != nullptr*/; i++)
			current2 = current2->next;

		addressOfMin->data = current2->data;
		current2->data = buff;
		counter++;
	}


	return true;
}

bool PrintList(List* elem)
{
	if (elem == nullptr)
		return false;

	List* current = elem;
	PrintHead();


	if (elem->prev == nullptr)
	{
		while (current != nullptr) {
			current->data.Print();
			current = current->next;
		}
	}
	else if (elem->next == nullptr) {
		while (current != nullptr) {
			current->data.Print();
			current = current->prev;
		}
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