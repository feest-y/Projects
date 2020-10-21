#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	const int n = 100;
	int Arr[n];
	for (int i = 0; i < 100; i++)
	{
		Arr[i] = rand() % 100 - 50;
		printf("Arr[%d] = %d\n", i, Arr[i]);
	}
}