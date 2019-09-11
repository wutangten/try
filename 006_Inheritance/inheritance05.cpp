#include <iostream>
using namespace std;

class parallelogram
{
public:
	void set_dimensions(double, double, double);
	double get_area() const;
	double get_perimeter() const;
private:
	double length;
	double height;
	double side_height;
};

class rectangle : protected parallelogram
{
public:
	void set_dimensions(double, double);
	double get_area() const; //Overriding parallelogram's get_area() function
	double get_perimeter() const; //Overriding parallelogram's get_perimeter() function
	/*
	These functions will be protected fields in this
	class since we are doing a protected inheritance and 
	these functions are public in parallelogram

	void set_dimensions(double, double, double);
	double get_area() const;
	double get_perimeter() const;
	
	-------------------------------------------------------
	
	Since these fields are private in the base
	class parallelogram, these will exist in this class
	but cannot be accessed directly

	double length;
	double height;
	double side_height;
	*/
};

/*-----------------------------------------------------------------
Parallelogram's member functions implementations
-----------------------------------------------------------------*/
void parallelogram::set_dimensions(double l, double h, double s)
{
	length = l;
	height = h;
	side_height = s;
}

double parallelogram::get_area() const
{
	return length * height;
}

double parallelogram::get_perimeter() const
{
	return 2 * (side_height + length);
}

/*-----------------------------------------------------------------
Rectangle's member functions implementations
-----------------------------------------------------------------*/
void rectangle::set_dimensions(double l, double h)
{
	/*
	Overriding parallelogram's set_dimensions function, we cannot omit
	parallelogram:: out of the statement below, the compiler will attempt
	to call rectangle's set_dimensions function instead of parallelogram's
	function if we omit parallelogram::
	*/
	parallelogram::set_dimensions(l, h, h);
}

double rectangle::get_area() const
{
	/*
	Overriding parallelogram's get_area function, we cannot omit
	parallelogram:: out of the statement below, the compiler will attempt
	to call rectangle's get_perimeter function instead of parallelogram's
	function if we omit parallelogram::
	*/
	return parallelogram::get_area();
}

double rectangle::get_perimeter() const
{
	/*
	Overriding parallelogram's get_perimeter function, we cannot omit
	parallelogram:: out of the statement below, the compiler will attempt
	to call rectangle's get_perimeter function instead of parallelogram's
	function if we omit parallelogram::
	*/
	return parallelogram::get_perimeter();
}

int main()
{
	parallelogram p;
	rectangle r;

	p.set_dimensions(3.0, 5.0, 5.4);
	r.set_dimensions(4.0, 5.0);

	cout << "Parallelogram's area: " << p.get_area() << endl;
	cout << "Parallelogram's perimeter: " << p.get_perimeter() << endl;

	cout << "Rectangle's area: " << r.get_area() << endl;
	cout << "Rectangle's perimeter: " << r.get_perimeter() << endl;
	
	return 0;
}
