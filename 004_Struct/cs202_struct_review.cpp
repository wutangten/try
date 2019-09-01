/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//		//Type here...//
//
//  Updated by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <fstream>
#include <string>

using namespace std;

struct personType
{
	string name;
	int age;
	double salary;
};

int main()
{
	personType people[5];
	ifstream infile;
	int peopleCounter;
	infile.open("textName.txt");

	while (!infile.eof())
	{
		infile >> people[peopleCounter].name >> people[peopleCounter].age >> people[peopleCounter].salary;
		peopleCounter++;
	}
}