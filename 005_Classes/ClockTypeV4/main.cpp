#include <iostream>
#include "clockType.h"
#include <cstdlib>
using namespace std;

int main()
{
	//creates an array of 10 clockType objects
	//each object is initialized using the
	//default constructor
	clockType clocks[10];

	for (int i = 0; i < 10; i++)
		cout << "clocks[" << i << "] = "
			 << clocks[i].getTime() << endl;

	//creates an array of 5 clockType objects
	//assigns an unamed clockType object to
	//each element of the array
	clockType moreClocks[] = { clockType(), 
			clockType(12), clockType(13, 45, 1),
			clockType(23, 56), clockType() };

	cout << endl;

	for (int i = 0; i < 5; i++)
		cout << "moreClocks[" << i << "] = "
			 << moreClocks[i].getTime() << endl;

	//creates an array of 5 clockType objects
	clockType evenMoreClocks[5];

	//reassigns each element to an new unamed clockTpe object
	for (int i = 0; i < 5; i++)
		evenMoreClocks[i] = clockType(rand() % 24, 
					rand() % 60, rand() % 60);

	cout << endl;

	for (int i = 0; i < 5; i++)
		cout << "evenMoreClocks[" << i << "] = "
			 << evenMoreClocks[i].getTime() << endl;

	return 0;
}