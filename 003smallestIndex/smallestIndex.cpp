
#include <iostream>
#include <cstdlib>

using namespace std;

void smallestIndex(int num[])
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
	cout<<"The smallest number is : "<<smallestIndex;
}
/*
void smallestIndex(int num[])
{
	int smallestIndex;
	for (int i = 0; i < 100; i++)
	{
		if (num[i] > num[i + 1])
		{
			smallestIndex = num[i + 1];
		}
		else
		{
			smallestIndex =  num[i];
		}
	}
	//return smallestIndex;
	cout<<"The smallest number is : "<<smallestIndex;
}
*/
int main()
{
	int num[100];
	for (int i = 0; i < 100; i++)
	{
		num[i] = rand() % 100 + 1;
		//cout << num[i] << " ";
	}

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
	//cout << "The smallest number is: " << smallestIndex(num);
	smallestIndex(num);
}