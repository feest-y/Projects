#include <stdio.h>
#include <iostream>
void push_inside(int*& arr, unsigned int& size, const int value, const unsigned int position)
{
	int x = 0;
	if (position > size)
	{
		x += position - size;
	}
	int* newArray = new int[size + 1 + x];

	for (unsigned int i = 0; i < position; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[position] = value;
	for (unsigned int i = position; i < size; i++)
	{
		newArray[i + 1] = arr[i];
	}
	for (unsigned int i = size; i < position; i++)
	{
		newArray[i] = 0;
	}
	size = size + 1 + x;
	delete[] arr;
	arr = newArray;
}
template <typename T>
void bin(T num = 0) {
	if (num != 0)
	{
		unsigned int size = 0, i = 0;
		int* Arr = new int[size];
		while (num)
		{
			push_inside(Arr, size, num % 2, i);
			num /= 2;
		}
		printf(" ( ");
		for (int i = size - 1; i >= 0; i--)
		{
			printf("%d", Arr[i]);
		}
		printf(" ) ");
		delete[] Arr;
	}
	else printf(" ( 0 ) ");
}
int main() {
	setlocale(LC_ALL, "ru");
	char t; // код типа файла
	char a; // код доступа
	unsigned char i; // номер файлового индекса
	unsigned short UnitStateWord = 0;
	do {
		system("cls");
		printf("Введите код типа файла - t (0 - 15) > ");
		scanf_s("%hhd", &t);
	} while (t > 15 || t < 0);

	do
	{
		system("cls");
		printf("Код типа файла - t (0 - 15) > %hhd", t);
		bin(t);
		printf("\nВведите код доступа - a (0 - 7) > ");
		scanf_s("%hhd", &a);
	} while (a > 7 || a < 0);

	do
	{
		system("cls");
		printf("Код типа файла - t (0 - 15) > %hhd", t);
		bin(t);
		printf("\nКод доступа - a (0 - 7) > %hhd", a);
		bin(a);
		printf("\nВведите номер файлового индекса - i (0 - 255) > ");
		scanf_s("%hhd", &i);
	} while (i > 255 || i < 0); // смысла нет, но пускай будет 

	system("cls");
	printf("Код типа файла - t (0 - 15) > %hhd", t);
	bin(t);
	printf("\nКод доступа - a (0 - 7) > %hhd", a);
	bin(a);
	printf("\nНомер файлового индекса - i (0 - 255) > %u", i);
	bin(i);
	UnitStateWord += t << 12;
	UnitStateWord += a << 9;
	UnitStateWord += i;
	printf("\nСлово состояния устройства - %04X", UnitStateWord);
	bin(UnitStateWord);
	t = a = i = 0;
	t = (UnitStateWord >> 12);
	a = ((UnitStateWord & 0b0000111111111111) >> 9);
	i = UnitStateWord & 0b0000000011111111;
	printf("\nt = %hhd, a = %hhd, i = %u", t, a, i);
	return 0;
}