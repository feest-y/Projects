#include "..\..\Header\Header.h"


class Timer {
public:
	int sec;
	Timer(int sec = 0, int min = 0) {
		this->sec = sec + min * 60;
	};

	void Print() {
		cout << sec << endl;
	}
};
int main()
{
	Timer A = (1, 2);
	A.Print();
	r0;
}