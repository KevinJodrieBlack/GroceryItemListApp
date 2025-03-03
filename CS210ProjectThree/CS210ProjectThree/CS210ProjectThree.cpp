#include <iostream>
#include <fstream>
#include <string>
#include "GroceryItemList.h"
#include "UserMenu.h"

using namespace std;

// Static instance of GroceryItemList to store grocery items
static GroceryItemList m_groceryItemList = GroceryItemList();

// Instance of UserMenu to handle user interactions
UserMenu m_userMenu = UserMenu();

// Function to read grocery item data from a file
static void ReadInfoFromFile() {
    // Open the input file
    ifstream file("/Users/kevin/OneDrive/Desktop/CS210_Project_Three_Input_File.txt");

    // Check if the file was successfully opened
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        // Pass each line to the grocery item list for processing
        m_groceryItemList.ReceiveItemInput(line);
    }

    // Close the file after reading
    file.close();
}

// Main function to run the application
int main()
{
    // Read grocery item data from the input file
    ReadInfoFromFile();

    // Save the grocery item list to an output file
    m_groceryItemList.SaveItemListToFile();

    // Run the user menu to interact with the grocery item list
    m_userMenu.RunUserMenu(m_groceryItemList);

    // Notify the user that the application is exiting
    cout << "Exiting application" << endl;

    return 0; // Indicate successful program termination
}

