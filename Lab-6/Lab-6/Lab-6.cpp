#include <iostream>
#include <String>
using namespace std;

int StrToInt(string b)
{
	int x = 0;
	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] >= 48 && b[i] <= 57)
		{
			x *= 10;
			x += (b[i] - 48);
		}
	}
	return x;
}

int main() {

	setlocale(LC_ALL, "ru");
	int length = 0;
	string input = "x";

	do
	{
		system("cls");
		cout << "¬ведите длинну первой строки > ";
		cin >> input;
		length = StrToInt(input);
		input = "x";
	} while (length <= 0);
	char* Str1 = new char[length + 1];
	input = "x";

	do
	{
		system("cls");
		cout << "¬ведите длинну второй строки > ";
		cin >> input;
		length = StrToInt(input);
		input = "x";
	} while (length <= 0);

	system("cls");

	char* Str2 = new char[length + 1];

	do
	{
		system("cls");
		cout << "Str1 > ";
		cin >> input;
	} while (input.length() > length);

	for (int i = 0; i < input.length(); i++)
	{
		*(Str1 + i) = input[i];
	}
	do
	{
		system("cls");
		cout << "Str2 > ";
		cin >> input;
	} while (input.length() > length);

	for (int i = 0; i < input.length(); i++)
	{
		*(Str2 + i) = input[i];
	}

	int i = 0, j = 0, counter = 0, counter1 = 0;

	while (Str1[i] != '\0')
	{
		counter = j = 0;
		while (Str2[j] != '\0')
		{
			if (Str1[i] == Str2[j])
			{
				counter++;
				break;
			}
			j++;
		}
		if (counter == 0)
		{
			cout << "Unique symbol > " << Str1[i];
			break;
		}
		i++;
	}

	delete[] Str1;
	delete[] Str2;
	return 0;
}