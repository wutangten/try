
/************************************************************************
//
//  Filename: smallestIndex.cpp
//
//  Code Description: Find the smallest index of an array
//
//  Created by brucederland on 08/08/19.
//
************************************************************************/

#include <iostream>
#include <cstdlib>		/* rand() */
#include <time.h>       /* time */

using namespace std;

int smallestIndex(int num[]);

int main()
{
	int num[100];

	/* Generate random number*/

	srand(time(NULL));	/* seed by time */
	for (int i = 0; i < 100; i++)
	{
		num[i] = rand() % 100 + 1;
		//cout << num[i] << " ";
	}

	/* Format: print 10 number per line */
	int linebreak = 0;
	for (int i = 0; i < 100; i++)
	{
		cout << num[i] << " ";
		linebreak++;
		if (linebreak == 10)
		{
			cout << endl;
			linebreak = 0;
		}
	}

	// output
	cout << "The smallest number is: " << smallestIndex(num);
}

int smallestIndex(int num[])
{
	int smallestIndex = num[0];
	for (int i = 0; i < 100; i++)
	{
		if (smallestIndex > num[i])
		{
			smallestIndex = num[i];
		}
	}
	//return smallestIndex;
	return smallestIndex;
}