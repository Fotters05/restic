#pragma once

#include "menuitem.h"
#include <vector>
#include <string>

using namespace std;

class Order {
public:
    Order();

    int getId() const;
    string getStatus() const;
    void setStatus(const string& status);
    void addItem(const MenuItem& item);
    const vector<MenuItem>& getItems() const;
    bool isEmpty() const;
    double getTotalPrice() const;

    void display() const;

private:
    int id;
    string status;
    vector<MenuItem> items;
    static int nextId;
};
