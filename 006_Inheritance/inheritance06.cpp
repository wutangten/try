#include <iostream>
using namespace std;

class rectangle
{
public:
	rectangle();
	rectangle(double, double);
	double get_area() const;
	double get_perimeter() const;
private:
	double length;
	double height;
};

class square : rectangle
{
public:
	square();
	square(double);
	double get_area() const; //overriding rectangle's get_area()
	double get_perimeter() const; //overrding rectangle's get_perimeter()

	/*
	We inherit all of the contents of rectangle class.
	The public fields in the rectangle class will be
	private fields in the square class since this is 
	a private inheritance.

	rectangle();
	rectangle(double, double);
	double get_area() const;
	double get_perimeter() const;	


	-----------------------------------------------------
	As before, the private fields in the rectangle class
	will not be directly accessible inside the square class
	regardless of the type on inheritance we use, but the fields
	still exist in the class

	double length;
	double height;
	*/
};

/*-----------------------------------------------------------------
Rectangle's member functions implementations
-----------------------------------------------------------------*/
rectangle::rectangle()
{
	length = 1.0;
	height = 1.0;
}

rectangle::rectangle(double l, double h)
{
	length = l;
	height = h;
}

double rectangle::get_area() const
{
	return length * height;
}

double rectangle::get_perimeter() const
{
	return 2 * (length + height);
}

/*-----------------------------------------------------------------
Square's member functions implementations
-----------------------------------------------------------------*/
square::square() : rectangle()
{
/*
	We don't need to set anything here (we can't set anything here)
	but we called the base class rectangle's constructor here which
	will set the set the length and height
*/
}

square::square(double l) : rectangle(l ,l)
{
/*
	We don't need to set anything here (we can't set anything here)
	but we called the base class rectangle's constructor here which
	will set the set the length and height again
*/
}

double square::get_area() const
{
	/*
	Calling rectangle's get_area() function, we must use the scope resolution
	operator :: otherwise it will attempt to call square's get_area() function
	which would cause the program to crash
	*/
	return rectangle::get_area();
}

double square::get_perimeter() const
{
	/*
	Calling rectangle's get_perimeter() function, we must use the scope resolution
	operator :: otherwise it will attempt to call square's get_perimeter() function
	which would cause the program to crash
	*/
	return rectangle::get_perimeter();
}

int main()
{
	rectangle r(4.0, 5.0);
	square s(4.0);

	rectangle r0;
	square s0;

	cout << r.get_perimeter() << endl;
	cout << r.get_area() << endl;

	cout << s.get_perimeter() << endl;
	cout << s.get_area() << endl;

	cout << r0.get_perimeter() << endl;
	cout << r0.get_area() << endl;

	cout << s0.get_perimeter() << endl;
	cout << s0.get_area() << endl;

	return 0;
}