/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//		//Type here...//
//
//  Updated by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/

using namespace std;

class clockType
{
private:
	int hr;
	int min;
	int sec;

public:
	void setTime(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	};
	void incHr();
	void incMin();
};

int main()
{
	clockType c1; // Create a variable named c1;

	// Assign value to 1st variable 'c1'
	// c1.hr = 18;	// this line will fail bc it is a private member
	c1.setTime(18, 25, 2);

	// Assign value to 2nd variable 'c2'
	clockType c2;
	c2.setTime(18, 45, 0);
}