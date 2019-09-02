/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//		//Type here...//
//
//  Updated by wutangten on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <fstream>  // file operation
#include <string>
using namespace std;

int main()
{
	string filename; // for user input.

	/* Step 1: decide which fstream (2 kinds) you want to use.
		1.1. ifstream: Stream class to read from files
		1.2. ostream: Stream class to write to files
	*/

	// First, we write something to a file.
	ofstream writefile; // "writefile" is just a variable name, it could be anything.

	/* Step 2: Open a file
		2.1. Directly open a file with open function from fstream-library.
		2.2. Ask the user to type the file name.
	*/

	// Method 2.1
	writefile.open("sample.txt");									//open the file directly.
	writefile << "This is the first line of this sample txt.file."; /* "<<" works the same with cin, which means writing the value from the right to the left. */
	writefile.close();												// save some run-time and memory.

	// Method 2.2
	do
	{
		cout << "Please  enter  the name of the file for writing on the file: ";
		cin >> filename;
		cout << "You've entered: " << filename << endl;
		cout << "The pointer of the string: " << filename.c_str() << endl
			 << "The writing part is completed successfully" << endl;

		writefile.open(filename.c_str()); // "c_str" is a pointer leads to the value in the variable (filename).
		if (writefile.is_open())
		{
			writefile << "This is the UPDATED line of this sample txt.file."; // overwrite the line with method 2.1.
		}
	} while (!writefile.is_open()); // repeat the prompt if the file is NOT found
	writefile.close();				// Needed, otherwise, can't perfrom reading below.

	/* Step 3: Read the thing we wrote into the file earlier with ofstream.
			3.1. Directly open a file with open function from fstream-library.
			3.2. Ask the user to type the file name.
	*/
	ifstream readfile; // "ifstream" is an object from library <fstream> for reading from a file.
	string str_holder;
	readfile.open("sample.txt"); //open the file directly.
	while (!readfile.eof())
	{
		getline(readfile, str_holder); //"getling(arg1, arg2)" is a built-in function performs reading the whole line.
	}
	cout << endl
		 << "The first time reading is completed and the string is: " << endl
		 << str_holder << endl;
	readfile.close(); // save some run-time and memory.

	do
	{
		cout << "Please  enter  the name of the file for 2nd reading: ";
		cin >> filename;
		cout << "You've entered: " << filename << endl;
		cout << "The pointer of the string: " << filename.c_str() << endl;

		readfile.open(filename.c_str()); // "c_str" is a pointer leads to the value in the variable (filename).
		if (!readfile.is_open())		 // Alert for wrong output.
		{
			cout << "Ok let’s try  this  again" << endl
				 << endl;
		}
		else
		{
			cout << "The file is successfully opened." << endl;
		}

	} while (!readfile.is_open()); // repeat the prompt if the file is NOT found
}