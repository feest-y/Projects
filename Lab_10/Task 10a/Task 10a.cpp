#include <iostream>


char Compare(int a, int b) {
	if (a < b) return '<';
	else if (a > b) return '>';
	else if (a == b) return '=';
	else return '#';
}


int main()
{
	setlocale(LC_ALL, "rus");
	int a, b;
	printf("Введите a: ");
	scanf_s("%d", &a);
	printf("Введите b: ");
	scanf_s("%d", &b);
	system("cls");
	printf("a = %d\nb = %d\n", a, b);
	printf("a %c b", Compare(a, b));
	return 0;
}