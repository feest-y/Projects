#include <iostream>
#include <math.h>

int main()
{
	setlocale(LC_ALL,"rus");
	int a, b, c, d;
	double  x1, x2;
	printf("ax^2 + bx + c = 0\na > ");
	scanf_s("%d", &a);
	printf("b > ");
	scanf_s("%d", &b);
	printf("c > ");
	scanf_s("%d", &c);
	d = b * b - (4 * a * c);
	x1 = (-b + (float)sqrt(d)) / (2 * a);
	if (d < 0)
	{
		printf("Значения некорректны");
	}
	else if (d > 0)
	{
		x2 = (-b - (float)sqrt(d)) / (2 * a);
		printf("x1 = %lf\nx2 = %lf", x1, x2);
	}
	else if (d == 0) {
		printf("x = %lf", x1);
	}
	else printf("Значения некорректны");
}