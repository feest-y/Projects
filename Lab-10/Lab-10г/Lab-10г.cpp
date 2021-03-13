#include "..\..\Header\Header.h"

class Timer {
	int sec;
public:

	Timer(int sec = 0) {
		this->sec = sec;
	};

	Timer(int min, int sec) {
		this->sec = sec + min * 60;
	};

	void Print() {
		cout << sec << endl;
	}
	void SetS(int value = 0) {
		sec = value;
	}

	Timer(const Timer& old) {
		this->sec = old.sec;
	};
};

int main()
{
	Timer A(6), B;
	//A.SetS(5);
	B = A;
	B.Print();
	r0;
}