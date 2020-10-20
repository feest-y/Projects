#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "rus");
	int year = 0, ySec = 365 * 24 * 3600, day = 24 * 3600;
	long long out = 0;
	long out_s = 0;
	printf("Введите год - ");
	scanf_s("%d", &year);
	
	if (year % 4 == 0) {
		out_s = out = (long long)ySec + day;
		printf("\nlong long > %lld секунд в этом высокосном году", out);
		printf("\nlong > %ld секунд в этом высокосном году", out_s);
	}
	else {
		out_s = out = ySec;
		printf("\nlong long > %lld секунд в этом не высокосном году", out);
		printf("\nlong > %ld секунд в этом не высокосном году", out_s);
	}
	out_s = out = (long long)ySec * 100 + (long long)day * (100 / 4);
	printf("\n\nlong long > Также в 100 лет - %lld секунд", out);
	printf("\nlong > Также в 100 лет - %ld секунд", out_s);
	out_s = out *= 10;
	printf("\n\nlong long > А также в 1000 лет - %lld секунд", out);
	printf("\nlong > А также в 1000 лет - %ld секунд\n", out_s);
	return 0;
}