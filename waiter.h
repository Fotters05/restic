#ifndef WAITER_H
#define WAITER_H

#include "employee.h"
#include "order.h"
#include <vector>
#include <string>

using namespace std;

class Waiter : public Employee {
public:
    Waiter(const string& name, const string& password);

    void viewOrders(const vector<Order>& orders);
    void receiveOrder(Order& order);
    void deliverOrder(Order& order);
};

#endif
