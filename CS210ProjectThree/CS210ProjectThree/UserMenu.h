#pragma once
#include <string>

using namespace std;

class GroceryItemList;

class UserMenu
{
public:

	//Function to launch menu
	void RunUserMenu(GroceryItemList& t_itemList);

private:

	//Gets input from user as string
	string GetStringFromInput(string t_message);

	//Gets input from user as int
	int GetIntFromInput(string t_message, int t_minRange, int t_maxRange);

	//Opens main menu to select which operation to perform
	void OpenMainMenu(GroceryItemList& t_itemList);

	//Opens menu to search for item by name
	void OpenNameSearchMenu(GroceryItemList& t_itemList);
};

