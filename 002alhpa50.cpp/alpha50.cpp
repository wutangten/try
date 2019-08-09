/************************************************************************
//
//  Filename: .cpp
//
//  Code Description: 
//
//  Created by brucederland on 08/08/19.
//
************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double alpha[50];
	alpha[0] =0;

	/* For the first 25 element */
	for (int i = 0; i < 25; i++)
	{
		alpha[i] = i * i;
	}

	/* For the last 25 element */
	for (int j = 25; j < 50; j++)
	{
		alpha[j] = 3 * j;
	}

	/* Output 10 element per line */
	cout << " The elements are: "<<endl;
	int linebreak = 0;
	for (int i = 0; i < 50; i++)
	{
		cout << alpha[i] << " ";
		linebreak++;
		if (linebreak == 10)
		{
			cout << endl;
			linebreak = 0;
		}
	}
}