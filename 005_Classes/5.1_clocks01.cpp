/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//
//  Created by brucederland on xx/xx/19.
//
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class clockType
{
public: // Public members can be used inside int main(), and usually have public functions instead of public variable.
	//always set the public member first
	// All public members are functions (you can tell by the parentheses in the end)
	// We can write the definition in the class scope or outside the class scope.

	// The first and only one function has its definition written in this class scope.
	void setTime(int h) // Sets the hr field for an object that calls the function
	{
		hr = h;
		hr = hr % 24; //prevents the hr field to contain anything over 23

		min = sec = 0;
	};

	// The definiton of the following functions is outside the class scope.
	void setTime(int h, int m); //function that sets the hr and min field for the object that calls the function
	void setTime(int h, int m, int s);
	void incHr();  // increments hr field of the object that called the function
	void incMin(); // increments min field of the object that called the function
	void incSec(); // increments sec field of the object that called the function

	//prints out the hr, min, and sec of the object that called the function
	void printTime() const // const in the end means it is a accessor function-member, it can only read the data(not changing).
	{
		// hr=0; // it can't compile becoz it is a accesser function.
		cout << hr << ":" << min << ":" << sec << endl;
	}

private: // usually would be variable
	int hr;
	int min;
	int sec;
};

int main()
{
	clockType c1, c2, c3; // Create class-variable(s) named c1, c2, c3;

	// Assign value to 1st variable 'c1'
	// c1.hr = 18;	// this line will fail bc it is a private member
	c3.setTime(18);		   //calls c3's setTime function (the version that has 1 int formal parameter)
	c2.setTime(17, 51);	//calls c2's setTime function (the version that has 2 int formal parameters)
	c1.setTime(17, 49, 3); //calls c1's setTime function (the version that has 3 int formal parameters)

	//prints each clock object
	c1.printTime();
	c2.printTime();
	c3.printTime();

	c1.incHr();  //increments c1's hr field
	c2.incMin(); //increments c2's min field
	c3.incSec(); //increments c3's sec field

	//prints each clock object
	c1.printTime();
	c2.printTime();
	c3.printTime();

	return 0;
}

/* 	Writing the function definition outside the class-scope
	Syntax: dataType of that function, name of the class, double-colon, name of the function (formal parameter list)
*/

void clockType::setTime(int h, int m) //function that sets the hr and min field for the object that calls the function
{
	int carry;

	hr = h % 24; //prevents the hr field to contain anything over 23

	carry = m / 60; //checks if m is over 60
	min = m % 60;   //prevents min from being over 60

	hr = hr + carry; //adds the amount to hr if min exceeds 60
	hr = hr % 24;

	sec = 0;
}

void clockType::setTime(int h, int m, int s) //function that sets the hr, min, and sec field for the object that calls the function
{
	int carry;

	hr = h % 24; //prevents hr from being over 23

	carry = m / 60; //checks if m exceeds 59
	min = m % 60;   //prevents min from begin over 59

	hr = (hr + carry) % 24; //adds the min overflow to hr

	//checks if s exceeds 59
	carry = s / 60;
	sec = s % 60;

	//adds the overflow to the min and hr field
	min = min + carry;

	carry = min / 60;
	min = min % 60;

	hr = (hr + carry) % 24;
}

void clockType::incHr() //function that increments hr field of the object that called the function
{
	hr = (hr + 1) % 24; // ensures its value will not exceed 23
}
void clockType::incMin() //function that increments min field of the object that called the function
{
	min++;

	if (min == 60) // ensures its value will not exceed 59
	{
		min = 0;
		incHr();
	}
}

void clockType::incSec() //function that increments sec field of the object that called the function
{
	sec++;

	if (sec == 60) // ensures its value will not exceed 59
	{
		sec = 0;
		incMin();
	}
}