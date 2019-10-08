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
	string text;
	// char* textArray[text.length()];	// static array

	char *textArray; /* Initialize pointer variable */

	/*
		Make it as dynamic array
		Syntax: pointer-variable = new dataType [index]
	*/
	textArray = new char[text.length()];	// make the pointer as dynamic array

	cout << "Enter a string" << endl;
	cin >> text;

	// deep copy: copy only the data
	for (int i = 0; i < text.length(); i++)
	{
		textArray[i] = text[i];		// copy data from normal array into dynamic array
	}

	cout << endl;
	cout << "Converted: ";
	for (int i = 0; i < text.length(); i++)
	{
		//cout << toupper(textArray[i]);	/* this will print number only */
		cout << (char)toupper(textArray[i]); /* 1st correct way */
		//putchar(toupper(textArray[i]));			/* 2nd correct way*/
	}

	delete[] textArray; /* avoid memory leak, deallocate or free the memory */
}
