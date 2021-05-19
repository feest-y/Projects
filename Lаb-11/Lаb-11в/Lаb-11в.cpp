#include <iostream>


class Complex
{
	double R;
	double M;
public:
	double GetR() {
		return R;
	}
	double GetM() {
		return M;
	}
	void Init(double R = 0, double M = 0) {
		this->R = R;
		this->M = M;
	}

	void Sum(Complex A) {
		this->R += A.GetR();
		this->M += A.GetM();
	}
	void Add(int ToR = 0, int ToM = 0) {
		R += ToR;
		M += ToM;
	}
	void Solve() {
		double I = (5 - R) / (M - 4);
		std::cout << "I = " << I << "\n";// БРЕД !
	}
	void Print() {
		std::cout << R << " + (" << M << ")i\n";
	}
	Complex() {
		R = 0;
		M = 0;
	};
	Complex(double R, double M) {
		this->R = R;
		this->M = M;
	};


};

int main()
{
	Complex A(5, 4);
	Complex B(1, 1);
	A.Sum(B);
	A.Print();
	A.Solve();
	return 0;
}