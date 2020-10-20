#include<iostream>
#include <time.h>
int main()
{
	unsigned long long a = 0;
	unsigned long long b = 0;
	printf("Input the biggest number you know - ");
	scanf_s("%lld", &a);
	printf("I know bigger number than yours:) - ");
	srand(time(NULL));
	b = a + rand();
	printf("%lld", b);
	return 0;
}