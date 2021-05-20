#include <iostream>
#include <ctime>
using namespace std;

class Dog {
	string name;
	int weight, age;
public:
	void SetName(string name) {
		this->name = name;
	}
	void SetAge(int age) {
		this->age = age;
	}
	void SetWeight(int weight) {
		this->weight = weight;
	}
	string GetName() {
		return name;
	}
	int GetAge() {
		return age;
	}
	int GetWeight() {
		return weight;
	}
	void Print() {
		cout << "\nName > " << name;
		cout << "\nWeight > " << weight;
		cout << "\nAge > " << age << endl;
	}
	Dog() {
		name = "Sharik";
		weight = 10;
		age = 10;
	}
	Dog(string name, int weight, int age) {
		this->name = name;
		this->weight = weight;
		this->age = age;
	}
};

class Master {
	string FIO[3]{};
	const int clubID = 123;
	Dog* dog = nullptr;
	int DogAmmount = 0;
	static int c;
public:

	void SetFIO(string Name, string surName, string lastName) {
		FIO[0] = Name;
		FIO[1] = surName;
		FIO[2] = lastName;
	}
	bool SetDog(string name, int age, int weight, int number = 0) {
		if (number >= DogAmmount)
		{
			cout << "Invalid Dog Number.\n";
			system("pause");
			return false;
		}

		dog[number].SetAge(age);
		dog[number].SetName(name);
		dog[number].SetWeight(weight);
		return true;
	}
	void SetAmountOfDogs(int n = 1) {
		Dog* Buff = new Dog[n];

		for (int i = 0; i < DogAmmount; i++)
			Buff[i].SetName(dog[i].GetName());

		if (dog != nullptr)
		{
			delete[] dog;
		}
		dog = new Dog[n]();
		for (int i = 0; i < DogAmmount; i++)
			dog[i].SetName(Buff[i].GetName());

		DogAmmount = n;
		delete[] Buff;
	}

	void Print() {
		cout << "\nFIO > " << FIO[0] << " " << FIO[1] << " " << FIO[2];
		cout << "\nClubID > " << clubID;
		cout << "\nCount > " << c;
		cout << "\nDogs: \n";
		for (int i = 0; i < DogAmmount; i++)
		{
			cout << endl << i + 1 << ".";
			dog[i].Print();
		}
	}

	Master(string Name, string surName, string lastName, int DogAmmount = 1) {
		FIO[0] = Name;
		FIO[1] = surName;
		FIO[2] = lastName;
		dog = new Dog[DogAmmount]();
		SetAmountOfDogs(DogAmmount);
		c++;
	}
	Master() {
		FIO[0] = "Albert";
		FIO[1] = "Shulz";
		FIO[2] = "Markovich";
		dog = new Dog[1];
		DogAmmount = 1;
		c++;
	}
	~Master() {
		c--;
		delete[] dog;
	}
};
int Master::c = 0;
int main()
{
	Master A("Ivan", "Ivanov", "Ivanovich", 2);
	Master B("Putler", "Shulz", "Markovich", 1);

	A.SetDog("Tori", 1, 2);
	A.SetDog("Bobik", 10, 20, 1);

	//B.SetDog("Inter",1,11);

	A.Print();
	cout << "____________________________\n";
	B.Print();

	return 0;
}