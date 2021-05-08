#pragma once
#include "Functions.h"
class Matrix
{
	int** Parent = nullptr;
	int** Transformed = nullptr;
	int rows, cols;

	float avg;
	int sumP;
	int sumD;
	void ParentToTransformed() {
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < cols; j++)
				Transformed[i][j] = Parent[i][j];
		}
	}
public:


	//Alg
	void EvenToInteger(int integer = -999) {
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < cols; j++)
			{
				if (Parent[i][j] % 2 == 0)
					Transformed[i][j] = integer;
				else
					Transformed[i][j] = Parent[i][j];
			}
		}
	}
	void TurnLeft() {
		ParentToTransformed();
		TurnArrayLeft(Transformed);
	}
	void Fill() {
		FillArray(Transformed, rows, cols);
	}

	//Parameters
	void CountAverage() {
		int sum = 0;
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < cols; j++)
				sum += Transformed[i][j];
		}

		avg = sum / (rows * cols);
	}
	void CountSumP() {
		sumP = 0;
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < cols; j++)
			{
				if (i == 0 || i == rows)
					sumP += Transformed[i][j];
				else if (j == 0 || j == cols)
					sumP += Transformed[i][j];
			}
		}
	}
	void CountSumD() {
		sumD = 0;
		for (short i = 0; i < cols; i++)
			sumD += Transformed[i][i];
	}

	Matrix(const int rows, const int cols) {
		this->rows = rows;
		this->cols = cols;
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
		rows = cols = 0;
		Parent = nullptr;
		Transformed = nullptr;
	}
	~Matrix() {
		if (Parent != nullptr)
		{
			for (int i = 0; i < rows; i++)
				delete[] Parent[i];
			delete[] Parent;
		}

		if (Transformed != nullptr)
		{
			for (int i = 0; i < rows; i++)
				delete[] Transformed[i];
			delete[] Transformed;
		}
	}
	void Print(bool isParent = true) {
		if (isParent)
			PrintArray(Parent, rows, cols);
		else
			PrintArray(Transformed, rows, cols);
	}
};