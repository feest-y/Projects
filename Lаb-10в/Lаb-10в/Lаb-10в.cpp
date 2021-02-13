#include "..\..\Header\Header.h"


class Sum {
public:
	int x = 0, y = 0, s = 0;
	void Init() {
		x = InputSize("x > ");
		y = InputSize("y > ");
	}void Print() {
		cout << "\nx > " << x << endl << "y > " << y << endl << "s > " << s << endl;
	}void CountS() {
		s = x + y;
		//cout << s << endl;
	}
};

int main()
{
	Standart();
	Sum A;
	A.Init();
	A.Print();
	return 0;
}