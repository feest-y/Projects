#define _CRT_SECURE_NO_WARNINGS
#include "..\..\..\Functions\Functions.h"
#include "Company.h"

int main()
{
	Standart();
	char* input = new char[50]{};
	char* name = new char[50]{};
	char type = name[0];
	int workers = 0;
	float area = 0;


	Company A;
	A.SetCompany(1);

	input = A.GetInput();
	name = A.GetName();
	type = A.GetType();
	workers = A.GetWorkers();
	area = A.GetArea();
	A.PrintHead();
	zxc;
	cout.width(11);
	cout << name;
	zxc;
	cout.width(7);
	cout << type;
	zxc;
	cout.width(10);
	cout << workers;
	zxc;
	cout.width(13);
	cout << area;
	zxc;
	printf("\n");
	cout.width(1);
	A.Show();
	_LINE_;
	r0;
}