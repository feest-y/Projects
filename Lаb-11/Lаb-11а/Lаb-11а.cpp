#include <iostream>


class Point
{
	int x, y;
public:

	void Set(int x, int y = -987543) { //да, если задать нули - будет работать не совсем корректно
		this->x = x;
		if (y != -987543)
			this->y = y;
	}


	void MyOperation(int& sum, int& mul) {
		sum = x + y;
		mul = x * y;
	}

	void Print() {
		printf("x > %d\ny > %d\n", x, y);
	};

	Point() {
		x = y = 0;
	};

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	};

	Point(const Point& old) {

		this->x = old.x;
		this->y = old.y;
	};

};



int main()
{
	Point A(1, 2),
		B;

	printf("A:\n");
	A.Print();

	printf("\nB:\n");
	B.Print();

	Point C(A);
	printf("\nC(A):\n");
	C.Print();

	B.Set(5, 5);
	printf("\nB:\n");
	B.Print();

	int sum, mul;

	B.MyOperation(sum, mul);
	printf("\nsum(B) > %d\nmul(B) > %d", sum, mul);
	return 0;
}