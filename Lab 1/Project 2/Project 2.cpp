#include<iostream>
int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, c;
	float s, p;
	a = b = c = s = p = 0;
	printf("Введите а,в,с:\n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("S= %f", s);
	return 0;
}