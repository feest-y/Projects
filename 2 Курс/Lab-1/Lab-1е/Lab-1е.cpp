#include <iostream>
#include "Matrix.h"
using namespace std;

void PrintArray(int** const arr, const int ROWS, const int COLLS) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			printf("%2.d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\b");
}

int main()
{
	Matrix X;
	int x, y;
	X.Fill();
	X.Print();
	X.FindMinXY(x, y);

	printf("\nMIN:\nx > %d\ny > %d\n\n", x, y);

	X.SetElemByPos(1, 6, 98);
	X.Print();

	cout << "\nElem by pos > " << X.GetElemByPos(1, 6);

	x = 8;
	y = 7;
	int** Arr = X.GetSubMatrix(1, 2, x, y);
	cout << "\n\nSubMatrix >\n";
	PrintArray(Arr, x, y);
	return 0;
}