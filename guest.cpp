#include <iostream>  
#include "guest.h"

using namespace std;

Guest::Guest(const string& login, const string& password) : login(login), password(password) {}

void Guest::addToOrder(const Order& order) {
    orders.push_back(order);
}

void Guest::confirmOrder() {

}

void Guest::trackOrderStatus(const Order& order) {
    cout << "Статус заказа: " << order.getStatus() << endl;
}

