#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string& name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

Product::~Product() {}

double Product::calculateTotalPrice(int count) const {
    return count * price;
}

void Product::displayInfo() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", Quantity: " << quantity << std::endl;
}

int Product::getId() const {
    return id;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::addQuantity(int amount) {
    quantity += amount;
}

bool Product::reduceQuantity(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false;
}

std::string Product::getName() const {
    return name;
}

PerishableProduct::PerishableProduct(int id, const std::string& name, double price, int quantity)
    : Product(id, name, price, quantity) {}

double PerishableProduct::calculateTotalPrice(int count) const {
    return count * price;
}

void PerishableProduct::displayInfo() const {
    std::cout << "Perishable ";
    Product::displayInfo();
}

ImperishableProduct::ImperishableProduct(int id, const std::string& name, double price, int quantity)
    : Product(id, name, price, quantity) {}

double ImperishableProduct::calculateTotalPrice(int count) const {
    return count * price;
}

void ImperishableProduct::displayInfo() const {
    std::cout << "Imperishable ";
    Product::displayInfo();
}
