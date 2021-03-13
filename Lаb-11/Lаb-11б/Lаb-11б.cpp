#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Figure
{
	unsigned int A, B, C, R;
public:
	Figure(unsigned int R) {
		this->R = R;
		A = B = C = 0;
	};

	Figure() {
		A = B = C = R = 0;
	};

	Figure(unsigned int A, unsigned int B, unsigned int C, unsigned int R = 0) {
		this->A = A;
		this->B = B;
		this->C = C;
		this->R = R;
	};

	double SquareOfTriangle() {
		float p = (A + B + C) / 2;
		return sqrt((p * (p - A) * (p - B) * (p - C)));
	}

	double SquareOfCircle() {
		return M_PI * R * R;
	}

};

int main()
{
	Figure A(3,2,3,4);
	std::cout <<"SquareOfTriangle > "<< A.SquareOfTriangle()<<std::endl;
	std::cout << "SquareOfCircle > " << A.SquareOfCircle();
	return 0;
}