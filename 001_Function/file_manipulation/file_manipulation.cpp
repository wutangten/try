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
using namespace std;

int main()
{
	string filename;
	ifstream infile; // object from library <fstream> for reading from a file
// infile.open("map.txt"); //open directly for testing
	do
	{
		cout << "RESIDENT  EVIL !!!!!  Please  enter  map: ";
		cin >> filename;
		infile.open(filename.c_str()); //attempts to open filestream
		if (!infile.is_open())
		{
			cout << "Ok let’s try  this  again" << endl
				 << endl;
		}
	} while (!infile.is_open()); // repeat the prompt if the file is NOT found
}