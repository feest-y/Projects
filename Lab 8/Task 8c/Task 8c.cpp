#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "rus");
	bool places[10];
	char q[5];
	unsigned short j = 0, k = 0;

	//printf("%s",q);
	while (j != 5 || k != 5)
	{
		system("cls");
		printf("Курите ? (YES\\NO) > ");
		scanf_s("%s", q, 5);
		if (q[0] == 'Y' && q[1] == 'E' && q[2] == 'S')
		{
			if (j <= 4) {
				places[j] = 1;
				j++;
				printf("Место №%d зарезервировано", j);
				Sleep(300);
			}
			else {
				printf("\bМест нет\n");
				Sleep(600);
			}
		}
		else if (q[0] == 'N' && q[1] == 'O') {
			if (k <= 4) {
				places[k] = 1;
				k++;
				printf("Место №%d зарезервировано", k);
				Sleep(300);
			}
			else {
				printf("\bМест нет\n");
				Sleep(600);
			}
		}
		else {
				printf("Ответ некорректный\n");
				Sleep(600);
		}
	}
	printf("\nМеста закончились");

	return 0;
}