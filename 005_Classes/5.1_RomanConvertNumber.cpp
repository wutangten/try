/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//
//  Created by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/

using namespace std;

class romanType
{
public:
	romanType();
	void convert(string);
	void print() const;
	void initialNum(int);

private:
	int positiveNum;
};

void romanType::print() const
{
	cout << "Positive Number: " << positiveNum;
}

void romanType::initialNum(int a)
{
	positiveNum = a;
}

romanType::romanType()
{
	positiveNum = 0;
}

void romanType::convert(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		/* need to check 4th and 6th, they are "2-characters"*/
		if (a[i] == 'M')
		{
			positiveNum = positiveNum + 1000;
		}
		else if (a[i] == 'D')
		{
			positiveNum = positiveNum + 500;
		}
		else if (a[i] == 'C')
		{
			positiveNum = positiveNum + 100;
		}
		else if (a[i] == 'L')
		{
			positiveNum = positiveNum + 50;
		}
		else if (a[i] == 'X')
		{
			positiveNum = positiveNum + 10;
		}
		else if (a[i] == 'V')
		{
			positiveNum = positiveNum + 5;
		}
		else if (a[i] == 'I')
		{
			positiveNum = positiveNum + 1;
		}
	}
}

int main()
{
	romanType test1;
	test1.convert("MCXIV");
	test1.print();
	/* Code */
}