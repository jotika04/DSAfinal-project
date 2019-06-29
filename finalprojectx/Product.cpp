//
// Created by jotika on 6/28/2019.
//

#include "Product.h"

Product::Product() {
    this->name = "";
    this->qty = 0;
    this->price = 0;
    this->type = "";
}

Product::Product(string n, int q, unsigned int p, string t) {
    this->name = n;
    this->qty = q;
    this->price = p;
    this->type = t;
}


const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

int Product::getQty() const {
    return qty;
}

void Product::setQty(int qty) {
    Product::qty = qty;
}

unsigned int Product::getPrice() const {
    return price;
}

void Product::setPrice(unsigned int price) {
    Product::price = price;
}

const string &Product::getType() const {
    return type;
}

void Product::setType(const string &type) {
    Product::type = type;
}
