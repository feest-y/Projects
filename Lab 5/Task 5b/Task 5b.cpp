#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	int k = 0;
	printf("k > ");
	scanf_s("%d", &k);

	//for (int i = 0; i <= 100; i++)
	//{
		//k = i;
	printf("У меня %d гриб", k);
	if ((k > 10 && k < 20) || (k % 10 >= 5 && k % 10 <= 9) || k % 10 == 0) {
		printf("ов\n");
	}
	else if (k % 10 >= 2 && k % 10 <= 4) {
		printf("а\n");
	}
	else printf("\n");
	//}

}