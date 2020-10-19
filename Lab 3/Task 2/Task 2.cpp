#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "rus");
	double a = 1, b = 1, x = 1, y = 1, t2 = 1;
	printf("Input x,y > ");
	scanf_s("%lf %lf", &x, &y);
	if ((2 * a * pow(cos(x), 2)) != 0 && 2 * a != 0 && (tan((a * x) / 2)) > 0 && cos(a * x / 2) != 0) { //ОДЗ
		t2 = (sin(a * x)) / (2 * a * pow(cos(x), 2) + (1 / (2 * a)) * log(tan((a * x) / 2)));
		printf("t2=%lf\n", t2);
	}
	else {
		printf("Значения не допустимы");
	}
}