#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "rus");
	int year = 0, ySec = 365 * 24 * 3600, day = 24 * 3600;
	long long out = 0;
	printf("Введите год - ");
	scanf_s("%d", &year);
	if (year % 4 == 0) {
		out = (long long)ySec + day;
		printf("%lld", out);
		printf(" секунд в этом высокосном году");
	}
	else {
		out = ySec;
		printf("%lld", out);
		printf(" секунд в этом не высокосном году");
	}
	out = (long long)ySec * 100 + (long long)day * (100 / 4);
	printf("\nТакже в 100 лет - %lld", out);
	out *= 10;
	printf(" секунд\nА также в 1000 лет - %lld", out);
	printf(" секунд");
	return 0;
}