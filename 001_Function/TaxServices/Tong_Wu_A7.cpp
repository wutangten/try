#include <iostream>
#include <iomanip>
using namespace std;

//this function outputs one line to the screen, the string parameter will be the output label, and the double parameter will be the number that you will output, the two int parameters will be the amount used for the setw function for the label and the number respectively*/
void outputLine(string msg, int msgLen, double amount, int amtLen)
{
	cout << left << setw(msgLen) << setfill('.') << msg << "$";
	cout << setw(amtLen) << setfill(' ') << right << fixed << setprecision(2) << amount << endl;
}
//Function prints certain prompt and check input is a correct type(number) or not.
double getInput(string msg)
{
	double value;
	cout << msg;
	cin >> value;
	//reprompt if input is not number, DON'T check negative and zeros here.
	while (cin.fail())
	{
		cout << msg;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> value;
	}
	return value;
}

//Function to compute final charge
double computeBillingAmount(double &totalIncome, int consulTime, double hourRate)
{
	double billAmount = 0;
	if ((totalIncome <= 25000 && consulTime <= 30) || (consulTime <= 20))
	{
		billAmount = 0;
	}
	else if ((consulTime >= 20) && (totalIncome >= 25000))
	{
		billAmount = (hourRate * .7 * ((consulTime - 20) / 60.0));
	}
	else
	{
		billAmount = (hourRate * .4 * ((consulTime - 30) / 60.0));
	}
	return billAmount;
}

int main(int argc, const char *argv[])
{
	//Testing value for debugging
	//double totalIncome=12456.71, hourRate=70, billAmount=0; int consulTime=75;
	//double totalIncome=150246.12, hourRate=85.23, billAmount=0; int consulTime=180;
	//double totalIncome=24561.66, hourRate=50, billAmount=0; int consulTime=30;

	double totalIncome = 0, hourRate = 0, consulTime = 0, billAmount = 0;
	//use do-while flow to reprompt if the input is 0 or negative
	do
	{
		string promt0 = "Enter total income: ";
		totalIncome = getInput(promt0);
	} while (totalIncome <= 0);
	cout << endl;

	do
	{
		string promt1 = "Enter hourly rate: ";
		hourRate = getInput(promt1);
	} while (hourRate <= 0);
	cout << endl;

	do
	{
		string promt2 = "Enter consulting time: ";
		consulTime = getInput(promt2);
	} while (consulTime <= 0);
	cout << endl;

	//Assign computed value to billAmount fo final output
	billAmount = computeBillingAmount(totalIncome, consulTime, hourRate);

	/*this function outputs one line to the screen, the string parameter will be the output label, and the double parameter will be the number that you will output, the two int parameters will be the amount used for the setw function for the label and the number respectively*/
	string afterincome = "Income";
	outputLine(afterincome, 20, totalIncome, 10);

	string afterHourRate = "Hourly rate";
	outputLine(afterHourRate, 20, hourRate, 10);

	string afterBillAmount = "Billing Amount";
	outputLine(afterBillAmount, 20, billAmount, 10);
	cout << endl;

	return 0;
}
