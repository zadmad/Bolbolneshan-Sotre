#include "Store.h"
#include <iostream>

Store::Store() : numProducts(0), numOrders(0) {}

Store::~Store() {
    for (int i = 0; i < numProducts; ++i) {
        delete products[i];
    }
}

void Store::addProduct(Product* product) {
    if (numProducts < MAX_PRODUCTS) {
        products[numProducts++] = product;
    } else {
        std::cout << "Store is full, cannot add more products." << std::endl;
    }
}

void Store::createOrder() {
    std::cout << "Available Products:" << std::endl;
    for (int i = 0; i < numProducts; ++i) {
        products[i]->displayInfo();
    }

    int id, quantity;
    std::cout << "Enter product ID and quantity (0 0 to finish): "<< std::endl;
    std::cout << "ID= ";
    std::cin >> id;
    std::cout<< "quantity= ";
    std::cin >> quantity;

    while (id != 0 && quantity != 0) {
        bool found = false;
        for (int i = 0; i < numProducts; ++i) {
            if (products[i]->getId() == id) {
                if (products[i]->reduceQuantity(quantity)) {
                    if (numOrders < MAX_ORDERS) {
                        orders[numOrders++] = {id, quantity};
                        std::cout << "Added " << quantity << " units of ";
                        products[i]->displayInfo();
                    } else {
                        std::cout << "Cannot place more orders, order list is full.\n";
                    }
                } else {
                    std::cout << "Not enough stock available for ";
                    products[i]->displayInfo();
                }
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Product with ID " << id << " not found." << std::endl;
        }
        std::cout << "Enter product ID and quantity (0 0 to finish): "<< std::endl;
        std::cout << "ID= ";
        std::cin >> id;
        std::cout<< "quantity= ";
        std::cin >> quantity;
    }
}

void Store::showProducts() const {
    std::cout << "Current Products in Store:" << std::endl;
    for (int i = 0; i < numProducts; ++i) {
        products[i]->displayInfo();
    }
}

void Store::showOrders() const {
    double totalPrice = 0.0;
    std::cout << "Current Orders:" << std::endl;
    for (int i = 0; i < numOrders; ++i) {
        int id = orders[i].productId;
        int quantity = orders[i].quantity;
        for (int j = 0; j < numProducts; ++j) {
            if (products[j]->getId() == id) {
                double price = products[j]->calculateTotalPrice(quantity);
                std::cout << "ID: " << id << ", Name: " << products[j]->getName() 
                          << ", Quantity: " << quantity << ", Total Price: $" << price << std::endl;
                totalPrice += price;
                break;
            }
        }
    }
    std::cout << "Total Price to Pay: $" << totalPrice << std::endl;
}
