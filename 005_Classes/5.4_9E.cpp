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

class temp
{
public:
	void print() const;
	void setDesription(string);
	void setX(double);
	string getDescription();
	double getX();
	temp();
	temp(string, double);

private:
	string description;
	double x;
};

class derived : public temp
{
public:
	void print();
	void setZ(double);
	double getZ();
	double power() const;
	derived();
	dervied(string, double, double);

private:
	double x;
};
int main()
{
	/* Code */
}