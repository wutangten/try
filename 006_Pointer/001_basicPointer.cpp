//
//  main.cpp
//  PointerPractice
//
//  Created by Kit tong on 2/20/19.
//  Copyright © 2019 Kit tong. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	// insert code here...
	int *pa, a = 10, b; //*pa means pointer of a

	cout << "The current value of a is " << &a << endl; //a current address

	pa = &a;	//assign a's address into pointer pa

	cout << "The current address of pa is " << pa << endl; //print out the a's address
	//cout<<&pa<<endl; this will be different address, DON't use it

	//Dereference:change a's value from 10 to 5
	*pa = 5; //*<pointer-name> is a value and <pointer-name> represents the address

	cout << "b is " << b << endl;
	cout << "Change pa value to 5" << endl;
	cout << "The current value of a is " << a << endl;
	cout << "A's address is " << &a << endl;
	cout << "Dereferenced pa is " << *pa << endl;
	cout << "The current value of pa is " << pa << endl;
	cout << "The current address of pa is " << &pa << endl;
	//you can chanege

	return 0;
}
