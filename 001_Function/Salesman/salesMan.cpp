/************************************************************************

	Filename: salesMan.cpp

	Code Description:
		This program calculates the final salary for a saleman.
		1. Need to read the following:
			1.1 The number of years have worked
			1.2. Monthly salary
			1.3. Sales amount of that month
		2. Output the following
			2.1. The base salary
			2.2. The bonus
			2.3. The Amount sold of that month
			2.3. The final salary (base salary + bonus)
			2.4. Ask the user about calculate for the next employee or not.


	Updated by wutangten on 03/09/19.

************************************************************************/
#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;

char keepGo(char yesNo);
int yearsCheck(int);
double incomeCheck(double), soldCheck(double);

int main(int argc, const char *argv[])
{
	int years = 0; // Only count whole year, so use int-type instead of double-type.
	char yesNo;	// Determine if the user like to continue
	double		   // Money must use decimal so double-type.
		monthIncome = 0,
		soldAmount = 0,
		bonus = 0,
		addBonus = 0;
	const double firstBar = 0.03, secondBar = 0.06; // For the calculate the comission.

	//use do-while for at least one running
	do
	{
		// Prompt
		cout << "Enter years worked: ";
		cin >> years;
		years = yearsCheck(years);

		cout << "Enter monthly salary: ";
		cin >> monthIncome;
		monthIncome = incomeCheck(monthIncome);

		cout << "Enter sales amount: ";
		cin >> soldAmount;
		soldAmount = soldCheck(soldAmount);

		//math for year-based commission
		if (years >= 5)
		{
			bonus = 20 * years;
		}
		//math for additional commission
		if (soldAmount > 5000 && soldAmount < 10000)
		{
			addBonus = soldAmount * firstBar;
		}
		else if (soldAmount >= 10000)
		{
			addBonus = soldAmount * secondBar;
		}
		//combine year-based and additional commission
		bonus = bonus + addBonus;
		double FinalSalary = monthIncome + bonus;

		// Output and formatting
		cout << left << setw(20) << "Years worked";
		cout << setw(16) << setfill(' ') << right << years << endl;
		cout << left << setw(20) << setfill('.') << "Base salary........."
			 << "$";
		cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << monthIncome << endl;

		if (years > 0) // No bonus for employees who worked less than ONE-year.
		{
			cout << left << setw(20) << setfill('.') << "Bonus..............."
				 << "$";
			cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << bonus << endl;
		}

		cout << left << setw(20) << setfill('.') << "Amount sold........."
			 << "$";
		cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << soldAmount << endl;

		if (years > 0) // No bonus for employees who worked less than ONE-year.
		{
			cout << left << setw(20) << setfill('.') << "Salary w/ bonus"
				 << "$";
			cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << FinalSalary << endl;
		}

		// Use 2nd do-while to emilate input that is not Y
		cout << "Do we have more employees? (Y/N): ";
		cin >> yesNo;
		yesNo = keepGo(yesNo);

	} while (yesNo == 'y' || yesNo == 'Y'); // Restart the program if input is y or Y
	return 0;
}

//for yearsValue-check
int yearsCheck(int years)
{
	while (years < 0 || cin.fail())
	{
		cout << "Enter years worked: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> years;
	}
	return years;
}

//for income-check
double incomeCheck(double monthIncome)
{
	while (cin.fail() || (monthIncome >= 1500) || (monthIncome < 0))
	{
		cout << "We both know that ’s not a valid salary..." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter monthly salary: ";
		cin >> monthIncome;
	}
	return monthIncome;
}

//soldAmount check
double soldCheck(double soldAmount)
{
	while (cin.fail() || (soldAmount < 0))
	{
		cout << "Are you giving away things for free?!?!?!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter sales amount: ";
		cin >> soldAmount;
	}
	return soldAmount;
}

//	Asking user to restart or not.
char keepGo(char yesNo)
{
	while (yesNo != 'y' && yesNo != 'Y')
	{
		if (yesNo == 'n' || yesNo == 'N')
		{
			return 0;
		}
		cout << "Do we have more employees? (Y/N): ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> yesNo;
	}
	return yesNo;
}
