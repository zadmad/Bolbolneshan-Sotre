#ifndef STORE_H
#define STORE_H

#include "Product.h"

class Store {
private:
    static const int MAX_PRODUCTS = 100;
    static const int MAX_ORDERS = 100;
    Product* products[MAX_PRODUCTS];
    int numProducts;

    struct Order {
        int productId;
        int quantity;
    };
    Order orders[MAX_ORDERS];
    int numOrders;

public:
    Store();
    ~Store();

    void addProduct(Product* product);
    void createOrder();
    void showProducts() const;
    void showOrders() const;
};

#endif
