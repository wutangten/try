#include <iostream> /* basic input output*/
#include <string>
using namespace std;
int main()
{
	int *ptr1;
	int *ptr2;
	ptr1 = new int; // allocates 4 byte memory
	// Syntax: new <dataType>: allocates the number of the memory

	*ptr1 = 15; // deference for regular data(value)
	cout << "Point 1's value:" << *ptr1 << endl;
	cout << "Point 1's address:" << ptr1 << endl;
	cout << "Point 1's value:" << *ptr2 << endl;
	cout << "Point 2's address:" << ptr2 << endl;

	ptr1 = ptr2; // ptr1 has the address of ptr2
	cout << "After assigning the address of ptr2 to ptr1" << endl;
	cout << "Point 1's value:" << *ptr1 << endl;
	cout << "Point 1's address:" << ptr1 << endl;
	cout << "Point 1's value:" << *ptr2 << endl;
	cout << "Point 2's address:" << ptr2 << endl;

	ptr1 = new int; // find memory has not allocated
	cout << *ptr1 << endl;
	cout << ptr1 << endl;

	/*	// Example of memory leak
		while(true){
			ptr1 = new int;
			*ptr1 = rand()%100+1;
		}
	*/
	cout << "2nd example" << endl;
	int *ptr3;
	ptr3 = new int;
	*ptr3 = 22;
	// deallocate/recycle the memory that the pointer points to
	delete ptr3; // now the memory linked with the pointer(ptr3) can be allocated again
	//cout << *ptr3 << endl; // FAILED: dangling pointer
	ptr3 = new int;
	//ptr3=NULL;
	//ptr3=nullptr;
	*ptr3 = 33;
}