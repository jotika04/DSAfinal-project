
#ifndef FINALPROJECTSHOP_SHOP_H
#define FINALPROJECTSHOP_SHOP_H

#include "Product.h"
#include <vector>
#include <iostream>
using namespace std;

/**
 * class to store the vector
 */
class Shop {
public:

    string name, type;
    int opt, qty;
    unsigned int price;
    vector<Product> ShopItemList;

};


#endif //FINALPROJECTSHOP_SHOP_H
