#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <String>
#define zxc printf("|")

using namespace std;


int StrToInt(char* b) {
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
	char input[255]{};
	char name[255]{};
	char type = name[0];
	int workers = 0;
	float area = 0;
	void ConvertName() {
		int i;
		for (i = 0; name[i] != '\0'; i++) {}

		for (int j = 0; j < 13; j++)
		{
			name[12 - i + j] = name[j];
			if (j < (12 - i)) {
				name[j] = ' ';
			}
		}
	}
	void SetCompany(bool x = 0) {
		if (x)
		{
			for (int i = 0; i < rand() % 5; i++)
				name[i] = rand() % (122 - 65) + 65;
			type = rand() % (122 - 65) + 65;
			ConvertName();
			workers = rand() % 12700;
			area = (float)(rand() % 1270);
		}

		else {
			cout << "Company name > ";
			cin >> name;
			ConvertName();
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
	void PrintFromFile(char* filename, short& notes, int num = 0) {
		char line[60]{};
		char buff[50]{};
		short position = 0;
		FILE* file = fopen(filename, "r");

		for (int i = 0; i < num; i++)
		{
			fgets(line, 60, file);
		}
		for (int j = 0; j < 50; j++)
		{
			if (line[j] == '|')
			{
				position++;
				if (position == 1)
				{
					for (int k = 0; k <= 12; k++)
					{
						buff[k] = line[j + k];
					}
					for (int k = 0; k <= 12; k++)
					{
						name[k] = buff[k + 1];
					}
				}
				else if (position == 2) {

					type = line[j + 7];
				}
				else if (position == 3) {
					for (int k = 0; k <= 10; k++)
					{
						buff[k] = line[j + k];
					}
					workers = StrToInt(buff);
				}
				else if (position == 4) {
					for (int k = 0; k <= 13; k++)
					{
						if (line[j + k == ','])
						{

						}
						buff[k] = line[j + k];
					}
					area = StrToInt(buff);
				}
			}
		}
		Print();

	}
	void CompanyToFile(char* filename, short& notes, short mode = 0) {
		if (mode == 0)
		{
			FILE* file = fopen(filename, "a");
			if (notes != 0)
				fprintf(file, "\n");

			fprintf(file, "|");
			fprintf(file, "%s", name);
			fprintf(file, "|");
			fprintf(file, "%7.c", type);
			fprintf(file, "|");
			fprintf(file, "%10.d", workers);
			fprintf(file, "|");
			fprintf(file, "%13.3f", area);
			fprintf(file, "|");
			fclose(file);

			notes++;
		}
		else if (mode == 1)
		{
			FILE* newfile = fopen(1 + filename, "a");
			FILE* file = fopen(filename, "a");
			fprintf(file, "");
			fclose(file);

			fprintf(newfile, "|");
			fprintf(newfile, "%s", name);
			fprintf(newfile, "|");
			fprintf(newfile, "%7.c", type);
			fprintf(newfile, "|");
			fprintf(newfile, "%10.d", workers);
			fprintf(newfile, "|");
			fprintf(newfile, "%13.3f", area);
			fprintf(newfile, "|");
			if (notes != 0)
				fprintf(newfile, "\n");
			file = fopen(filename, "r");
			char line[255]{};

			for (int i = 0; i < notes; i++)
			{
				fgets(line, 255, file);
				fprintf(newfile, "%s", line);
			}
			fclose(file);
			fclose(newfile);
			remove(filename);
			rename(1 + filename, filename);
			remove(1 + filename);
			notes++;
		}
		else if (mode == 2) {
			FILE* file = fopen(filename, "w");
			fprintf(file, "|");
			fprintf(file, "%s", name);
			fprintf(file, "|");
			fprintf(file, "%7.c", type);
			fprintf(file, "|");
			fprintf(file, "%10.d", workers);
			fprintf(file, "|");
			fprintf(file, "%13.3f", area);
			fprintf(file, "|");
			fclose(file);

			notes = 1;
		}
	}

};