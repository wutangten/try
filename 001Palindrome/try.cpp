#include <iostream>
using namespace std;

void isPalindrome(string text)
{
	int start = 0;
	int end = text.length()-1;
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
	cout << "Enter the text: " << endl;
	cin >> text;
	cout << "You've entered: ";
	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
	}
	cout << endl;
	isPalindrome(text);
}
