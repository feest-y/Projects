#include <iostream>
#include <ctime>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int k = 12345670, buff = 0, i = 1;
	printf("Введите число > ");
	scanf_s("%d", &k);
	while (true)
	{
		i++;
		buff = k % (int)pow(10, i);
		k -= buff;
		
	}


}