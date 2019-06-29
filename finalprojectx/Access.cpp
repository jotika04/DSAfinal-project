//
// Created by jotika on 6/28/2019.
//

#include "Access.h"
/**
 * saves all of the data in a txt file
 */
void Access::savefile() {
    ofstream shopfile;
    string name,type;
    int qty;
    unsigned int price;
    shopfile.open("shopdata.txt");

    for (int i = 0;i<shop.ShopItemList.size();i++)
    {
    name = shop.ShopItemList[i].getName();
    qty = shop.ShopItemList[i].getQty();
    price = shop.ShopItemList[i].getPrice();
    type = shop.ShopItemList[i].getType();
    shopfile << name << " "<< qty <<" "<<price<<" "<<type<<endl;
    }
}
/**
 * load the file from the txt file
 */
void Access::loadfile() {
    ifstream infile("shopdata.txt");
    if (infile.fail())
    {
        cerr<<"Error opening file"<<endl;
        exit(1);
    }

    if(infile.is_open())
    {
        while (infile >> name >> qty >> price >> type)
        {
            Product pro(name,qty,price,type);
            shop.ShopItemList.push_back(pro);
        }
        infile.close();
    }
    else
    {
        cout << "file is not opened" << endl;
    }
}

/**
 * adds the data to the vector
 * @param p
 */
void Access::add(Product p)
{
    shop.ShopItemList.push_back(p);
}
/**
 * deletes item from the vector
 * @param key name of item to be deleted
 * @return
 */
bool Access::del(string key)
{
    for (vector<Product>::iterator stritr = shop.ShopItemList.begin(); stritr != shop.ShopItemList.end();++stritr) {
        if (stritr->getName() == key){
            shop.ShopItemList.erase(stritr);
            return true;
        }
    }
    return  false;
}
/**
 * view the data of items to sell
 */
void Access::viewall()
{
    for(vector<Product>::iterator stritr = shop.ShopItemList.begin();
        stritr != shop.ShopItemList.end();++stritr){
        cout<<">>"<<stritr->getName()<<"|"<<stritr->getQty()<<"|"<<stritr->getPrice()<<
            "|"<<stritr->getType()<<endl;
    }
}
/**
 * updates the information from admin
 * @param key name of updated data
 * @return false because of failed updating
 */
bool Access::update(string key)
{
    for (vector<Product>::iterator strItr = shop.ShopItemList.begin(); strItr != shop.ShopItemList.end(); ++strItr){
        if (strItr->getName() == key){
            cout << "change name? (Y/N): "; cin >> confirm;
            if(confirm == "Y" || confirm == "y"){
                cout << "change name to: "; cin >> name;
                strItr->setName(name);
            }else
                strItr->getName();

            cout << "change type? (Y/N): "; cin >> confirm;
            if(confirm == "Y" || confirm == "y"){
                cout << "change name to: "; cin >> type;
                strItr->setType(type);
            }else
                strItr->getType();

            cout << "change quantity? (Y/N): "; cin >> confirm;
            if(confirm == "Y" || confirm == "y"){
                cout << "change quantity to: "; cin >> qty;
                strItr->setQty(qty);
            }else
                strItr->getQty();

            cout << "change price? (Y/N): "; cin >> confirm;
            if(confirm == "Y" || confirm == "y"){
                cout << "change price to: "; cin >> price;
                strItr->setPrice(price);
            }else
                strItr->getPrice();

            return true;
        }
    }
    return false;
}
/**
 * user interface for the admin
 */
void Access::adminInterface()
{
    bool flag = true;
    while(flag == true){
        cout << "1.Add item \n2.update item \n3.delete item \n4.view item \n5.Back to menu" << endl;
        cin >> opt;
        switch (opt){
            case 1: {
                cout << "product name: ";
                cin >> name;
                cout << "quantity: ";
                cin >> qty;
                cout << "price: ";
                cin >> price;
                cout << "type: ";
                cin >> type;
                Product product(name, qty, price, type);
                add(product);
                break;
            }
            case 2: {
                cout << "name of the product that you want to update: " << endl;
                cin >> name;
                if(update(name)){
                    cout << "updated" << endl;
                }else{
                    cout << "can not found product named "<< name << endl;
                }
                break;}

            case 3:
                cout << "name of the product that you want to delete: " << endl;
                cin >> name;
                if(del(name)){
                    cout << "delete end" << endl;
                }else
                    cout << "can not found product " << name << endl;
                break;

            case 4:
                viewall();
                break;

            case 5:
                flag = false;
        }
    }
}

/**
 * method to list all of what the buyer bought
 * @param key  name of the product
 */
void Access::buy(string key)
{
    for (vector<Product>::iterator strItr = shop.ShopItemList.begin(); strItr != shop.ShopItemList.end(); ++strItr){
        if (strItr->getName() == key) {
            cout << "how much? " << endl; cin >> qty;

            buying.setQuantity(qty);
            string n = strItr->getName();
            string t = strItr->getType();

            unsigned int p = strItr->getPrice();
            buyList.push_back(Product(n, qty, p, t));
            strItr -> setQty(strItr->getQty()-qty);
        }
    }
}
/**
 * the total amount of things bought
 */
void Access::bill() {
    unsigned int totalPrice = 0;

    for(vector<Product>::iterator stritr = buyList.begin();stritr != buyList.end();++stritr){
        cout << stritr->getName()<<  "||amount: " << stritr->getQty() << "|| Rp." << stritr->getPrice() << endl;
        totalPrice = totalPrice + (stritr->getPrice() * stritr->getQty());
    }
    cout << "total price: Rp." << totalPrice << endl;
}

void Access::viewshopitem()
{
    for(vector<Product>::iterator stritr = shop.ShopItemList.begin();stritr != shop.ShopItemList.end();++stritr){
        cout<<">>"<<stritr->getName()<<"|"<<stritr->getQty()<<"|"<<stritr->getPrice()<<
            "|"<<stritr->getType()<<endl;
    }
}
/**
 * view items thats already bought
 */
void Access::viewboughtitems() {
    int number = 0;
    for(vector<Product>::iterator stritr = buyList.begin();
        stritr != buyList.end();++stritr){
        cout<<number + 1 << ". "<<stritr->getName()<<"||amount: "<<stritr->getQty() <<"||Rp." << stritr->getPrice()
            << endl;
    }}

void Access::customerinterface()
{
    bool flag = true;
    while(flag == true) {
        cout << "1.Buy Item \n2.view bought list\n3.View Shop \n4.bills \n5.Exit Shop" << endl;
        cin >> opt;
        switch (opt) {
            case 1: {
                cout << "product name: ";
                cin >> name;
                buy(name);

                break;
            }
            case 2: {
                viewboughtitems();
                break;
            }
            case 3:
                viewshopitem();
                break;
            case 4:
                bill();
                break;
            case 5:
                buyList.clear();
                flag = false;
        }
    }

    }


