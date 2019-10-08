#include <iostream> /* basic input output*/
#include <string>
using namespace std;
int main()
{
	int *dynArray;		   // pointer points nowhere here
	dynArray = new int[5]; // allocates 5 integers in an array-order
						   // diagram: [][][][][]
	*dynArray = 18;		   // diagram: "[18]"[][][][], working the 1st element

	// Assigning the 2nd element, note that just use normal array notation
	// Method 1, no need bracket coz the '*' makes it working with address.
	*(dynArray + 1) = 16;
	// Method 2, more friendly.
	dynArray[1] = 16;

	// generate random values for the dynamic array
	for (int i = 0; i < 5; i++)
	{
		dynArray[i] = rand() % 20;
		*(dynArray + 1) = rand() % 20;
	}

	/*
		Bad method to work on other element of the array
		dynArray = dynArray + 1; // Jump to the 2nd-element, diagram: []"[here]"[][][]
		*dynArray = 16;			 // diagram: [18]"[16]"[][][], working ONLY the 1st element
	*/
}