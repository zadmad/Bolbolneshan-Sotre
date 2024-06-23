#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Product(int id, const std::string& name, double price, int quantity);
    virtual ~Product();

    virtual double calculateTotalPrice(int count) const;
    virtual void displayInfo() const;

    int getId() const;
    int getQuantity() const;
    void addQuantity(int amount);
    bool reduceQuantity(int amount);

    std::string getName() const;
};

class PerishableProduct : public Product {
public:
    PerishableProduct(int id, const std::string& name, double price, int quantity);
    double calculateTotalPrice(int count) const override;
    void displayInfo() const override;
};

class ImperishableProduct : public Product {
public:
    ImperishableProduct(int id, const std::string& name, double price, int quantity);
    double calculateTotalPrice(int count) const override;
    void displayInfo() const override;
};

#endif
