/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//		//Type here...//
//		Note:
//			Dynamic array is good for big data set or unknown size of data.
//			Use static array if the data set is small.
//
//  Updated by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	int *dynArray;
	dynArray = new int[5]; // only 5 elements [][][][][]
	for (int i = 0; i < 5; i++)
	{
		dynArray[i] = rand() % 20; // [2][48][6][35][75]
	}

	// 2: assign values from one
	// step 1: declare a new pointer
	int *tmpArray;

	// step 2: allocate memory more to this new pointer
	/* 	Make it as dynamic array
		Syntax: pointer-variable = new dataType [index]
	*/
	tmpArray = new int[10]; // 10 elements: [][][][][][][][][][]

	// step 3: deep copy of the old dynArray into new array
	for (int i = 0; i < 5; i++)
	{
		tmpArray[i] = dynArray[i]; // [2][48][6][35][75][][][][][]
	}

	// step 4: decllocate old array
	delete dynArray;
	//delete[] dynArray;

	// step 5: assign old pointer to point the larger array
	dynArray = tmpArray;

	// step 6(optional)
	tmpArray = NULL;
}
