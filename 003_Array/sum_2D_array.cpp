#include <iostream>
using namespace std;

int main()
{

	double matrix[4][5];
	double row_sum = 0;
	// initialize the table
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = i + j;
		}
		cout << endl;
	}
	//output the initialized table
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	// Math: adding the element of each row.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			row_sum += matrix[i][j]; // add all element in that row
		}
		cout << row_sum << endl; //output sum of each row of a 2D-array
		row_sum = 0;			 // reset the counter
	}
}
