#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	int a[] = {1, 2, -3, 4, 5, 4};
	int Constant = 3;

	for (int i = 0; i < 5; i++)
	{
		//Dont execute negative value
		if (a[i] < 0)
		{
			continue; //ignore a[2] and jump to a[3]
		}

		//j is for the range of the array: a[3] to a[5] in this case
		for (int j = i + 1; j < i + Constant + 1; j++)
		{
			//
			if (j >= 6)
			{
				break; //terminate the loop
			}
			else
			{
				a[i] = a[i] + a[j];
			}
		}
	}

	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;
	cout << a[3] << endl;
	cout << a[4] << endl;
	cout << a[5] << endl;
	cout << *a << endl;
	// Should print 4, 8, -3, 13, 9, 4

	return 0;
}
