//
// Created by jotika on 6/28/2019.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;


class Product{
private:
    string name;
    int qty;
    unsigned int price;
    string type;

public:
    const string &getName() const;

    void setName(const string &name);

    int getQty() const;

    void setQty(int qty);

    unsigned int getPrice() const;

    void setPrice(unsigned int price);

    const string &getType() const;

    void setType(const string &type);

    Product();
    Product(string n, int q, unsigned int p, string t);

};


#endif

