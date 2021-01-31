#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <String>
#define zxc printf("|")
#define zxcf fout.width(1);fout << "|"

using namespace std;


int StrToInt(string b) {
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

struct Company
{
	string input = " ";
	string name = "Abc";
	char type = name[0];
	float area = 0;
	int workers = 0;

	void SetCompany(bool x = 0) {
		if (x)
		{
			for (int i = 0; i < 3; i++)
				name[i] = rand() % (122 - 65) + 65;

		
			type = rand() % (122 - 65) + 65;
			workers = rand() % 12700;
			area = (float)(rand() % 1270);
		}

		else {
			cout << "Company name > ";
			cin >> name;
			cout << "Company type > ";
			cin >> input; type = input[0];
			cout << "Company workers > ";
			cin >> input; workers = StrToInt(input);
			cout << "Company area > ";
			cin >> input; area = (float)StrToInt(input);
		}
	}

	void Print() {
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
	}
	void PrintFromFile(string filename, short position = 0) {
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{
			short i = 0;
			string Buff = "";
			for (i = 1; !fin.eof(); i++)
			{
				getline(fin, Buff);
				if (position == 0 || i == position)
					cout << Buff << "\n";
			}
			if (i <= position)
				cout << "Запись отсутствует\n";
		}
		else cout << "File is not open";
	}
	void CompanyToFile(string filename, short position = 0) {
		ofstream fout;

		if (position == 0)
			fout.open(filename);
		else if (position == 1)
			fout.open('1' + filename, ofstream::app);
		else if (position == 2) {
			fout.open(filename, ofstream::app);
			fout << "\n";
		}

		zxcf;
		fout.width(11);
		fout << name;
		zxcf;
		fout.width(7);
		fout << type;
		zxcf;
		fout.width(10);
		fout << workers;
		zxcf;
		fout.width(13);
		fout << area;
		zxcf;

		if (position == 1)
		{
			ifstream fin;
			fin.open(filename);

			if (fin.is_open())
			{
				string Buff = "";
				while (!fin.eof())
				{
					fout << "\n";
					getline(fin, Buff);
					fout << Buff;
				}
			}
			fin.close();
			fout.close();
			remove("Company.txt");
			position = rename("1Company.txt", "Company.txt");
		}
		else
			fout.close();

	}
};