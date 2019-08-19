#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int MENU_AMOUNT = 50;

//Assigning arrays
void getItems(string itemNames[], int quantities[], double prices[], int &size, ifstream &infile)
{
	size = 0;
	while (!infile.eof())
	{
		infile >> itemNames[size] >> prices[size] >> quantities[size]; //assign values into 3 diffrent arrays
		size++;
	}
	//cout<<"Line/size is : "<<size-1<<endl; //for debugging: keep check on how many lines in the file.
	return;
}

//swap function for bubble sort below
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
	return;
}
//Perform bubble sorting
void sortItemsByQuantity(string itemNames[], int quantities[], double prices[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 2; j++)
		{
			//if you flip the inequality, it will sort //the array from highest to lowest
			if (quantities[j] > quantities[j + 1]) //swap 3 diffrent arrays
			{
				swap(quantities[j], quantities[j + 1]);
				swap(itemNames[j], itemNames[j + 1]);
				swap(prices[j], prices[j + 1]);
			}
		}
	}
	return;
}
//output formatting
void outputItem(string itemNames, int itemLen, double prices, int priceLen)
{
	cout << left << setw(itemLen) << setfill(' ') << itemNames << "$";
	cout << setw(priceLen) << setfill(' ') << right << fixed << setprecision(2) << prices << endl;
}

int main(int argc, const char *argv[])
{
	int size = 0;
	string itemNames[MENU_AMOUNT];
	int quantities[MENU_AMOUNT];
	double prices[MENU_AMOUNT];
	string filename;
	ifstream infile;
	//get filename input
	do
	{
		cout << "Enter an input file: ";
		cin >> filename;
		infile.open(filename.c_str()); //attempts to open filestream
	} while (!infile.is_open());	   //checks if the file is found */
	cout << "Welcome to the Krusty Krab!" << endl
		 << endl;

	//assign file into array
	getItems(itemNames, quantities, prices, size, infile);
	infile.close();

	int selection = 0;							   //what item he/she wants
	int quanOrder = 0;							   //how many of that item he/she wants
	char yesNo = 'x';							   //exit the outer loop
	double amount = 0.0, taxes = 0.0, total = 0.0; //what he/she needs to pay in the end.
	do
	{

		sortItemsByQuantity(itemNames, quantities, prices, size); //step 3 on the assignment sheet
		int listNum[size];
		for (int i = 0; i < size - 1; i++)
		{
			if (quantities[i] == 0)
			{ //jump control if quantities is 0
				continue;
			}
			listNum[i] = i + 1;
			cout << left << setw(3) << listNum[i]; //output start from 1 not 0 so i+1
			outputItem(itemNames[i], 20, prices[i], 10);
		}
		cout << endl;
		do
		{ //first inner loop
			cout << "Make a selection: ";
			cin >> selection;
			cin.clear();
			cin.ignore(10000, '\n');
		} while (cin.fail() || selection <= 0 || selection > quantities[selection - 1]);
		cout << "Alright, great choice!" << endl
			 << endl;

		do
		{ //2nd inner loop
			cout << "How many orders of this item would you like? ";
			cin >> quanOrder;
			cin.clear();
			cin.ignore(10000, '\n');
			if (quanOrder > quantities[selection - 1])
			{ //it customer wants more than we have now
				cout << "We only have " << quantities[selection - 1] << " of those" << endl
					 << endl;
			}
			else if (quanOrder <= quantities[selection - 1] && quanOrder > 0)
			{
				quantities[selection - 1] = quantities[selection - 1] - quanOrder;
				cout << "Ok we'll bring that right out" << endl
					 << endl;
			}
		} while (cin.fail() || quanOrder <= 0);

		amount = amount + quanOrder * prices[selection - 1]; //calculation

		cout << "Kitchen is still open, will this complete your order? ";
		cin >> yesNo;
		cout << endl;
		while (yesNo != 'y' && yesNo != 'n')
		{
			cout << "I'm going to need a better answer" << endl;
			cout << "WILL THIS COMPLETE YOUR ORDER??? ";
			cin >> yesNo;
			cout << endl;
		}
		if (yesNo == 'y' || yesNo == 'Y')
		{
			cout << "Never mind, the kichen JUST closed, now get out" << endl;
			cout << "But you have to pay first" << endl;
			cout << left << setw(10) << "Amount" << setfill(' ') << "$";
			cout << setw(10) << setfill(' ') << right << fixed << setprecision(2) << amount << endl;

			taxes = amount * (.0725);
			cout << left << setw(10) << "Tax" << setfill(' ') << "$";
			cout << setw(10) << setfill(' ') << right << fixed << setprecision(2) << taxes << endl;

			total = amount + taxes;
			cout << left << setw(10) << "Total" << setfill(' ') << "$";
			cout << setw(10) << setfill(' ') << right << fixed << setprecision(2) << total << endl
				 << endl;
			break;
		}
	} while (yesNo == 'n' || yesNo == 'N');
	return 0;
}
