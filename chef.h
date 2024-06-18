#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <vector>
#include "order.h"  

using namespace std;

class Chef {
public:
    Chef(const string& name);
    void selectItemsForPreparation(const vector<MenuItem>& menu, Order& order);
    void startPreparingOrder(Order& order);
    void viewOrders(const vector<Order>& orders);

private:
    string name;
};

#endif  
