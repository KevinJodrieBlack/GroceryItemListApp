#include "UserMenu.h"
#include "GroceryItemList.h"
#include <iostream>
#include <limits>

// Function to start the user menu system
void UserMenu::RunUserMenu(GroceryItemList& t_itemList)
{
    OpenMainMenu(t_itemList); // Open the main menu
}

// Function to get a string input from the user
string UserMenu::GetStringFromInput(string t_message)
{
    cout << endl;
    cout << t_message; // Display the provided message
    string userInput = "";
    cin >> userInput; // Read user input
    return userInput; // Return the input string
}

// Function to get an integer input from the user within a specified range
int UserMenu::GetIntFromInput(string t_message, int t_minRange, int t_maxRange)
{
    cout << endl;

    while (true) {
        cout << t_message; // Display the provided message

        int userInput = 0;
        cin >> userInput; // Read user input

        // Check if input is invalid (e.g., non-integer)
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input, please try again" << endl; // Prompt user to retry
        }
        // Check if input is outside the specified range
        else if (userInput < t_minRange || userInput > t_maxRange) {
            cout << "Invalid input, please try again" << endl; // Prompt user to retry
        }
        // If input is valid, return it
        else {
            return userInput;
        }
    }
}

// Function to display the main menu and handle user choices
void UserMenu::OpenMainMenu(GroceryItemList& t_itemList)
{
    cout << endl;

    // Display the main menu options
    cout << "Select which operation to perform." << endl;
    cout << "1) Search item by name" << endl;
    cout << "2) Get all item counts (numeric)" << endl;
    cout << "3) Get all item counts (*)" << endl;
    cout << "4) Exit" << endl;

    cout << endl;

    // Get user input for menu selection (1-4)
    int response = GetIntFromInput("Select option 1-4: ", 1, 4);

    cout << endl;

    // Handle the user's choice
    switch (response) {

    case 1:
        OpenNameSearchMenu(t_itemList); // Open the name search menu
        break;

    case 2:
        t_itemList.PrintFullGroceryList(); // Print the full grocery list with numeric counts
        OpenMainMenu(t_itemList); // Return to the main menu
        break;

    case 3:
        t_itemList.PrintListHistogram(); // Print the grocery list as a histogram
        OpenMainMenu(t_itemList); // Return to the main menu
        break;

    case 4:
        break; // Exit the menu system

    default:
        cout << endl;
        cout << "Invalid input. Please try again" << endl; // Handle invalid input
        cout << endl;
        OpenMainMenu(t_itemList); // Return to the main menu
        break;
    }
}

// Function to handle searching for an item by name
void UserMenu::OpenNameSearchMenu(GroceryItemList& t_itemList)
{
    // Get the item name to search for
    string nameToSearch = GetStringFromInput("Enter item name: ");

    cout << endl;

    // Search for the item in the grocery list
    t_itemList.FindItemByName(nameToSearch);

    cout << endl;

    // Return to the main menu
    OpenMainMenu(t_itemList);
}
