#pragma once
//#include "Functions.h"
//using namespace System;
//using namespace System::Windows::Forms;

#include <ctime>
#include <cstdlib>
#include <cstdio>

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

	void ToFile(bool isParent = true, bool isParam = false) {
		if (isParent) {
			char filename[20]{ 'P','a','r','e','n','t','.','t','x','t','\0' };
			FILE* file = fopen(filename, "w");
			for (int i = 0; i < rowsP; i++)
			{
				if (i > 0)
					fprintf(file, "\n");
				for (int j = 0; j < colsP; j++)
				{
					if (j > 0)
						fprintf(file, " ");
					fprintf(file, "%d", Parent[i][j]);
				}
			}
			fprintf(file, "\n");
			fclose(file);
		}
		else {
			char filename[20]{ 'T','r','a','n','s','f','o','r','m','e','d','.','t','x','t','\0' };
			FILE* file = fopen(filename, "w");
			for (int i = 0; i < rowsT; i++)
			{
				if (i > 0)
					fprintf(file, "\n");
				for (int j = 0; j < colsT; j++)
				{
					if (j > 0)
						fprintf(file, " ");
					fprintf(file, "%d", Transformed[i][j]);
				}
			}
			fprintf(file, "\n");
			fclose(file);

		}

		if (isParam)
		{
			char filename[20]{ 'P','a','r','a','m','e','t','e','r','s','.','t','x','t','\0' };
			FILE* file = fopen(filename, "w");
			fprintf(file, "Average   > %f\n", avg);
			fprintf(file, "Perimeter > %d\n", sumP);
			fprintf(file, "SumOnDiag > %d", sumD);
			fclose(file);
		}
	}
	bool FromFile(bool isParent = true) {
		char filename[20]{ 'P','a','r','e','n','t','.','t','x','t','\0' };
		FILE* file = fopen(filename, "r");

		char buff = '0';
		int i = 0, j = 0, num = 0, maxj = 0, maxi = 0, r = 1;
		int Arr[15][15]{};
		while (fscanf(file, "%c", &buff) == 1)
		{
			if (buff >= 48 && buff <= 57)
			{
				while (buff != ' ' && (buff >= 48 && buff <= 57) && r == 1)
				{
					num *= 10;
					num += buff - 48;
					r = fscanf(file, "%c", &buff);
				}
				Arr[i][j] = num;
				num = 0;
				j++;
			}
			if (buff == '\n')
			{
				if (j > maxj)
					maxj = j;

				j = 0;
				i++;
			}
		}
		fclose(file);
		maxi = i;
		ChangeSize(maxi, maxj);
		for (i = 0; i < maxi; i++)
		{
			for (j = 0; j < maxj; j++)
			{
				Parent[i][j] = Arr[i][j];
			}
		}

		return true;
	}
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
};