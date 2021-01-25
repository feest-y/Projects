#pragma once
#include <iostream>
void Debug() {
	time_t t;
	t = time(0);
	std::cout << puts(ctime(&t));
	std::cout << "\b\b\b";
}