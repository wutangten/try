#include <iostream>
using namespace std;

class clockType
{
public:
	clockType();
	clockType(int);
	clockType(int, int);
	clockType(int, int, int);
	void incHr();
	void incMin();
	void incSec();
	string getTime() const;

private:
	int hr;
	int min;
	int sec;
};

//Default constructor, sets all fields to 0
clockType::clockType()
{
	hr = min = sec = 0;
}

//constructor that sets the hr field, min and sec to 0
clockType::clockType(int h)
{
	hr = h;
	hr = hr % 24; //ensures hr will not exceed 23

	min = sec = 0;
}

//constructor that sets the hr and min fields, sets sec to 0
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

//constructor that sets the hr, min, and sec fields
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

/******************************************
FUNCTION: incHr
PARAMETERS: None
RETURN: void
DESCIRPTION: increments the hr field of the 
object
******************************************/
void clockType::incHr()
{
	hr = (hr + 1) % 24;
}

/******************************************
FUNCTION: incMin
PARAMETERS: None
RETURN: void
DESCIRPTION: increments the min field of the
object and increments the minutes by one if needed
******************************************/
void clockType::incMin()
{
	min++;

	if (min == 60)
	{
		min = 0;
		incHr();
	}
}

/******************************************
FUNCTION: incSec
PARAMETERS: None
RETURN: void
DESCIRPTION: increments the sec field of the object
and increments the min field if needed
******************************************/
void clockType::incSec()
{
	sec++;

	if (sec == 60)
	{
		sec = 0;
		incMin();
	}
}

/******************************************
FUNCTION: getTime
PARAMETERS: None
RETURN: a string that represents the time, in the
form hr:min:sec
DESCIRPTION: concatenates the hr, min, and sec into
a string, uses the to_string() function which returns
the string equivalent of the number passed in
******************************************/
string clockType::getTime() const
{
	return to_string(hr) + ":" + to_string(min) + ":" + to_string(sec);
}

int main()
{
	clockType c1;			  //initializes c1 by calling default constructor
	clockType c2(12);		  //initializes c2 by calling the constructor that takes in one argument
	clockType c3(25, 61);	 //initializes c3 by calling the constructor that takes in two arguments
	clockType c4(13, 59, 62); //initializes c4 by calling the constructor that takes in three arguments

	c1.incHr();
	c2.incMin();
	c3.incSec();
	c4.incHr();

	//outputs each clock objects time, each object calls its getTime() function which returns
	//a string which is output since it's used in a cout output expression
	cout << "c1 = " << c1.getTime() << endl;
	cout << "c2 = " << c2.getTime() << endl;
	cout << "c3 = " << c3.getTime() << endl;
	cout << "c4 = " << c4.getTime() << endl;

	clockType c5; //initializes c5 by calling the default constructor

	c5 = c3; //since c5 and c3 are of the same time, this will copy all the data from c3 into c5

	cout << "c5 = " << c5.getTime() << endl;

	//initializes c6 by calling the copy constructor, clones c2 into c6 (similar to the assignment operator)
	//the copy constructor is always given and will always copy all the data from the object passed into
	//the constructor with the object that calls the constructor
	clockType c6(c2);

	cout << "c6 = " << c6.getTime() << endl;

	return 0;
}