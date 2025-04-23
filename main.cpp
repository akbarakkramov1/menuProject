#include <iostream>
#include <iomanip>
using namespace std;

// Structure for menu items
struct MenuItem {
    int id;
    string name;
    float price;
};

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    cout << "\n========== MENU ==========\n";
    cout << "ID\tItem\t\tPrice\n";
    cout << "-------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << menu[i].id << "\t" << menu[i].name << "\t\t$" << fixed << setprecision(2) << menu[i].price << endl;
    }
    cout << "=========================\n";
}

int main() {
    const int MENU_SIZE = 6;
    MenuItem menu[MENU_SIZE] = {
        {1, "Burger", 5.99},
        {2, "Pizza", 8.99},
        {3, "Pasta", 7.50},
        {4, "Salad", 4.99},
        {5, "Soda", 1.50},
        {6, "Water", 1.00}
    };

    const int MAX_ORDER = 10; // Maximum items that can be ordered
    MenuItem order[MAX_ORDER];
    int orderCount = 0;
    int choice;
    char continueOrder;

    cout << "Welcome to Our Simple Restaurant!\n";

    do {
        displayMenu(menu, MENU_SIZE);

        cout << "\nEnter the ID of the item you want to order: ";
        cin >> choice;

        // Find the selected item
        bool found = false;
        for (int i = 0; i < MENU_SIZE; i++) {
            if (menu[i].id == choice) {
                order[orderCount] = menu[i];
                orderCount++;
                cout << menu[i].name << " added to your order.\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Invalid selection. Please try again.\n";
        }

        if (orderCount >= MAX_ORDER) {
            cout << "Maximum order limit reached.\n";
            break;
        }

        cout << "Would you like to order anything else? (y/n): ";
        cin >> continueOrder;

    } while ((continueOrder == 'y' || continueOrder == 'Y') && orderCount < MAX_ORDER);

    // Calculate total and display receipt
    if (orderCount > 0) {
        float total = 0.0;

        cout << "\n========= RECEIPT =========\n";
        cout << "Item\t\tPrice\n";
        cout << "-------------------------\n";

        for (int i = 0; i < orderCount; i++) {
            cout << order[i].name << "\t\t$" << order[i].price << endl;
            total += order[i].price;
        }

        cout << "-------------------------\n";
        cout << "TOTAL:\t\t$" << total << endl;
        cout << "=========================\n";
        cout << "Thank you for your order!\n";
    } else {
        cout << "No items were ordered. Goodbye!\n";
    }

    return 0;
}