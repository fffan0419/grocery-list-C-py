#include "splashkit.h"
#include "utilities.h"
#include "splashkit-arrays.h"

// Global grocery array and item counter (original unused global variables)
string grocery[100];
int count = 0;

/**
 * Display all items in the grocery list.
 * Shows message if list is empty. Pauses for user enter key.
 * @param grocery Array holding grocery item strings
 * @param count Number of valid items stored in array
 */
void view_list(string grocery[], int count)
{
    if (count == 0)
    {
        read_string("The grocery list is empty. Press Enter to continue.");
        return;
    }
    string output = "\n===== Grocery List =====\n";
    for (int i = 0; i < count; i++)
    {
        output = output + to_string(i + 1) + ". " + grocery[i] + "\n";
    }
    read_string(output + "\nPress Enter to continue.");
}

/**
 * Add new item to grocery list.
 * Will reject adding when list reaches max size 100.
 * @param grocery Array storing grocery items
 * @param count Reference to current number of items, increments on add
 */
void add_item(string grocery[], int &count)
{
    if(count >= 100)
    {
        read_string("List full, cannot add more items.");
        return;
    }
    string item = read_string("Enter item to add: ");
    grocery[count] = item;
    count++;
    read_string("Item added!\nPress Enter to continue.");
}

/**
 * Remove selected item by displayed list number.
 * Shifts remaining items forward to fill gap, decreases count.
 * @param grocery Array storing grocery items
 * @param count Reference to item counter, decreases after removal
 */
void remove_item(string grocery[], int &count)
{
    view_list(grocery, count);
    if (count == 0)
    {
        return;
    }
    int index = read_integer("Enter number of item to remove: ");
    if (index >= 1 && index <= count)
    {
        for(int i = index - 1; i < count -1; i++)
        {
            grocery[i] = grocery[i+1];
        }
        count--;
        read_string("Item removed!\nPress Enter to continue.");
    }
    else
    {
        read_string("Invalid number!\nPress Enter to continue.");
    }
}

/**
 * Main program: grocery list menu loop.
 * Presents menu, reads user choice and calls corresponding functions.
 * Exits loop when user selects option 4.
 * @return int Program exit status
 */
int main()
{
    string groceryList[100];
    int itemCount = 0;
    int choice;
    while(true)
    {
        string menu_text = "\n===== MENU =====\n"
                      "1. View grocery list\n"
                      "2. Add item\n"
                      "3. Remove item\n"
                      "4. Exit\n"
                      "Enter your choice: ";
        choice = read_integer(menu_text);
        if(choice == 1)
        {
            view_list(groceryList, itemCount);
        }
        else if(choice == 2)
        {
            add_item(groceryList, itemCount);
        }
        else if(choice == 3)
        {
            remove_item(groceryList, itemCount);
        }
        else if(choice == 4)
        {
            read_string("Program exit.\nPress Enter to close.");
            break;
        }
        else
        {
            read_string("Invalid option, try again.\nPress Enter to continue.");
        }
    }
    return 0;
}