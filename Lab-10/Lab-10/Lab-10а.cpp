#include <iostream>
using namespace std;
class Sq {
public:
	template <typename T>
	T Square(T a, T b = '\0') {
		if (b == '\0')
			return a * a;
		else
			return a * b;
	}
};

int main()
{
	Sq A;
	cout << A.Square(6);
	return 0;
}