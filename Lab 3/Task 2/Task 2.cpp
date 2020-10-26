#include <iostream>
#include <stdio.h>
#include <math.h>
const double PI = atan(1.0) * 4;
int main()
{
	setlocale(LC_ALL, "rus");
	double a = 1, b = 1, x = 1, y = 1, t2 = 1, xr;
	printf("Input x,y > ");
	scanf_s("%lf %lf", &x, &y);
	xr = x * PI / 180;
	if ((2 * a * pow(cos(xr), 2)) != 0 && 2 * a != 0 && (tan((a * xr) / 2)) > 0 && cos(a * xr / 2) != 0) { //ОДЗ
		t2 = (sin(a * xr)) / (2 * a * pow(cos(xr), 2) + (1 / (2 * a)) * log(tan((a * xr) / 2)));
		printf("t2=%lf\n", t2);
	}
	else {
		printf("Значения не допустимы");
	}
}