#include <iostream>
#include <math.h>
int main()
{
	const double eps = 0.000001;
	double
		n = 0,
		s = 0,
		s10 = 0,
		// correct_a1 = (-2 * (1 + 1)) / (1 + 1 * 1),
		// correct_a = (-2 * (n + 1)) / (1 + n * n),
		k = 1, //(-1)^n
		a = k * (2 * (n + 1)) / (2 + (n + 1) * (n - 1));
	
	while (fabs(a) >= eps)
	{
		a = k * (2 * (n + 1)) / (2 + (n + 1) * (n - 1));
		s += a;
		if (n == 10)
		{
			s10 = s;
		}
		if ((int)n % 500 == 0) {
			//printf("s%d = %1.15lf\n", (int)n, s);
			//printf("a%d = %1.15lf\n", (int)n, a);
		}
		n++;
		k *= -1;
	}

	printf("s10 = %1.10lf\n", s10);
	printf("s%d = %1.15lf\n", (int)n, s);
	printf("a%d = %1.19lf\n", (int)n, a);
}



// после упрощения дроби (-2 * (n + 1)) / (1 + n * n)