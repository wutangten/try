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

	char* textArray;	/* Initialize pointer variable */

	textArray = new char[text.length()]; /* Make it as dynamic array */

	cout << "Enter a string" << endl;
	cin >> text;

	for (int i = 0; i < text.length(); i++)
	{
		textArray[i] = text[i];
	}

	cout << endl;
	cout << "Converted: ";
	for (int i = 0; i < text.length(); i++)
	{
		//cout << toupper(textArray[i]);	/* this will print number only */
		cout << (char)toupper(textArray[i]);	/* 1st correct way */
		//putchar(toupper(textArray[i]));			/* 2nd correct way*/
	}

	delete []textArray;		/* Free the memory */
}
