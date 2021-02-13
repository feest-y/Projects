#include <iostream>
using namespace std;

template <typename T>
T Square(T a, T b = '\0') {
	if (b == '\0')
		return a * a;
	else
		return a * b;
}

int main()
{
	cout << Square(6);
	return 0;
}