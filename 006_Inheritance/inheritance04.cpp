#include <iostream>
using namespace std;

class parallelogram
{
public:
	void set_dimensions(double, double, double);
	double get_area() const;
	double get_perimeter() const;
protected:
	double length;
	double height;
private:
	double side_height;
};

class rectangle : parallelogram
{
public:
	void set_dimensions(double, double);
	double get_area() const;
	double get_perimeter() const;

	/*
	Since we are doing a private inheritance, the public
	fields in parallelogram will be private fields in
	rectangle class

	void set_dimensions(double, double, double);
	double get_area() const;
	double get_perimeter() const;

	------------------------------------------------------
	Since length and height fields in parallelogram are protected
	and we're doing a private inheritance, they will be private
	members in rectangle so they can be directly accessed as if
	they are just regular private members

	-------------------------------------------------------
	The field side_height is private in parallelogram so this
	field exists in rectangle but cannot be directly accessed 
	in this class
	*/
} ;

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
	return 2 * (length + side_height);
}

/*-----------------------------------------------------------------
Rectangle's member functions implementations
-----------------------------------------------------------------*/
void rectangle::set_dimensions(double l, double h)
{
	/*
	We could use parallelogram's set_dimensions function like before
	but since length and height were declared protected in the
	parallelogram class, we can directly access the fields so we don't NEED
	to use parallelogram's set_dimensions function but we can if we want to
	*/
	length = l;
	height = h;
}

double rectangle::get_area() const
{
	/*
	We could use parallelogram's get_area function like before
	but since length and height were declared protected in the
	parallelogram class, we can directly access the fields so we don't NEED
	to use parallelogram's get_area function but we can if we want to
	*/
	return length * height;
}

double rectangle::get_perimeter() const
{
	/*
	We could use parallelogram's get_perimeter function like before
	but since length and height were declared protected in the
	parallelogram class, we can directly access the fields so we don't NEED
	to use parallelogram's get_perimeter function but we can if we want to
	*/
	return 2 * (length + height);
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