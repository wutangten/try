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

using namespace std;

int main()
{
	/* Code */
	int list[7] = {10, 8, 15, 14, 16, 24, 36};
	int *ptr = list;
	cout<<"The original array: ";
	for (int i = 0; i < 7; i++)
	{
		cout << list[i] << " ";
	}
	cout<<endl;
	
	*ptr = *ptr + 2;
	cout<<"After first line: ";
	for (int i = 0; i < 7; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;

	ptr = ptr + 2;
	cout<<"After second line: ";
	for (int i = 0; i < 7; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;

	*ptr = (*ptr) - *(ptr - 1);
	cout<<"After third line: ";
	for (int i = 0; i < 7; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;

	ptr++;
	*ptr = 2 * (*ptr) - 3;
	cout<<"After last line: ";
	for (int i = 0; i < 7; i++)
	{
		cout << list[i] << " ";
	}
}
