//
// Created by jotika on 6/28/2019.
//

#include "Buying.h"


void Buying::setQuantity(int q){
    this->quantity = q;
}

void Buying::setName(string n){
    this->name = n;
}

void Buying::setType(string t){
    this->type = t;
}

void Buying::setPrice(unsigned int p){
    this->price = p;
}

unsigned int Buying::getPrice(){
    return price;
}

int Buying::getQuantity() {
    return quantity;
}

string Buying::getName() {
    return name;
}

string Buying::getType() {
    return type;
}

Buying::Buying(){
    this->name = "";
    this->quantity = 0;
    this->price = 0;
    this->type = "";
}

Buying::Buying(string n, int q, unsigned int p, string t) {
    this->name = n;
    this->quantity = q;
    this->price = p;
    this->type = t;
}
