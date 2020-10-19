#include <iostream>
#include <stdio.h>
int main()
{
	setlocale(LC_ALL, "rus");
	double x = 0, y = 0;
	printf("Введите x,y > ");
	scanf_s("%lf %lf", &x, &y);
	system("cls");
	printf("x = %lf; y = %lf\n", x, y);
	if (x >= -1 && x <= 0 && y >= 0 && y <= 1) {
		printf("Заданая точка попадает в область в левой части графика\n");
	}
	else if (((x * x + y * y) <= 1) && x >= 0 && y <= 0) {
		printf("Заданая точка попадает в область в правой части графика\n");
	}
	else printf("Заданая точка не попадает в область\n");
	printf(" x Є [-1,0], y Є [0,1];\n или\n x^2 + y^2 <= 1; при x >=0 и y <=0;");
}

// x Є [-1,0], y Є [0,1];

// или

// x^2 + y^2 <= 1;
// при x >=0; y <=0;