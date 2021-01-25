#include <iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "ru");
	int length = 0;
	cout << "¬ведите длинну первой строки > ";
	cin >> length;
	char* Str1 = new char[length];

	cout << "¬ведите длинну второй строки > ";
	cin >> length;
	char* Str2 = new char[length];


	delete[] Str1;
	delete[] Str2;
	return 0;
}