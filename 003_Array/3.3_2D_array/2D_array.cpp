/************************************************************************

	Filename: 2D_array.cpp

	Code Description:
		This program is a practice for array and file-operation.
		Find a max square area for giving file that contains a 10*10-sized matrix with 1s and 0s.
		There are two txt-files for this assignment. Feel free to modify the files to test the algorithm.
			Note: The txt-file can only contains 1s and 0s.
		Four functions:
		1. Prompt and check if the input is valid.
		2. Read from the file and assign into the first 2D-array (map1).
		3. For the comparision algorithm.
		4. Construct the second 2D-array(map2) to find the max square- area.
		Algorithm Reference: https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

	Updated by wutangten on 09/02/19.

************************************************************************/

#include <iostream> /* basic input output*/
#include <fstream>  // file operation
#include <string>

using namespace std;

void promptRead(string filename, ifstream &infile);						// Prompt and check if the input is valid.
void storing(char map1[10][10], ifstream &infile);						// Read from the file and assign into the first 2D-array (map1).
int findMin(int a, int b);												// For the comparision algorithm.
void findMaxArea(char map1[10][10], int map2[10][10], int &max_matrix); // Construct the second 2D-array(map2) to find the max square- area.

int main()
{
	ifstream infile; // object from library <fstream> for reading from a file

	const int col = 10, row = 10; // must use const otherwise won't compile
	char map1[row][col];		  // 2D-array, use char, DONT use int because text.file is character.
	int map2[row][col];			  // 2D-array, use int to compare element and find the max square area.
	int maxArea;				  // the final result/output
	string filename;			  // This reads the filename the user enter
	int max_matrix;				  // keep track of the biggest element in the new 2D-array

	promptRead(filename, infile); // Prompt and check if the input is valid.
								  // infile.open("map.txt"); //open directly for testing
	infile.close();
	storing(map1, infile);				 // Read file into 2D array
	findMaxArea(map1, map2, max_matrix); // Construct the second 2D-array(map2) to find the max square area.
	maxArea = max_matrix * max_matrix;   // the max_matrix is the biggest possible elemnet.

	// Print maxArea when all functions are done.
	cout << endl
		 << "Thanks" << endl
		 << endl;
	cout << "Max  area in the  police  station  is " << maxArea;
}

//	1st function: Prompt and check if the input is valid.
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
	} while (!infile.is_open()); // repeat the prompt if the file is NOT found
};

/*
	2nd function:
		2.1 Read from the file and assign into 2D-array.
		2.2 Convert the 1s into 0s and ve versa for the algorithm of finding the max square-area.
*/
void storing(char map1[10][10], ifstream &infile)
{
	// 2.1 Read from the file and assign into 2D-array.
	while (!infile.eof()) // keep reading until reaches to the end of file.
	{
		for (int row = 0; row < 10; row++)
		{
			for (int col = 0; col < 10; col++)
			{
				infile >> map1[row][col];
			}
		}
	}
	// 2.2 Convert the 1s into 0s and ve versa for the algorithm of finding the max square-area.
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			if (map1[row][col] == '1') // 1-element becomes 0-element
			{
				map1[row][col] = '0';
			}
			else // 0-element becomes 1-element
			{
				map1[row][col] = '1';
			}
		}
	}
};

/* 3rd function: for the comparision algorithm
	Actually, there is a built-in min function in the <algorithm> library already just I just wrote this to practice writing a simple function.
*/
int findMin(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

// 4th function: construct the map2 to find the max square- area.
void findMaxArea(char map1[10][10], int map2[10][10], int &max_matrix)
{
	// Copy map1 into map2 so we can perform the comparision algorithm.
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			map2[row][col] = map1[row][col] - '0'; // map1 is char-type, so subtracting '0' gets the actual integer value for map2 that is int-type.
		}
	}
	// Increment the element has 1 to perfrom the algorithm.
	for (int row = 1; row < 10; row++)
	{
		for (int col = 1; col < 10; col++)
		{
			if (map1[row][col] == '1') // this algorithm only checks the 1-element in the 1st 2D-array (map1).
			{
				map2[row][col] = findMin(map2[row][col - 1], findMin(map2[row - 1][col],
																	 map2[row - 1][col - 1])) +
								 1; // check 3 surrounding elements and increment the smallest one.
			}
			else
			{
				map2[row][col] = 0; //keep the 0-element as zero so the algorithm won't check it.
			}
		}
	}
	// Find the biggest index/element in the 2D-array "map2" after incrementing.
	max_matrix = map2[0][0]; // a biggest element holder start with [0][0]
	for (int row = 1; row < 10; row++)
	{
		for (int col = 1; col < 10; col++)
		{
			if (max_matrix < (map2[row][col])) // update the holder if the next element has bigger value.
			{
				max_matrix = map2[row][col];
			}
		}
	}
	/*	// Testing: print the max_matrix and the map2 after incrementing.
	cout << "Max Matrix: " << max_matrix << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map2[i][j] << " ";
		}
		cout << "\n";
	}
	*/
};