/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//		//Type here...//
//		Note:
//			Dynamic array is good for big data set or unknown size of data.
//			Use static array if the data set is small.
//
//  Updated by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	int **two_D;
	/* 	Make it as dynamic array
		Syntax: pointer-variable = new dataType [index]
	*/

	// allocate a 3*3 array
	two_D = new int *[3]; // allocate the rows, 3 rows

	for (int i = 0; i < 3; i++)
	{
		two_D[i] = new int[3]; // each row has 3 columns
	}

	/*
		row1: [[[]]]
		row2: [[[]]]
		row3: [[[]]]
	*/
	two_D[0][0] = 15;
	**two_D = 15; // same result:
	two_D[2][1] = 12;
	*(*(two_D + 2) + 1) = 12; //col_address(row_address(tow_D+2)+1) =12;

	/*
		row1: [15][][]
		row2: [][][]
		row3: [][12][]
	*/

	// another 2d-array
	// 1. declare a new pointer
	int **tmp2D;

	// 2. allocate more memory to the pointer
	tmp2D = new int *[4];
	/*	temp2D
		row0: []
		row1: []
		row2: []
		row3: []
	*/
	for (int i = 0; i < 4; i++)
	{
		tmp2D[i] = new int[5];
	}

	// 3. deep copy from smaller matrix into larger matrix.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp2D[i][j] = two_D[i][j];
		}
	}
	// 4. deallocate smaller array
	for (int i = 0; i < 3; i++)
	{
		delete[] two_D[i];
	}
	delete[] two_D;
	// 5. Have the old pointer points to the new array
	two_D = tmp2D;
	tmp2D = NULL;
}
