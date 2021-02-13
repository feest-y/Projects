#include <iostream>
#include "..\..\Header\Header.h"

using namespace std;


short MinI(int a = INT32_MIN, int b = INT32_MIN, int c = INT32_MIN) {
	short index;

	if (a <= b && a <= c)
		index = 0;
	else if (b <= a && b <= c)
		index = 1;
	else
		index = 2;

	return index;
}

short MaxI(int a = INT32_MIN, int b = INT32_MIN, int c = INT32_MIN) {
	short index;

	if (a >= b && a >= c)
		index = 0;
	else if (b >= a && b >= c)
		index = 1;
	else
		index = 2;

	return index;
}

void SwapP(int* a, int* b, int* c) {
	int minimum = 0;
	short min = MinI(*a, *b, *c), max = MaxI(*a, *b, *c);

	if (min == 0)
		minimum = *a;
	else if (min == 1)
		minimum = *b;
	else if (min == 2)
		minimum = *c;

	if (max == 0) {

		if (min == 1) {
			*b = *a;
			*a = minimum;
		}
		else if (min == 2) {
			*c = *a;
			*a = minimum;
		}

	}
	else if (max == 1) {

		if (min == 0) {
			*a = *b;
			*b = minimum;
		}
		else if (min == 2) {
			*c = *b;
			*b = minimum;
		}

	}
	else if (max == 2) {

		if (min == 0) {
			*a = *c;
			*c = minimum;
		}
		else if (min == 1) {
			*b = *c;
			*c = minimum;
		}
	}
}


void SwapL(int& a, int& b, int& c) {
	int minimum = 0;
	short min = MinI(a, b, c), max = MaxI(a, b, c);

	if (min == 0)
		minimum = a;
	else if (min == 1)
		minimum = b;
	else if (min == 2)
		minimum = c;

	if (max == 0) {

		if (min == 1) {
			b = a;
			a = minimum;
		}
		else if (min == 2) {
			c = a;
			a = minimum;
		}

	}
	else if (max == 1) {

		if (min == 0) {
			a = b;
			b = minimum;
		}
		else if (min == 2) {
			c = b;
			b = minimum;
		}

	}
	else if (max == 2) {

		if (min == 0) {
			a = c;
			c = minimum;
		}
		else if (min == 1) {
			b = c;
			c = minimum;
		}
	}
}

int main()
{
	int a = InputSize("a >"),
		b = InputSize("b >"),
		c = InputSize("c >");

	//SwapP(&a, &b, &c);
	SwapL(a, b, c);
	printf("\na > %d\nb > %d\nc > %d\n", a, b, c);

	r0;
}