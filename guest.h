#ifndef GUEST_H
#define GUEST_H

#include <vector>
#include "order.h"
#include "menuitem.h"

using namespace std;

class Guest {
public:
    Guest(const string& login, const string& password);
    void addToOrder(const Order& order);
    void confirmOrder();
    void trackOrderStatus(const Order& order);
private:
    string login;
    string password;
    vector<Order> orders;
};

#endif 
