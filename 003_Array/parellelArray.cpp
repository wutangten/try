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

int main()
{
	ifstream infile;
	string name[5];
	int ages[5];
	double salaries[5];
	int peopleCounter = 0;
	//	infile.open("map.txt");
	//infile>>names[peopleCounter]>>ages[peopleCounter]>>salaries[peopleCounter];
	while (!infile.eof())
	{
		peopleCounter++;
	}

	// Sorting
	for (int i = 0; i < peopleCounter; i++)
	{
		for (int j = 0; j < peopleCounter; j++)
		{
			/* code */
		}
	}
}