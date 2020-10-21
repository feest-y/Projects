#include <iostream>
#include<ctime>
int main()
{
	srand(time(NULL));
	int Arr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		Arr[i] = rand() % 100 - 50;
		printf("Arr[%d] = %d\n", i, Arr[i]);
	}
}