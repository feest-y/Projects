#include "..\..\Functions\Functions.h"

class Sum {
	//private:
public:
	int* x = new int, * y = new int, * sum = new int;

public:
	void Init() {
		*x = InputSize("x > ");
		*y = InputSize("y > ");
		cout << endl;
	}
	void Print() {
		printf("x > %d\ny > %d\nsum > %d\n", *x, *y, *sum);
	}
	void CountS(bool Print = false) {
		*sum = *x + *y;
		if (Print)
			cout << *sum << endl;
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
	~Sum() {
		delete x;
		delete y;
		delete sum;
		cout << "\nDestructor: " << this;
	}
};

int main()
{
	Standart();
	int a = 5, b = 6;
	Sum A(a, b);
	Sum* C = new Sum(a + 1, b + 1);

	//A.Init();
	A.CountS();
	A.Print();


	cout << "\npointerX > " << *A.x;
	cout << "\npointerX > " << *A.y;

	cout << "\npointersC > " << *C->y << "\t" << *C->x;
	delete C;
	r0;
}