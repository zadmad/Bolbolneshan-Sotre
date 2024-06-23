#include "Product.h"
#include "Store.h"
#include <iostream>

using namespace std;

void clearscreen();
void banner();
void keytoexit();
void case1(Store& store);

int main() {
    banner(); 

    Store store;

    int choice;
    do {
        cout << "\n1. Add Product\n2. Create Order\n3. Show Products\n4. Show Orders\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                case1(store);
                keytoexit();
                break;
            case 2:
                store.createOrder();
                keytoexit();
                break;
            case 3:
                store.showProducts();
                keytoexit();
                break;
            case 4:
                store.showOrders();
                keytoexit();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                keytoexit();
        }
    } while (choice != 5);

    return 0;
}

void case1(Store& store) {
    char more;
    do {
        int type;
        cout << "Enter type of product (1 - Perishable, 2 - Imperishable): ";
        cin >> type;
        int id;
        string name;
        double price;
        int quantity;
        cout << "Enter ID, Name, Price, Quantity: "<< endl;
        cout << "ID= ";
        cin >> id;
        cout << "Name= ";
        cin >> name;
        cout << "Price= ";
        cin >> price;
        cout << "Quantity= ";
        cin >> quantity;
        if (type == 1) {
            store.addProduct(new PerishableProduct(id, name, price, quantity));
        } else if (type == 2) {
            store.addProduct(new ImperishableProduct(id, name, price, quantity));
        } else {
            cout << "Invalid product type.\n";
        }
        cout << "Do you want to add more products? (y/n): ";
        cin >> more;
    } while (more == 'y');
}

void clearscreen() {
    system("cls");
}

void banner() {
    system("color 8F");
    cout << " ---------------------------------------------------------" << endl;
    cout << "\t\t\tBolbolneshan Store " << endl;
    cout << " ---------------------------------------------------------" << endl;
}

void keytoexit() {
    cout << "Exit by pressing any key!" << endl;
    cin.ignore();
    cin.get();
    clearscreen();
}
