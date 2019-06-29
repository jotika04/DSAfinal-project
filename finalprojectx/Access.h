//
// Created by jotika on 6/28/2019.
//

#ifndef FINALPROJECTSHOP_ACCESS_H
#define FINALPROJECTSHOP_ACCESS_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "Product.h"
#include "Shop.h"
#include "Buying.h"

class Access {
public:
    void add(Product p);
    bool update(string key);
    bool del(string key);
    Product search(string key);
    void viewall();

    void adminInterface();
    Shop shop;
    Buying buying;
    void buy(string key);

    void viewshopitem();
    void viewboughtitems();
    void customerinterface();
    void bill();

    void loadfile();
    void savefile();

    string name, type, confirm;
    int qty, opt;
    unsigned int price;

private:
    /**
     * vector for the buyer
     */
    vector<Product> buyList;

};


#endif //FINALPROJECTSHOP_ACCESS_H
