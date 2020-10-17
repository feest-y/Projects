int main()
{
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("\n%d", a);
	printf("\n%d", b);
	return 0;
}