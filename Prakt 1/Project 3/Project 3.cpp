int main()
{
	setlocale(LC_ALL, "rus");
	int a = 0;
	printf("Введите а: ");
	scanf_s("%d", &a);
	for (int i = 0; i < 3; i++)
	{
		a = a * a;
	}
	printf("a^8= %d", a);
	return 0;
}