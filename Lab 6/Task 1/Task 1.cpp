#include <iostream>

int main()
{
	int n = 10;
	double a = (-2 * (n + 1)) / (1 + n * n), // после упрощения дроби
		s10 = a,
		a1 = (-2 * (1 + 1)) / (1 + 1 * 1),
		a2 = (-2 * (2 + 1)) / (1 + 2 * 2),
		d = a2 - a1;

	for (double i = 1; i <= n; i++)
	{
		a = (-2 * (i + 1)) / (1 + i * i);
		s10 += a;
		//printf("a%d = %lf\n", (int)i, s);
	}

	printf("a10 = %lf\n", s10);
	printf("a1 = %lf\n", a1);
	printf("d = %lf\n", d);
}

















/*for (int i = 1; i <= n; i++)
{
	a = (-2 * (i + 1)) / (1 + i * i);
	s10 += a;
}*/