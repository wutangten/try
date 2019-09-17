#include "clockType.h"
#include <string>
using namespace std;

//default constructor, sets all fields to default values, i.e sets all fields to 0
clockType::clockType()
{
	hr = min = sec = 0;
}

//constructor that takes in 1 integer, sets the hr field with this value
clockType::clockType(int h)
{
	hr = h;
	hr = hr % 24; //ensures hr will not exceed 23

	min = sec = 0;
}

//constructor that takes in 2 integer, and sets hr with the first parameter and min with
//the second parameter
clockType::clockType(int h, int m)
{
	int carry;

	hr = h % 24; //checks for over 23

	//computes the overflow for the minute amount
	carry = m / 60;
	min = m % 60;

	//adds that amount to hr and makes sure hr is not over 23
	hr = hr + carry;
	hr = hr % 24;

	sec = 0;
}

//constructor that takes in 3 integer parameters, sets hr with the first parameter,
//sets min with the second parameter, and sets sec with the third parameter,
//also cleans up any overflows
clockType::clockType(int h, int m, int s)
{
	int carry;

	hr = h % 24;

	carry = m / 60;
	min = m % 60;

	hr = (hr + carry) % 24;

	carry = s / 60;
	sec = s % 60;

	min = min + carry;

	carry = min / 60;
	min = min % 60;

	hr = (hr + carry) % 24;
}

/*
FUNCTION NAME: incHr
PARAMETERS: None
RETURN TYPE: void
DESCRIPTION: increments the hr field by 1
and checks for overflow
*/
void clockType::incHr()
{
	hr = (hr + 1) % 24;
}

//increments min of the object that called the function, this function also calls the same
//object's incHr() function if min reaches 60 after incrementing the min field
void clockType::incMin()
{
	min++;

	if (min == 60)
	{
		min = 0;
		incHr();
	}
}

//increments sec of the object that called the function, this function also calls the same
//object's incMin() function if sec reaches 60 after incrementing the sec field
void clockType::incSec()
{
	sec++;

	if (sec == 60)
	{
		sec = 0;
		incMin();
	}
}

//returns the objects time info in the form, hr:min:sec as one long string
//the to_string() function is used that converts an integer into a string
//and concatenates all the strings into one large string
string clockType::getTime() const
{
	return to_string(hr) + ":" + to_string(min) + ":" + to_string(sec);
}
