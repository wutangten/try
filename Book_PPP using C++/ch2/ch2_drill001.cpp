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
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
inline void keep_window_open()		// Needed for some Windows machines prevenet closing window before read the output.
{
	char ch;
	cin >> ch;
}

int main()
{
	cout << "Hello, World!\n";
	keep_window_open(); // wait for a char to be entered
	return 0;
}