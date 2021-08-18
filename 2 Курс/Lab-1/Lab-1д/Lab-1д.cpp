#include <iostream>
#include "Train.h"
using namespace std;

void Sort(Train* A, int size) {
	Train B(A[0]);
	bool isLower;
	int position = 0;
	for (int j = 0; j < size; j++) {
		isLower = false;
		for (int i = j; i < size; i++) {
			if (A[i].GetNumber() <= B.GetNumber()) {
				B = A[i];
				isLower = true;
				position = i;
			}
		}
		if (isLower) {
			A[position] = A[j];
			A[j] = B;
			B.AutoSet(INT32_MAX, "~", 99999, 999999);
		}
	}
}



void SortByDestination(Train* A, int size) {
	Train B;
	B.AutoSet(INT32_MAX, "~", 99999, 999999);
	bool isLower;
	int position = 0;

	for (int j = 0; j < size; j++) {
		isLower = false;
		for (int i = j; i < size; i++) {
			if (A[i].GetDestination()[0] == B.GetDestination()[0]) {
				if (A[i].GetDestination()[1] == B.GetDestination()[1]) {
					if (A[i].GetDestination()[2] == B.GetDestination()[2]) {
						if (A[i].GetDestination()[3] == B.GetDestination()[3]) {
							if (A[i].GetTime() <= B.GetTime()) {
								B = A[i];
								isLower = true;
								position = i;

							}
						}
						else if (A[i].GetDestination()[3] < B.GetDestination()[3]) {
							B = A[i];
							isLower = true;
							position = i;
						}
					}
					else if (A[i].GetDestination()[2] < B.GetDestination()[2]) {
						B = A[i];
						isLower = true;
						position = i;
					}
				}

				else if (A[i].GetDestination()[1] < B.GetDestination()[1]) {
					B = A[i];
					isLower = true;
					position = i;
				}
			}
			else if (A[i].GetDestination()[0] < B.GetDestination()[0]) {
				B = A[i];
				isLower = true;
				position = i;
			}

		}
		if (isLower) {
			A[position] = A[j];
			A[j] = B;
			B.AutoSet(INT32_MAX,"~",99999,999999);
		}
	}

}
int main()
{
	const int amount = 5;
	Train A[amount];
	cout << "Set ? (y/n) > ";
	char x;
	cin >> x;

	if (x == 'y')
	{
		for (int i = 0; i < amount; i++) {
			printf("Train %d:\n", i + 1);
			A[i].Set();
		}
	}
	else {
		A[0].AutoSet(999, "Kharkiv", 19, 20);
		A[1].AutoSet(99, "Kharkiv", 0, 20);
		A[2].AutoSet(9, "Karkiv", 20, 20);
		A[3].AutoSet(29, "Kiev", 6, 20);
		A[4].AutoSet(30, "Kiev", 3, 20);
	}

	system("cls");
	for (int i = 0; i < amount; i++) {
		printf("Train %d:", i + 1);
		A[i].Print();
	}
	cout.width(0);
	cout << "\nTrain number > ";
	int number;
	cin >> number;

	cout << "---------------------------------------\n";
	for (int i = 0; i < amount; i++) {
		if (A[i].GetNumber() == number)
			A[i].Print();
	}
	cout << "---------------------------------------\n";

	Sort(A, amount);
	cout << "\nSorted >\n";
	for (int i = 0; i < amount; i++)
		A[i].Print();


	SortByDestination(A, amount);
	cout << "\nSorted by destination >\n";
	for (int i = 0; i < amount; i++)
		A[i].Print();


	return 0;
}