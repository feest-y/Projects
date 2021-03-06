﻿/********************************************************/
/*             Лабораторная  работа №2                  */
/*            Типы данных и ввод-вывод                  */
/*			   	      Вариант №3						*/
/*		    Солтус Андрей Евгениевич 320-В				*/
/********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
int main() {
	setlocale(LC_ALL, "rus");
	char sur1[25] = "", sur2[25] = "", sur3[25] = "";
	char name1[25] = "", name2[25] = "", name3[25] = "";
	int year1 = 0, year2 = 0, year3 = 0;
	float sall1 = 0, sall2 = 0, sall3 = 0;
	/* Введение фактических данных*/
	printf("1. Введите: Фамилию, инициалы, год рождения, оклад >");
	scanf_s("%s %s %d %f", sur1, 25, name1, 25, &year1, &sall1);
	printf("2. Введите: Фамилию, инициалы, год рождения, оклад >");
	scanf_s("%s %s %d %f", sur2, 25, name2, 25, &year2, &sall2);
	printf("3. Введите: Фамилию, инициалы, год рождения, оклад >");
	scanf_s("%s %s %d %f", sur3, 25, name3, 25, &year3, &sall3);
	/* Вывод таблицы */
	/* вывод заголовков */
	printf("\n--------------------------------------------------\n");
	printf("|                 Отдел кадров                   |\n");
	printf("|------------------------------------------------|\n");
	printf("|   Фамилия   | Инициалы | Год рожд. |   Оклад   |\n");
	printf("|-------------|----------|-----------|-----------|\n");
	/* вывод строк фактических данных */
	printf("|1. %-9s | %-8s | %-9d | %-8.2f$ |\n", sur1, name1, year1, sall1);
	printf("|2. %-9s | %-8s | %-9d | %-8.2f$ |\n", sur2, name2, year2, sall2);
	printf("|3. %-9s | %-8s | %-9d | %-8.2f$ |\n", sur3, name3, year3, sall3);
	/* вывод примечаний */
	printf("|------------------------------------------------|\n");
	printf("| Примечание: оклад установлен по состоянию на   |\n");
	printf("| 1 января 2000 года                             |\n");
	printf("--------------------------------------------------\n");
	return 0;
}