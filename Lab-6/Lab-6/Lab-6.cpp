#include <iostream>
#include <String>
using namespace std;


int main() {

	setlocale(LC_ALL, "ru");
	int length = 1000;
	string input;

	cout << "¬ведите длинну первой строки > ";
	while (cin >> length)
	{

	}
	char* Str1 = new char[length];

	cout << "¬ведите длинну второй строки > ";
	while (cin >> length)
	{

	}
	char* Str2 = new char[length];


	cout << "Str1 > ";
	cin >> Str1;
	cout << "Str2 > ";
	cin >> Str2;
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
			cout << Str1[i];
			break;
		}
		i++;
	}

	delete[] Str1;
	delete[] Str2;
	return 0;
}