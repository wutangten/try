/************************************************************************

	Filename: 4.2_types_of_struct.cpp

	Code Description:
		This program decribles the three main usages of struct
		1. Struct(s) of array
		2. Array(s) of struct
		3. Struct(s) of struct

	Updated by wutangten on xx/xx/19.

************************************************************************/
#include <iostream> /* basic input output*/
#include <string>

using namespace std;

/* Struct Syntax */

const int arr_size = 10; // Must use const-type, otherwise, it won't compile.

struct info //1st struct: struct_of_arr
{
	// Member list
	string personality;
	// Note: we can't assign or initialize the variable within the struct definition.
	//string personality = "Good Person"; // this is illegal.

	// two common way to declare arrays within a struct.
	int age[10];			 // 1. define the size in the strcut definition.
	double net_worth[10];		 // 1. define the size in the strcut definition.
	string gender[arr_size]; // 2. Use a global variable(constant) to define the size.
};

struct person // 2nd struct: struct_of_struct
			  // Note: it is only a struct of a struct here. Although, we will make it array_of_struct eventually, which will perform in int main().
{
	info person1; // struct_of_struct, note it is only a struct of a struct here.
};

/*
	struct struct_of_struct
	{
		array_of_struct

	};*/

int main()
{
	// 1. Declaring the struct-variable name.
	info data1;
	info data2 = {"OK Person", 21, 353.300}; //We can initialize the variable while decalring the variable name.
	person person[10];					  // This makes that struct of a struct also a arrays of struct.
										  // Note: Must define the size while declaring the struct-variable name.

	data2.personality = "OK Person";
	data2.net_worth[0] = 333;
	data2.gender[0] = "OK Person";
	cout << "Person 2: " << data2.personality
		 << ", Age: " << data2.age[0]
		 << ", Net Worth: " << data2.net_worth[0]
		 << ", Gender: " << data2.gender[0] << endl;

	// First, access the arrays of struct, then get the arrays in that struct.
	// Accessing struct of a struct just use two dots.
	person[0].person1.age[0] = 21;
	person[0].person1.personality = "OK Person";
	cout << "Person 1: " << person[0].person1.personality
		 << ", Age: " << person[0].person1.age[0]
		 << ", Net Worth: " << person[0].person1.net_worth[0]
		 << ", Gender: " << person[0].person1.gender[0] << endl; // First, access the arrays of struct, then get the arrays in that struct.

	data1 = data2;
	person[0].person1.age[0] = 21;
	person[0].person1.personality = "Good Person Now";
	cout << "Person 1: " << person[0].person1.personality
		 << ", Age: " << person[0].person1.age[0]
		 << ", Net Worth: " << person[0].person1.net_worth[0]
		 << ", Gender: " << person[0].person1.gender[0] << endl; // First, access the arrays of struct, then get the arrays in that struct.

	person[0].person1.age[0] = 30;
	person[0].person1.personality = "Bad Person Now!!";
	cout << person[0].person1.personality << endl;
	cout << person[0].person1.age[0] << endl;
}