#pragma once
#include <string>

using namespace std;

class GroceryItem
{
private:

	//Variables to store item name and quantity
	string m_itemName = "none";
	int m_itemQuantity = 1;

public:

	//Constructors to allow easy name assignment
	GroceryItem() {}
	GroceryItem(string t_itemName) : m_itemName(t_itemName) {}

	//Getter for name
	string GetItemName() const { return m_itemName; }

	//Function to increase quantity by 1
	void IncrementQuantity() { m_itemQuantity++; }

	//Getter for item quantity
	int GetItemQuantity() const { return m_itemQuantity; }
};

