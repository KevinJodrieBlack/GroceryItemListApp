#include "GroceryItemList.h"
#include <iostream>
#include <fstream>

void GroceryItemList::ReceiveItemInput(const string t_itemName)
{
	//Checks through list to see if name matches existing item
	for (int i = 0; i < m_groceryItemArray.size(); i++) {

		auto& groceryItem = m_groceryItemArray.at(i);

		if (t_itemName == groceryItem.GetItemName()) {

			//If item is found quantity is increased by 1
			groceryItem.IncrementQuantity();
			return;
		}
	}

	//Otherwise a new item is created
	CreateGroceryItem(t_itemName);
}

void GroceryItemList::PrintFullGroceryList()
{
	//Loop through list and print info for each item
	for (int i = 0; i < m_groceryItemArray.size(); i++) {
	
		const auto& groceryItem = m_groceryItemArray.at(i);
		PrintItemInfo(groceryItem);
	}
}

void GroceryItemList::PrintListHistogram()
{
	//Loop through list and print name
	for (int i = 0; i < m_groceryItemArray.size(); i++) {

		const auto& groceryItem = m_groceryItemArray.at(i);
		
		cout << groceryItem.GetItemName() << ": ";

		//Loop once again for the item quantity to add the * character
		for (int i = 0; i < groceryItem.GetItemQuantity(); i++) {
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;
}

void GroceryItemList::PrintItemInfo(const GroceryItem& t_groceryItem)
{
	//Print name and quantity for item
	cout << t_groceryItem.GetItemName() << ": " << t_groceryItem.GetItemQuantity() << endl;
}

void GroceryItemList::FindItemByName(const string t_name)
{
	//Loop through list comparing the names of each item
	for (int i = 0; i < m_groceryItemArray.size(); i++) {

		const GroceryItem& item = m_groceryItemArray[i];

		//If item is found, it's info is printed
		if (item.GetItemName() == t_name) {
			PrintItemInfo(item);
			return;
		}
	}

	//Otherwise the user is informed that the item is not in the list
	cout << "Item could not be found\n" << endl;
}

void GroceryItemList::SaveItemListToFile()
{
	//Create out file to store info
	ofstream file("/Users/kevin/OneDrive/Desktop/frequency.txt");

	//Throw error and return if file can't be opened
	if (!file.is_open()) {
		std::cerr << "Error writing to file!" << std::endl;
		return;
	}

	//Write infor for each item to file
	for (int i = 0; i < m_groceryItemArray.size(); i++) {

		GroceryItem& item = m_groceryItemArray[i];

		file << item.GetItemName() << ": " << item.GetItemQuantity() << endl;
	}

	file.close();
}

void GroceryItemList::CreateGroceryItem(const string t_itemName)
{
	//Create new item and add to list
	auto newGroceryItem = GroceryItem(t_itemName);
	m_groceryItemArray.push_back(newGroceryItem);
}
