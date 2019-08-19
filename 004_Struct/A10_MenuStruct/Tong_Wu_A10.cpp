#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int MENU_AMOUNT = 50;

//Struct
struct menuItem
{
	string itemName;
	int quantity;
	double price;
};

void getItems(menuItem items[], int &size, ifstream &infile);				 //Assigning data to struct
void sortItemsByQuantity(menuItem items[], int size);						 //Perform bubble sorting to swap out 0 or lower quantity item
void outputItem(string itemNames, int itemLen, double prices, int priceLen); //formatting

int main(int argc, const char *argv[])
{
	int size = 0;
	menuItem items[MENU_AMOUNT];
	ifstream infile;
	string filename;

	do //reprompt if the input filename is wrong.
	{
		cout << "Enter an input file: ";
		cin >> filename;
		infile.open(filename.c_str()); //attempts to open filestream
	} while (!infile.is_open());	   //checks if the file is found */
	cout << "Welcome to the Krusty Krab!" << endl
		 << endl;
	getItems(items, size, infile); //read from file and Assigning data to struct
	infile.close();

	int selection = 0;							   //what item he/she wants
	int quanOrder = 0;							   //how many of that item he/she wants
	char yesNo = 'x';							   //exit the outer loop
	double amount = 0.0, taxes = 0.0, total = 0.0; //what he/she needs to pay in the end.

	do
	{
		int listNum[size];				  //output list number
		sortItemsByQuantity(items, size); //reline-up items: ensure small quantity is at top and out the 0 quantity
		for (int i = 0; i < size - 1; i++)
		{
			if (items[i].quantity == 0)
			{ //jump control if quantities is 0
				continue;
			}
			listNum[i] = i + 1;
			cout << left << setw(3) << listNum[i]; //output start from 1 not 0 so i+1
			outputItem(items[i].itemName, 20, items[i].price, 10);
		}
		cout << endl;
		do
		{ //first inner loop
			cout << "Make a selection: ";
			cin >> selection;
			cin.clear();
			cin.ignore(10000, '\n');
		} while (cin.fail() || selection <= 0 || selection > items[selection - 1].quantity);
		cout << "Alright, great choice!" << endl
			 << endl;

		do
		{ //2nd inner loop
			cout << "How many orders of this item would you like? ";
			cin >> quanOrder;
			cin.clear();
			cin.ignore(10000, '\n');
			if (quanOrder > items[selection - 1].quantity)
			{ //it customer wants more than we have now
				cout << "We only have " << items[selection - 1].quantity << " of those" << endl
					 << endl;
			}
			else if (quanOrder <= items[selection - 1].quantity && quanOrder > 0)
			{
				items[selection - 1].quantity = items[selection - 1].quantity - quanOrder;
				cout << "Ok we'll bring that right out" << endl
					 << endl;
			}
		} while (cin.fail() || quanOrder <= 0);

		amount = amount + quanOrder * items[selection - 1].price; //calculation

		cout << "Kitchen is still open, will this complete your order? "; //last termination
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

void getItems(menuItem items[], int &size, ifstream &infile)
{
	size = 0;
	while (!infile.eof())
	{ //assign values into 3 diffrent arrays
		infile >> items[size].itemName >> items[size].price >> items[size].quantity;
		//cout<<items[size].itemName<<" ";
		//cout<<items[size].price<<" ";
		//cout<<items[size].quantity<<" "<<endl;
		size++;
	}
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
//void sortItemsByQuantity(string itemNames[], int quantities[], double prices[], int size){
void sortItemsByQuantity(menuItem items[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 2; j++)
		{
			//if you flip the inequality, it will sort //the array from highest to lowest
			if (items[j].quantity > items[j + 1].quantity) //swap 3 diffrent arrays
			{
				swap(items[j].quantity, items[j + 1].quantity);
				swap(items[j].itemName, items[j + 1].itemName);
				swap(items[j].price, items[j + 1].price);
			}
		}
	}
	return;
}

//void sortItemsByQuantity(menuItem items[], int size) {}

void outputItem(string itemNames, int itemLen, double prices, int priceLen)
{
	cout << left << setw(itemLen) << setfill(' ') << itemNames << "$";
	cout << setw(priceLen) << setfill(' ') << right << fixed << setprecision(2) << prices << endl;
}
