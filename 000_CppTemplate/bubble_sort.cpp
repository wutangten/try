/************************************************************************

	Filename: bubble_sort.cpp

	Code Description:
		Perform basic algorithm(bubble sort).

	Updated by wutangten on 09/17/19.

************************************************************************/

#include <iostream>  /* basic input output*/
#include <algorithm> // contains swap()

using namespace std;

/****************************************************
	Function Name:
	Parameters:
	Return Type:
	Description:
****************************************************/

int main()
{
	int list1[] = {3, -5, 19, 13, -5};
	int num_of_element=0;

	/*
		sizeof(list1)/sizeof(list1[0]) is useful when we don't know
		how many elements in the array(s).
		sizeof() counts the operand's size(by byte).
		size(list1) == num_of_element * sizeof(int)
		size(list1) == num_of_element * sizeof(list1[0])
		Can rewrite algebraically
		num_of_element == size(list1) * sizeof(int)
	*/
	//cout<<"The size of the array: "<<sizeof(list1)/sizeof(list1[0])<<endl;
	//cout<<"The size of the array: "<<sizeof(list1)/sizeof(*list1)<<endl;	// '*'deference, gets the address
	cout<<"The size of the array: "<<sizeof(list1)/sizeof(list1[3])<<endl;
	num_of_element = sizeof(list1)/sizeof(list1[0]);

	// Perfrom bubble sort
	for (int i = 0; i < num_of_element-1; i++)
	{
		for (int j = 0; j < num_of_element-i-1; j++)
		{
			if (list1[j] > list1[j + 1]) // Order: small to large
			{
				swap(list1[j], list1[j + 1]);
			}
			/*
			if (list1[j] > list1[j + 1]) // Order: large to small
			{
				swap(list1[j], list1[j + 1]);
			}
			*/
		}
	}

	cout << "After sorting:" << endl;
	for (int i = 0; i < num_of_element; i++)
	{
		cout << list1[i] << ", ";
	}
}