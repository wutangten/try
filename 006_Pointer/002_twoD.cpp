/************************************************************************

	Filename: towD.cpp

	Code Description:
		make a dynamic array and resize it into bigger size
		need a temp_dynamic_array to resize
			old size: 4*5
			new size: 7*5

	Updated by wutangten on 10/07/19.

************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	// 1. declare the pointer with two-star
	int **twoD;

	// 2. create array of pointer, this will represent the number of rows
	twoD = new int *[4];

	// 3. create the column.
	for (int i = 0; i < 4; i++)
		twoD[i] = new int[5]; //assign a column amount to each row

	// 4. use 2-for-loop to set random values to the 2d_dynamic_array
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			twoD[i][j] = rand() % 15 + 1;


	// How to resize the 2D array
	//create temporary larger 2D array
	int **tmp;

	//we create a 7 x 5 array
	// get the row
	tmp = new int *[7];

	// get the col
	for (int i = 0; i < 7; i++)
		tmp[i] = new int[5];

	// deep copy: copy the data from smaller dynamic array to bigger array
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = twoD[i][j];


	// deallocate the old array
	for (int i = 0; i < 4; i++)
		delete[] twoD[i];
	delete[] twoD;
	// twoD is now obsolete

	// shallow copy: have the old array points to the new array
	twoD = tmp; //now twoD is resized

	// avoid dangling pointer
	tmp = NULL;	// optional though

	return 0;
}
