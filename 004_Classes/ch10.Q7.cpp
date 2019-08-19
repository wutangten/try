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

int smallestIndex(int num[]);

class bagType
{
public:
	void set(string, double, double, double, double);
	void print() const;
	bagType();
	bagType(string, double, double, double, double);

private:
	string style;
	double l;
	double w;
	double h;
	double price;
};

bagType::bagType()
{
	style = "";
	l = 0.0;
	w = 0.0;
	h = 0.0;
	price = 0.0;
}

void bagType::set(string name, double length, double width, double height, double cost)
{
	style = name;
	l = length;
	w = width;
	h = height;
	price = cost;
}

void bagType::print() const
{
	cout << "Style: " << style << endl;
	cout << "Length: " << l << endl;
	cout << "Width: " << w << endl;
	cout << "Height: " << h << endl;
	cout << "Cost: " << price << endl;
}

int main()
{
	/* Code */
	bagType newBag;
	newBag.print();

	bagType tempBag;
	//temp("backPack", 15, 8, 20, 49.99);
	tempBag.set("backPack", 15, 8, 20, 49.99);
}