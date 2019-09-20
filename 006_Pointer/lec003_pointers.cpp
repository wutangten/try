#include <iostream> /* basic input output*/
#include <string>
using namespace std;
int main()
{
	double *ptr1;
	double *ptr2;

	// allocating
	ptr1 = new double;
	*ptr1 = 2.82;

	// make ptr1 and ptr2 the same
	cout << ptr1 << endl
		 << ptr2 << endl;
	cout << *ptr1 << endl
		 << *ptr2 << endl;

	// make ptr1 and ptr2 the same
	ptr2 = ptr1; // shallow copy: both point to the same address now.
	cout << ptr1 << endl
		 << ptr2 << endl;
	cout << *ptr1 << endl
		 << *ptr2 << endl;

	// Both pointers(varialbe) will be change
	*ptr2 = 3.14; // Both pointers(variable) will be changed
	cout << ptr1 << endl
		 << ptr2 << endl;
	cout << *ptr1 << endl
		 << *ptr2 << endl;
}