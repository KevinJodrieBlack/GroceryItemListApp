#pragma once
#include "GroceryItem.h"
#include <vector>

using namespace std;

class GroceryItemList
{
private:

	vector<GroceryItem> m_groceryItemArray;

public:

	//Function to either create or add to grocery item depending on name
	void ReceiveItemInput(const string t_itemName);

	//Print name and quantity (integer) for entire list
	void PrintFullGroceryList();

	//Print name and quantity (histogram) for entire list
	void PrintListHistogram();

	//Function to print name and quantity for individual items
	void PrintItemInfo(const GroceryItem& t_groceryItem);

	//Function to find item in list via name
	void FindItemByName(const string t_name);

	//Saves list to output file
	void SaveItemListToFile();

private:

	//Creates and adds grocery item to list
	void CreateGroceryItem(const string t_itemName);

};

