#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

using namespace std;

class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem(const string& name, double price);

    string getName() const;
    double getPrice() const;
};


bool removeMenuItem(vector<MenuItem>& menu, const string& itemName);

#endif 
