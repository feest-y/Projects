#pragma once
#include <iostream>
#include <String>
#include "Debug.h"

#define zxc printf("|")

using namespace std;

struct Company
{
	std::string name = "N";
	char type = name[0];
	float area = 0;
	int workers = 0;

	void SetCompany(bool x = 0);
	void PrintCompany();
}A[10];

void Company::SetCompany(bool x) {
	if (x)
	{
		name[0] = rand() % (122 - 65) + 65;
		type = rand() % (122 - 65) + 65;
		workers = rand() % 12700;
		area = (float)(rand() % 1270);
	}
	else {
		cout << "Company name > ";
		cin >> name;
		cout << "Company type > ";
		cin >> type;
		cout << "Company workers > ";
		cin >> workers;
		cout << "Company area > ";
		cin >> area;
	}

#ifdef DEBUG
	std::cout << __FILE__ << " > " << __FUNCTION__ << ": ";
	Debug();
#endif // DEBUG
}

void Company::PrintCompany() {
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

#ifdef DEBUG
	std::cout << __FILE__ << " > " << __FUNCTION__ << ": ";
	Debug();
#endif // DEBUG
}