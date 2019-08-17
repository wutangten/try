/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//
//  Created by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/

using namespace std;

class employee
{
public:
	employee();
	employee(string, int, double);
	employee(int, double);
	employee(string);

	void setData(string, int, double);
	void print() const;
	void updateSalary(double x);
	int getNumOfServiceYears() const;
	double getSalary() const;

private:
	string name;
	int numOfServiceYears;
	double salary;
};

employee::employee()
{
	name = "";
	numOfServiceYears = 0;
	salary = 0.0;
}

employee::employee(string betaName, int betaNumOfServices, double betaSalary)
{
	name = betaName;
	numOfServiceYears = betaNumOfServices;
	salary = betaSalary;
}

employee::employee(int cNumOfServices, double cSalary)
{
	name = "";
	numOfServiceYears = cNumOfServices;
	salary = cSalary;
}

void employee::setData(string a, int b, double c)
{
	name = a;
	numOfServiceYears = b;
	salary = c;
}

void employee::updateSalary(double x)
{
	salary = salary + x;
}

int employee::getNumOfServiceYears() const
{
	return numOfServiceYears;
}

double employee::getSalary() const
{
	return salary;
}

void employee::print() const
{
	cout << "Name:" << name << endl;
	cout << "Years in service:" << numOfServiceYears << endl;
	cout << "Salary:" << salary << endl;
}

int main()
{
	employee staff1;
	staff1.setData("Bruce", 3, 88888);
	staff1.print();
	cout<<endl;
	staff1.updateSalary(10000); /* Raise*/
	staff1.print();
}