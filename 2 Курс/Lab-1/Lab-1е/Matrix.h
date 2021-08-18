#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Matrix
{
	static const int ROWS = 9, COLS = 9;
	int A[ROWS][COLS];


public:
	void Fill(short max = 99) {
		//srand(time(0));
		for (short i = 0; i < ROWS; i++)
		{
			for (short j = 0; j < COLS; j++)
				A[i][j] = rand() % (max - 1) + 1;
		}

	}

	void Print() {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("%2.d ", A[i][j]);
			}
			printf("\n");
		}
	}

	void FindMinXY(int& x, int& y) {
		short min = INT16_MAX;
		for (short i = 0; i < ROWS; i++)
		{
			for (short j = 0; j < COLS; j++)
			{
				if (A[i][j] < min)
				{
					min = A[i][j];
					x = j;
					y = i;
				}
			}
		}
	}

	short GetElemByPos(short x, short y) {
		if (x >= 9 || y >= 9) {
			cout << "\nInvalid position\n";
			return false;
		}
		return A[x][y];
	}

	bool SetElemByPos(short x, short y, short value) {
		if (x >= 9 || y >= 9) {
			cout << "\nInvalid position\n";
			return false;
		}
		A[x][y] = value;
		return true;
	}

	int** GetSubMatrix(short x, short y, short newrows, short newcols) {
		/*if (x + newrows >= 9 || y + newcols >= 9) {
			cout << "\nUnable to create SubMatrix\n";
			return nullptr;
		}*/

		int** Arr = new int* [newrows];

		for (int i = 0; i < newrows; i++)
			Arr[i] = new int[newcols];

		for (short i = 0; i < newrows; i++) {
			for (short j = 0; j < newcols; j++) {
				Arr[i][j] = A[i + y][j + x];
			}
		}
		return Arr;
	}

	Matrix() {
		for (short i = 0; i < ROWS; i++) {
			for (short j = 0; j < COLS; j++)
				A[i][j] = i * 10 + j;
		}
	}
};