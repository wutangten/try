/************************************************************************
//
//  Filename: 004.1_Billing.cpp
//
//  Code Description:
//		A basic program to practice struct (user-defined data type).
//		Create 8-arrays of struct.
//		Initialize the item names and prices.
//		Output the menu with format.
//
//  Updated by brucederland on 08/18/19.
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <iomanip>  /* Formatting library */
using namespace std;

const int arrSize = 8;

struct menuItemType /* Struct Definition (Always put it in front of all function ) */
{
	/* Struct members */
	string menuItem;
	double menuPrice;
};

/* Function Prototypes */
void getData(menuItemType menuList[]);  /* Initialize the items and prices */
void showMenu(menuItemType menuList[]); /* Output the menu with format */

int main()
{
	menuItemType menuList[arrSize]; /* Arrays of Structs, total 8 structs here */
									/*
										Data type: menuItemType
										Variable Name: menuList
										Size of the array: arrSize = 8
									*/
	getData(menuList);				/* Initialize the items and prices */
	showMenu(menuList);				/* Output the menu with format */
}

void getData(menuItemType menuList[]) /* Initialize the items and prices */
{

	menuList[0].menuItem = "Plain Egg";
	menuList[0].menuPrice = 1.45;
	menuList[1].menuItem = "Bacon and Egg";
	menuList[1].menuPrice = 2.45;
	menuList[2].menuItem = "Muffin";
	menuList[2].menuPrice = 0.99;
	menuList[3].menuItem = "French Toast";
	menuList[3].menuPrice = 1.99;
	menuList[4].menuItem = "Fruit Basket";
	menuList[4].menuPrice = 2.49;
	menuList[5].menuItem = "Cereal";
	menuList[5].menuPrice = 0.69;
	menuList[6].menuItem = "Coffee";
	menuList[6].menuPrice = 0.50;
	menuList[7].menuItem = "Tea";
	menuList[7].menuPrice = 0.75;
}

void showMenu(menuItemType menuList[]) /* Output the menu with format */
{
	for (int i = 0; i < arrSize; i++) /* Arrays of struct so use for-loop */
	{
		cout << left << setw(20);							 /* Align the text from the left */
		cout << menuList[i].menuItem << setfill(' ') << "$"; /* Fill with spaces and end with dollar sign */
		cout << menuList[i].menuPrice << endl;
	}
}