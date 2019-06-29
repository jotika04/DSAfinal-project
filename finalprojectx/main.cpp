#include <iostream>
#include "Shop.cpp"
#include "Access.h"

int main() {
    Shop shop;
    Access access;

    string name, type, confirm;
    int opt;

    bool flag = true;
    access.loadfile();
    while(flag == true){
        cout << "login as: \n1.Admin \n2.Customer \n3.exit \nchoice: "; cin >> opt;
        if(opt == 1){
            access.adminInterface();
        }
        else if(opt == 2){
            access.customerinterface();
        }
        else if(opt == 3){
            flag = false;
        }
    }access.savefile();

    return 0;
}