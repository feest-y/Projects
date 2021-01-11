#include "../../Header/Header.h"


int main()
{
	Standart();

	int size = InputSize(),n=0;
	int* Arr = new int[size];
	
	FillArray(Arr,size,-100,100);
	cout << "Arr random numbers >\n";
	PrintArray(Arr,size);
	
	DescendingSort(Arr,size);
	cout << "Arr sorted >\n";
	PrintArray(Arr,size);
	
	n = CountNegativeDigits(Arr,size);
	int* Brr = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		Brr[i] = Arr[size-n+i];
	}
	cout << "New Brr initialized >\n";
	PrintArray(Brr,n);
	
	DeleteArray(Arr);
	DeleteArray(Brr);
	r0;
}
