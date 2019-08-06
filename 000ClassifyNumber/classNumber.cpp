/************************************************************************
//
//  Filename: classNumber.cpp
//
//  Code Description: Determine the type of the number (even, odd, zeros) and count how many of them.
//
//  Created by brucederland on 7/26/19.
//
************************************************************************/

#include <iostream>
using namespace std;

const int length = 5;	/* how many input(number) to read in */
/* const int length = 20;	//for 20 numbers*/

void initialize(int &zeros, int &odds, int &evens); /* set these counter to zero */
void classifyNumber(int num1, int &zeros, int &odds, int &evens); /* (De)increment the counter */

int main(int argc, const char *argv[])
{
	/* Declare variables */
	int zeros, odds, evens;
	int num1;
	initialize(zeros, odds, evens);

	/* Prompt */
	cout << "Enter 5 integers" << endl;

	/* Don't use array in this program, so use for loop */
	for ( int i = 0; i < length; i++)
	{
		cin >> num1;
		classifyNumber(num1, zeros, odds, evens);
	}

	/* Output */
	cout << "You entered: " << num1 << endl;
	cout << "zeros: " << zeros << endl;
	cout << "odds: " << odds << endl;
	cout << "evens: " << evens << endl;

	return 0;
}

void initialize(int &zeros, int &odds, int &evens){
	zeros = 0;
	odds = 0;
	evens = 0;
}

void classifyNumber(int num1, int &zeros, int &odds, int &evens)
{
	if (num1 > 0)
	{
		if (num1 % 2 == 0)
		{
			evens++;
		}
		else
		{
			odds++;
		}
	}
	else
	{
		zeros++;
	}
}
