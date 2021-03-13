#include "..\..\Header\Header.h"

class Sum {
private:
	int* x, * y, * sum;
public:
	void Init() {
		*x = InputSize("x > ");
		*y = InputSize("y > ");
		cout << endl;
	}
	void Print() {
		printf("x > %d\ny > %d\nsum > %d", *x, *y, *sum);
	}
	void CountS() {
		*sum = *x + *y;
		cout << sum << endl;
	}
	Sum() {
		*x = 0;
		*y = 0;
		*sum = 0;
	}
	Sum(int x, int y) {
		*this->x = x;
		*this->y = y;
		*sum = x + y;
	}
	/*Sum(int* x, int* y, int* sum = nullptr) {
		this->x = x;
		this->y = y;
		*sum = *x + *y;
		this->sum = sum;
	}*/
};

int main()
{
	Standart();
	int a = 5, b = 6;
	Sum A(a, b);

	//A.Init();
	A.CountS();
	A.Print();

	r0;
}