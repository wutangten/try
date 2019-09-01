/************************************************************************
//
//  Filename: TONG_WUKIT_A1.cpp
//
//  Code Description:
//		Need 3 function:
		1. Read  the  file
		2. Store  the contents into the 2D array
		3. Determine the size of the max square sub matrix
//
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// void promptRead(string filename, ifstream &infile);
void storing(char map[10][10], ifstream &infile);

int main()
{
	ifstream infile; // object from library <fstream> for reading from a file

	const int col = 10, row = 10; // must use const otherwise won't compile
	char map[row][col];			  // 2D-array, use char, DONT use int because text.file is character.
	int maxArea;				  // the final result/output
	string filename;			  // This reads the filename the user enter

	// Open the file and prompt
	//promptRead(filename, infile); // 1st function: reads user input for filename
	infile.open("map2.txt"); //open directly for testing

	// Test the reading into 2D-array
	storing(map, infile); // 2nd function: read file into 2D array

	cout << endl
		 << "Print the 2D-array after storing" << endl;
	for (int row = 0; row < 10; row++)
	{
		cout << "Row" << row + 1 << ": ";
		for (int col = 0; col < 10; col++)
		{
			cout << map[row][col];
		}
		cout << endl;
	}

	// After successfully reading into 2D-array
	cout << endl
		 << "Thanks" << endl; // this will print if the file is opened successfully.

	// final outout:
	// 1st: find how many 0's in each row(array).
	char map2[row][col];

	//cout << "Max  area in the  police  station  is " << maxArea;

	cout << "The 2nd map BEFORE algo: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map2[i][j] = map[i][j];
			cout << map2[i][j];
		}
		cout << endl;
	}
	/* Set first column of S[][]*/
	for (int i = 0; i < 10; i++)
	{
		map2[i][0] = (int)map[i][0];
	}

	/* Set first row of S[][]*/
	for (int j = 0; j < 10; j++)
	{
		map2[0][j] = (int)map[0][j];
	}

	//Construct the final 2nd map
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (map[i][j] == '0')
			{
				map2[i][j] = min(map2[i][j - 1], min(map2[i - 1][j],
													 map2[i - 1][j - 1])) +
							 1;
			}
			else
			{
				map2[i][j] = '1';
			}
		}
	}

	// Find entry point. //map2 is char
	char max_matrix[10][10];
	max_matrix[0][0] = map2[0][0];
	int max_col = 0, max_row = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (max_matrix[i][j] < map2[i+1][j+1])
			{
				max_matrix[i][j]=map2[i][j];
				max_col=j;
				max_row=i;
			}
		}
	}
	cout<<"The entry point is: "<<'['<<max_row<<']'<<' '<<'['<<max_col<<']'<<endl;
	cout << "The 2nd map AFTER algo: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			cout << map2[i][j];
		}
		cout << endl;
	}
}

void storing(char map[10][10], ifstream &infile)
{
	while (!infile.eof())
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				infile >> map[j][k];
			}
		}
	}
};
/*
	1st function: reads user input for filename
	argument: string filename and ifstream &infile
*/

/*
void promptRead(string filename, ifstream &infile)
{
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

}
while (!infile.is_open())
	; // repeat the prompt if the file is NOT found
}*/
;

/*
	string line;
	while ( getline (infile,line) )
    {
      cout << line << '\n';
    }*/