#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#define PRINT_TYPE

#include "Company.h"
#include "Functions.h"
#include "Debug.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	Company All;
	short n = 10;

	for (short i = 0; i < n; i++)
	{
#ifdef PRINT_TYPE
		A[i].SetCompany(true);
#else
		if (i != 0) std::cout << "\n";
		std::cout << "Company " << i + 1 << ":\n";
		A[i].SetCompany(false);
#endif // PRINT_TYPE

	}

	PrintS(All);

	SortS(All);

	PrintS(All);
#ifdef DEBUG
	std::cout << __FILE__ <<" > "<< __FUNCTION__ << ": ";
	Debug();
#endif // DEBUG
	return 0;
}
