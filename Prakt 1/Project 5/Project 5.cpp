#include <time.h>
int main()
{
	long int a;
	unsigned long long int b = 0;
	printf("Input the biggest number you know - ");
	scanf_s("%d", &a);
	printf("I know bigger number than yours:) - ");
	srand(time(NULL));
	while (b < a) {
		b = a + rand();
	}
	cout << b;
	return 0;
}