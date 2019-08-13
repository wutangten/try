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
#include <iomanip>
using namespace std;

const int arrSize=8;
struct menuItemType
{
	string menuItem;
	double menuPrice;
};

void getData(menuItemType menuList[])
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

void showMenu(menuItemType menuList[])
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << left << setw(20) << menuList[i].menuItem << setfill(' ') << "$"<<menuList[i].menuPrice<<endl;
	}
}
void printCheck(menuItemType menuList[])
{}

int main()
{
	menuItemType menuList[arrSize];
	getData(menuList);
	showMenu(menuList);
}