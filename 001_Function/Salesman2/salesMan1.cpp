#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;

char keepGo(char yesNo);
int yearsCheck(int);
double incomeCheck(double), soldCheck(double);

int main(int argc, const char *argv[])
{
	int years = 0;
	char yesNo;
	double monthIncome = 0, soldAmount = 0, bonus = 0, addBonus = 0;
	const double fristBar = 0.03, secondBar = 0.06;
	;

	//use do-while for at least one running
	do
	{
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
			addBonus = soldAmount * fristBar;
		}
		else if (soldAmount >= 10000)
		{
			addBonus = soldAmount * secondBar;
		}
		//combine year-based and additional commission
		bonus = bonus + addBonus;
		double FinalSalary = monthIncome + bonus;

		//out and formatting
		cout << left << setw(20) << "Years worked";
		cout << setw(16) << setfill(' ') << right << years << endl;
		cout << left << setw(20) << setfill('.') << "Base salary........."
			 << "$";
		cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << monthIncome << endl;
		if (years > 0)
		{
			cout << left << setw(20) << setfill('.') << "Bonus..............."
				 << "$";
			cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << bonus << endl;
		}

		cout << left << setw(20) << setfill('.') << "Amount sold........."
			 << "$";
		cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << soldAmount << endl;
		if (years > 0)
		{
			cout << left << setw(20) << setfill('.') << "Salary w/ bonus"
				 << "$";
			cout << setw(15) << setfill(' ') << right << fixed << setprecision(2) << FinalSalary << endl;
		}

		//use 2nd do-while to emilate input that is not Y
		cout << "Do we have more employees? (Y/N): ";
		cin >> yesNo;
		yesNo = keepGo(yesNo);

	} while (yesNo == 'y' || yesNo == 'Y'); //will continue to start over if input is y or Y
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

//for continue
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
