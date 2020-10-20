#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned short n = 0,
		period = 4,
		t = 0;
	float x = 0,
		y = 0,
		step = 0.25,
		max_value = 19.75,
		operations = max_value / step + 1;
	for (int i = 1; i <= operations; i++)
	{
		if (x != 0&&(((int)(x*1000))%4000==0)) {
			n = n + 4;
			t++;
		}
		if (i < 10) {
			printf(" ");
		}

		if (x >= (0 + n) && x < (2 + n)) {
			y = 1.5 * x - 1 - (1.5 * period) * t;
			printf("%d. x = %0.2f; y = %0.3lf\n", i, x, y);
		}
		else if (x == (2 + n)) {
			printf("%d. x = %0.2f; y Є [1, 2]\n", i, x);
		}
		else if (x > (2 + n) && x <= (3 + n)) {
			y = 5 - 2 * x + (2 * period) * t;
			printf("%d. x = %0.2f; y = %0.3lf\n", i, x, y);
		}
		else if (x > (3 + n) && x < (4 + n)) {
			y = -1;
			printf("%d. x = %0.2f; y = %0.3lf\n", i, x, y);
		}
		x += step;
	}
	return 0;
}


// y = 1.5x - 1 x Є [0+n*4, 2+n*4) n Є z
// x = 2 x Є {2+n*4} n Є z
// y = 5 - 2x x Є (2+n*4, 3+n*4] n Є z
// y = -1 x Є (3+n*4, 4+n*4) n Є z
