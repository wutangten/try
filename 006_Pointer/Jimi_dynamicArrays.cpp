#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int * dynamicArray; //pointer that points to a dynamic array
	int capacity = 5; //denotes the max amount of elements that can be stored
	int size = 0; //denotes the actual amount of elements currently stored in the array

	dynamicArray = new int[capacity]; //allocate an array to the pointer

	cin >> dynamicArray[size]; //read an element

	//keep reading until value read in is -1
	while (dynamicArray[size] != -1)
	{
		size++; //-1 not read, increment the counter

		if (capacity == size) //array is full, time to resize it
		{
			//allocate a temporary array, that is double the size of the previous array
			int * tmpArray = new int[capacity * 2];

			//perform a deep copy of smaller array into larger array
			for (int i = 0; i < capacity; i++)
				tmpArray[i] = dynamicArray[i];

			capacity = capacity * 2; //update the max capacity for the new array

			delete [] dynamicArray; //deallocate obsolete array

			dynamicArray = tmpArray; //pointer dynamic array to newly resized array
		}

		cin >> dynamicArray[size];
	}

	cout << "Elements in array" << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dynamicArray[i] << " ";

	cout << endl;

	delete [] dynamicArray; //deallocate all dynamic memory before program terminates

	return 0;
}