#include <iostream>
using namespace std;

struct male
{
	int d_size;
	int nums_ball;
};
struct human
{
	int age;
	int height;
	int weight;
	male kit; // can't use this object(kit) independently in main, it exists within the struct only.
			  // order matters, must have the inner struct created before the outer struct.
};

int main()
{
	human person1;
	// now try to access the struct-member within another struct
	// Syntax: objectONE_name + '.' + objectTWO_name + '.' + member_of_objectTWO
	person1.kit.d_size = 30;
	cout << "D's size is: " << person1.kit.d_size << endl;

	// Understand the scope
	//kit.d_size = 1; // FAILED, the inner object created in the 2nd(outter struct) can't be used directly
	male kit;		// we have to make the object in the main
	kit.d_size = 1; // now it works
	cout << "D's size is: " << kit.d_size << endl;
	person1.kit.d_size = 88;
	cout << "D's size is: " << person1.kit.d_size << endl;
	kit.d_size = 99; // now it works
	cout << "D's size is: " << kit.d_size << endl;
}