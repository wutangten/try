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
	int num;
	int *listPtr;
	int *temp;
	listPtr = new int[5];
	num = 8;
	temp = listPtr;

	for (int i = 0; i < 5; i++)
	{
		*listPtr = num;
		num = num + 2;
		listPtr++;
	}
	cout<<"After 1st loop: ";
	for (int k = 0; k < 5; k++)
	{
		cout << *listPtr << " ";
		listPtr++;
	}
	listPtr = temp;

	for (int k = 0; k < 5; k++)
	{
		*temp = *temp + 3;
		temp++;
	}
	cout<<endl<<"After 2nd loop: ";
	for (int k = 0; k < 5; k++)
	{
		cout << *listPtr << " ";
		listPtr++;
	}
	cout << endl;
}
