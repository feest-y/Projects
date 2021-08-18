#pragma once
using namespace std;
class Time {
	int hours;
	int minutes;
public:
	void Print() {
		cout.width(2);
		if (hours != 0)
			cout << hours;
		else cout << "0";

		cout << ":";
		cout.width(0);

		if (minutes < 10)
		{
			cout << "0";
			cout << minutes;
		}
		else if (minutes == 0)
			cout << "00";
		else cout << minutes;
		cout.width(0);
	}

	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int hours, int minutes) {
		this->hours = hours;
		this->minutes = minutes;
	}
	void SetHours(int h) {
		hours = h;
	}

	void SetMinutes(int m) {
		minutes = m;
	}
	int GetTime(){
		return hours * 100 + minutes;
	}
};

class Train
{
	string destination;
	int number;
	Time time;
public:
	Train() {
		destination = "none";
		number = 0;
	}
	Train(int number,string destination,int hours,int minutes) {
		this->number = number;
		this->destination = destination;
		time.SetHours(hours);
		time.SetMinutes(minutes);
	}
	Train(const Train& other) {
		this->destination = other.destination;
		this->number = other.number;
		this->time = other.time;
	}
	void AutoSet(int number, string destination, int hours, int minutes) {
		this->number = number;
		this->destination = destination;
		time.SetHours(hours);
		time.SetMinutes(minutes);
	}
	void Set() {
		int x;
		cout << "Number > ";
		cin >> number;
		cout << "Destination > ";
		cin >> destination;
		cout << "Time :\n\tHours > ";
		cin >> x;
		time.SetHours(x);
		cout << "\tMinutes > ";
		cin >> x;
		time.SetMinutes(x);
	}

	void Print() {
		cout << " | ";
		cout.width(5);
		cout << number;
		cout << " | ";
		cout.width(10);
		cout << destination;
		cout << " | ";
		time.Print();
		cout << " |\n";
		cout.width(0);
	}
	int GetTime() {
		return time.GetTime();
	}
	int GetNumber() {
		return number;
	}
	string GetDestination() {
		return destination;
	}
	void SetNumber(int n = 0) {
		number = n;
	}
};