/************************************************************************
//
//  Filename: isPalindrome.cpp
//
//  Code Description: Determine a word(string) is a palindrome or not.
// 	Palindrom is a word/phrase reads the same from backward or forward
//
//  Created by brucederland on 08/08/19.
//
************************************************************************/

#include <iostream>
using namespace std;

/* Reference for this algorithm: https://mathalope.co.uk/2014/09/04/accelerated-c-solution-to-exercise-5-10/ */
void isPalindrome(string text)
{
	int start = 0;
	int end = text.length() - 1;
	while (end > 1)
	{
		if (text[start++] != text[end--])
		{
			cout << "Not Palindrome!";
			return;
		}
	}
	cout << "It's Palindrome!";
}

int main()
{
	string text;

	/* Prompt */
	cout << "Enter the text: " << endl;
	cin >> text;

	/* Make sure the input is correct */
	cout << "You've entered: ";
	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
	}
	cout << endl;
	isPalindrome(text);
}
