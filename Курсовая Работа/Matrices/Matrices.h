#pragma once
//#include "Functions.h"

#include <ctime>
#include <cstdlib>
#include <cstdio>

//using namespace System;
//using namespace System::Windows::Forms;

void TurnArrayLeft(int** arr, const int ROWS = 9, const int COLLS = 9) {
	int Buffer[9][9] = {};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			Buffer[i][j] = arr[j][ROWS - i - 1];
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			arr[i][j] = Buffer[i][j];
		}
	}
}

void FillArray(int** const arr, const int ROWS, const int COLLS, const int min = 1, const int max = 99) {
	srand(time(NULL));
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			arr[i][j] = rand() % (max - min) + min;
		}
	}
}

void PrintArray(int** const arr, const int ROWS, const int COLLS) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLS; j++) {
			if (arr[i][j] != 0)
				printf("%2.d ", arr[i][j]);
			else
				printf("%2.c ", '0');
		}
		printf("\n");
	}
	printf("\b");
}

class Matrix
{
	void ParentToTransformed() {
		if (!IsEqual() || rowsT == 0 || colsT == 0)
			ChangeSize(rowsP, colsP, false);


		for (short i = 0; i < rowsT; i++)
		{
			for (short j = 0; j < colsT; j++)
				Transformed[i][j] = Parent[i][j];
		}
	}
	bool IsEqual() {
		if (rowsP != rowsT || colsP != colsT)
			return false;
		else return true;
	}

public:
	float avg;
	int sumP;
	int sumD;
	int rowsP, colsP;
	int rowsT, colsT;
	int** Parent = nullptr;
	int** Transformed = nullptr;
	void ChangeSize(int newrows, int newcols, bool isParent = true) {
		if (isParent)
		{
			if (Parent != nullptr)
			{
				for (int i = 0; i < this->rowsP; i++)
					delete[] Parent[i];
				delete[] Parent;
			}

			this->rowsP = newrows;
			this->colsP = newcols;
			Parent = new int* [newrows];

			for (int i = 0; i < newrows; i++) {
				Parent[i] = new int[newcols] {};
			}
		}
		else {
			if (Transformed != nullptr)
			{
				for (int i = 0; i < this->rowsT; i++)
					delete[] Transformed[i];
				delete[] Transformed;
			}

			this->rowsT = newrows;
			this->colsT = newcols;
			Transformed = new int* [newrows];

			for (int i = 0; i < newrows; i++) {
				Transformed[i] = new int[newcols] {};
			}
		}
	}
	//Algorithms
	void EvenToInteger(int integer = -999) {
		if (!IsEqual())
			ChangeSize(colsP, rowsP, false);

		for (short i = 0; i < rowsT; i++)
		{
			for (short j = 0; j < colsT; j++)
			{
				if (Parent[i][j] % 2 == 0)
					Transformed[i][j] = integer;
				else
					Transformed[i][j] = Parent[i][j];
			}
		}
	}
	void Flip() {
		ParentToTransformed();

		int Buffer[9][9] = {};

		for (int i = 0; i < rowsT; i++)
		{
			for (int j = 0; j < colsT; j++)
			{
				//Buffer[i][j] = Transformed[j][rowsT - i - 1];
				Buffer[i][j] = Transformed[j][i];
			}
		}

		if (rowsT != colsT)
			ChangeSize(colsT, rowsT, false);


		for (int i = 0; i < rowsT; i++)
		{
			for (int j = 0; j < colsT; j++)
			{
				Transformed[i][j] = Buffer[i][j];
			}
		}



	}
	void x2() {
		if (Transformed == nullptr)
			ParentToTransformed();

		for (int i = 0; i < rowsT; i++)
		{
			for (int j = 0; j < colsT; j++)
			{
				Transformed[i][j] *= 2;
			}
		}

	}
	void Fill(bool isParent = false) {
		if (isParent)
		{
			FillArray(Parent, rowsP, colsP);
		}
		else {

			if (!IsEqual())
				ChangeSize(rowsP, colsP, false);

			FillArray(Transformed, rowsT, colsT);
		}
	}

	//Parameters
	void CountAverage() {
		int sum = 0;
		for (short i = 0; i < rowsT; i++)
		{
			for (short j = 0; j < colsT; j++)
				sum += Transformed[i][j];
		}

		avg = sum / (rowsT * colsT);
	}
	void CountSumP() {
		sumP = 0;
		for (short i = 0; i < rowsT; i++)
		{
			for (short j = 0; j < colsT; j++)
			{
				if (i == 0 || i == rowsT)
					sumP += Transformed[i][j];
				else if (j == 0 || j == colsT)
					sumP += Transformed[i][j];
			}
		}
	}
	void CountSumD() {
		sumD = 0;
		for (short i = 0; i < colsT; i++)
			sumD += Transformed[i][i];
	}

	Matrix(const int rows, const int cols) {
		this->rowsP = this->rowsT = rows;
		this->colsP = this->colsT = cols;
		Parent = new int* [rows];
		Transformed = new int* [rows];

		for (int i = 0; i < rows; i++) {
			Parent[i] = new int[cols] {};
			Transformed[i] = new int[cols] {};
		}

		avg = 0;
		sumP = 0;
		sumD = 0;
	}
	Matrix() {
		rowsP = colsP = colsT = rowsT = 0;
		Parent = nullptr;
		Transformed = nullptr;
	}
	~Matrix() {
		if (Parent != nullptr)
		{
			for (int i = 0; i < rowsP; i++)
				delete[] Parent[i];
			delete[] Parent;
		}

		if (Transformed != nullptr)
		{
			for (int i = 0; i < rowsT; i++)
				delete[] Transformed[i];
			delete[] Transformed;
		}
	}
	void Print(bool isParent = true) {
		if (isParent)
			PrintArray(Parent, rowsP, colsP);
		else
			PrintArray(Transformed, rowsT, colsT);
	}
};