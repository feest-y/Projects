#include <iostream>
#include <stdio.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "rus");
	double a = 1, b = 1, c = 1, d = 1, x = 1, y = 1, t1 = 1;
	printf("Input x,y > ");
	scanf_s("%lf %lf", &x, &y);
	if ((c != 0) && (a * x + b != 0) && c != 0 && ((y * x + a) / (a * x + b)) > 0) {
		t1 = (1 / c) * ((1 / (a * x + b) + (y / c) * log((y * x + a) / (a * x + b))));
		printf("t1=%lf\n", t1);
	}
	else {
		printf("Значения не допустимы");
	}
}