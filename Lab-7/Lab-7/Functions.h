#pragma once
#include <String>
//#include <cmath>

int StrToInt(std::string b) {
	int x = 0, counter = 0;;
	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] >= 48 && b[i] <= 57 && counter == 0)
		{
			x *= 10;
			x += (b[i] - 48);
		}
		/*else if (b[i] == 46 && b[i + 1] >= 48 && b[i + 1] <= 57) {
			counter++;
		}
		else if (counter != 0 && b[i] >= 48 && b[i] <= 57) {
			x += (b[i] - 48)/(pow(10,counter));
			counter++;
		}*/
	}
	return x;
}