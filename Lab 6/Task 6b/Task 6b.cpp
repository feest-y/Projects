#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int a = 0, b = 0, m = 0, x = 0;
	for (int i = 1; i <= 10; i++)
	{
		a = (rand() / 100) % 10;
		b = rand() % 10;
		printf("%d. %d * %d = ", i, a, b);
		scanf_s("%d", &x);
		if (a * b == x)
		{
			m++;
		}
	}
	printf("Вы набрали %d балов из 10", m);
	return 0;
}

//Нужно ли фиксить проблему с одинаковыми примерами ?