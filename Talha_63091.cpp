#include <iostream>
#include <string>
using namespace std;

// ===============================================
// ITEM NODE STRUCTURE FOR LINKED LIST
// ===============================================
struct Item {
    int itemID;    
    string name;   
    string type; 
    string rarity;     
    int quantity;   

    Item* next;      
};

Item* head = nullptr;

int nextID = 1;


// ===============================================
// CREATE A NEW ITEM NODE
// ===============================================
Item* createItem(string name, string type, string rarity, int quantity) {
    Item* newItem = new Item();

    // Assign values
    newItem->itemID = nextID++;
    newItem->name = name;
    newItem->type = type;
    newItem->rarity = rarity;
    newItem->quantity = quantity;

    newItem->next = nullptr;

    return newItem;
}


// ===============================================
// ADD ITEM TO THE END OF LINKED LIST
// ===============================================
void addItem() {
    string name, type, rarity;
    int quantity;

    cout << "\nEnter Item Name (no spaces): ";
    cin >> name;

    cout << "Enter Item Type (no spaces): ";
    cin >> type;

    cout << "Enter Rarity (no spaces): ";
    cin >> rarity;

    cout << "Enter Quantity: ";
    cin >> quantity;

    // Create new node
    Item* newItem = createItem(name, type, rarity, quantity);

    if (head == nullptr) {
        head = newItem;
    }
    else {
        // Traverse to last node
        Item* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        // Insert new node at end
        temp->next = newItem;
    }

    cout << "\nItem added successfully! (ID: " << newItem->itemID << ")\n";
}


// ===============================================
// REMOVE ITEM BY ID
// ===============================================
void removeItem() {
    if (head == nullptr) {
        cout << "\nInventory is empty.\n";
        return;
    }

    int id;
    cout << "Enter Item ID to remove: ";
    cin >> id;

    Item* temp = head;
    Item* prev = nullptr;

    // Search for item
    while (temp != nullptr && temp->itemID != id) {
        prev = temp;
        temp = temp->next;
    }

    // Item not found
    if (temp == nullptr) {
        cout << "\nItem not found.\n";
        return;
    }

    // Removing head node
    if (prev == nullptr) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "\nItem removed successfully.\n";
}


// ===============================================
// SEARCH ITEM BY NAME
// ===============================================
void searchItem() {
    if (head == nullptr) {
        cout << "\nInventory is empty.\n";
        return;
    }

    string searchName;
    cout << "Enter Item Name to search (no spaces): ";
    cin >> searchName;

    Item* temp = head;
    bool found = false;

    // Traverse entire list
    while (temp != nullptr) {
        if (temp->name == searchName) {
            cout << "\nItem Found:\n";
            cout << "ID: " << temp->itemID << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Type: " << temp->type << endl;
            cout << "Rarity: " << temp->rarity << endl;
            cout << "Quantity: " << temp->quantity << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "\nNo item found with that name.\n";
}


// ===============================================
// UPDATE QUANTITY OF AN ITEM BY ID
// ===============================================
void updateQuantity() {
    if (head == nullptr) {
        cout << "\nInventory is empty.\n";
        return;
    }

    int id, newQty;
    cout << "Enter Item ID to update quantity: ";
    cin >> id;

    Item* temp = head;

    // Search for item
    while (temp != nullptr && temp->itemID != id)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "\nItem not found.\n";
        return;
    }

    cout << "Enter new quantity: ";
    cin >> newQty;

    temp->quantity = newQty;

    cout << "\nQuantity updated successfully!\n";
}


// ===============================================
// DISPLAY ENTIRE INVENTORY LIST
// ===============================================
void displayInventory() {
    if (head == nullptr) {
        cout << "\nInventory is empty.\n";
        return;
    }

    cout << "\n-------- INVENTORY ITEMS --------\n";

    Item* temp = head;

    // Traverse list and print each item
    while (temp != nullptr) {
        cout << "ID: " << temp->itemID << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Type: " << temp->type << endl;
        cout << "Rarity: " << temp->rarity << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "-----------------------------\n";
        temp = temp->next;
    }
}


// ===============================================
// MAIN MENU FUNCTION
// ===============================================
void menu() {
    int choice;

    do {
        cout << "\n========= GAME INVENTORY MANAGER =========\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Update Quantity\n";
        cout << "5. View All Items\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: removeItem(); break;
            case 3: searchItem(); break;
            case 4: updateQuantity(); break;
            case 5: displayInventory(); break;
            case 6: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 6);
}


// ===============================================
// MAIN FUNCTION
// ===============================================
int main() {
    menu();
    return 0;
}
