def view_list(grocery, count):
    """Display all grocery items. Show empty message when no items.

    Args:
        grocery: list storing grocery items, max size 100
        count: number of valid items in the list
    """
    if count == 0:
        print("The grocery list is empty.")
        input("Press Enter to continue.")
        return
    print("\n===== Grocery List =====")
    for i in range(count):
        print(f"{i+1}. {grocery[i]}")
    input("\nPress Enter to continue.")

def add_item(grocery, count):
    """Add new grocery item. Return updated item count.
    Reject new item if list hits max capacity of 100.

    Args:
        grocery: list storing grocery items, max size 100
        count: current number of items

    Returns:
        int: updated item count after adding
    """
    if count >= 100:
        print("List full, cannot add more items.")
        input("Press Enter to continue.")
        return count
    item = input("Enter item to add: ")
    grocery[count] = item
    count = count + 1
    print("Item added!")
    input("Press Enter to continue.")
    return count

def remove_item(grocery, count):
    """Remove selected item by displayed number. Shift items to fill gap.
    Handles non‑integer user input errors. Return updated count.

    Args:
        grocery: list storing grocery items, max size 100
        count: current number of items

    Returns:
        int: updated item count after removal
    """
    view_list(grocery, count)
    if count == 0:
        return count
    try:
        index = int(input("Enter number of item to remove: "))
        if 1 <= index <= count:
            for i in range(index - 1, count - 1):
                grocery[i] = grocery[i + 1]
            count = count - 1
            print("Item removed!")
        else:
            print("Invalid number!")
    except ValueError:
        print("Please enter a valid integer.")
    input("Press Enter to continue.")
    return count

def main():
    """Main program loop: show menu, handle user menu choices."""
    grocery_list = [""] * 100
    item_count = 0
    while True:
        print("\n===== MENU =====")
        print("1. View grocery list")
        print("2. Add item")
        print("3. Remove item")
        print("4. Exit")
        choice = input("Enter your choice: ")
        if choice == "1":
            view_list(grocery_list, item_count)
        elif choice == "2":
            item_count = add_item(grocery_list, item_count)
        elif choice == "3":
            item_count = remove_item(grocery_list, item_count)
        elif choice == "4":
            print("Program exit.")
            input("Press Enter to close.")
            break
        else:
            print("Invalid option, try again.")
            input("Press Enter to continue.")

if __name__ == "__main__":
    main()