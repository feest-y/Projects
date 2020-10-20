#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int a = 0, x = 0, i = 0;
	unsigned r = rand() * (rand() % 9);
	r /= 10;
	printf("Выбери уровень сложности:\n1.Легкий (1 - 100)\n2.Нормальный (1 - 1 000)\n3.Сложный (1 - 10 000)\n> ");
	scanf_s("%d", &a);

	while (i != 1)
	{
		if (a == 1) {
			x = r % 100 + 1;
			i = 1;
		}
		else if (a == 2) {
			x = r % 1000 + 1;
			i = 1;
		}
		else if (a == 3) {
			x = r % 10000 + 1;
			i = 1;
		}
		else {
			system("cls");
			printf("Попробуйте еще раз.\nВыберите уровень сложности:\n1.Легкий (1 - 100)\n2.Нормальный (1 - 1 000)\n3.Сложный (1 - 1 000 000)\n> ");
			scanf_s("%d", &a);
		}
	}

	i = 0;
	system("cls");
	printf("x = %d\n", x);
	printf("Напиши чило > ");

	while (a != x)
	{
		i++;
		scanf_s("%d", &a);
		if (a < x) {
			system("cls");
			printf("%d < x", a);
		}

		else if (a > x) {
			system("cls");
			printf("%d > x", a);
		}
		printf("\nНапиши чило > ");
	}
	system("cls");
	printf("Вы угадали!!!\nКоличество ваших попыток - %d", i);

	return 0;
}