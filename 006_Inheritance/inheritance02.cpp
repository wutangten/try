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

class rectangle : parallelogram // Omitting the "public" in front of the 1st-class-name, makes it private inheritance.
{
public:
	void set_dimensions_rectangle(double, double);
	double get_area_rectangle() const;
	double get_perimeter_rectangle() const;
	/*
	These functions will be private in this
	class since we are doing a private inheritance

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
void rectangle::set_dimensions_rectangle(double l, double h)
{
	/*
	If you omitted the parallelogram:: from the statement
	below, the compiler would trace up the derivation tree
	and call parallelogram's set_dimensions function
	Note: the number of parameter is different(3 in the heading) and (2 in the function-call), but it will still work
	*/
	parallelogram::set_dimensions(l, h, h);
}

double rectangle::get_area_rectangle() const
{
	/*
	If you omitted the parallelogram:: from the statement
	below, the compiler would trace up the derivation tree
	and call parallelogram's get_area function
	*/
	return parallelogram::get_area();
}

double rectangle::get_perimeter_rectangle() const
{
	/*
	If you omitted the parallelogram:: from the statement
	below, the compiler would trace up the derivation tree
	and call parallelogram's get_area function
	*/
	return parallelogram::get_perimeter();
}

int main()
{
	parallelogram p;
	rectangle r;

	p.set_dimensions(3.0, 5.0, 5.4);
	r.set_dimensions_rectangle(4.0, 5.0);

	cout << "Parallelogram's area: " << p.get_area() << endl;
	cout << "Parallelogram's perimeter: " << p.get_perimeter() << endl;

	cout << "Rectangle's area: " << r.get_area_rectangle() << endl;
	cout << "Rectangle's perimeter: " << r.get_perimeter_rectangle() << endl;

	return 0;
}