//
// Created by jotika on 6/28/2019.
//

#ifndef FINALPROJECTX_BUYING_H
#define FINALPROJECTX_BUYING_H
#include <iostream>
using namespace std;

class Buying {

private:
    int quantity;
    string name;
    string type;
    unsigned int price;

public:
    Buying();
    Buying(string n, int q, unsigned int p, string t);
    void setQuantity(int q);

    void setName(string n);

    void setType(string t);

    void setPrice(unsigned int p);

    int getQuantity();
    unsigned int getPrice();
    string getType();
    string getName();

};


#endif //FINALPROJECTX_BUYING_H
