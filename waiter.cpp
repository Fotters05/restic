#include "waiter.h"
#include <iostream>

using namespace std;

Waiter::Waiter(const string& name, const string& password)
    : Employee(name, password) {}

void Waiter::viewOrders(const vector<Order>& orders) {
    cout << "--- Список заказов ---\n";
    for (const auto& order : orders) {
        cout << "Заказ #" << order.getId() << " - Статус: " << order.getStatus() << "\n";
        const auto& items = order.getItems();
        cout << "Пункты заказа:\n";
        for (const auto& item : items) {
            cout << "- " << item.getName() << " " << item.getPrice() << " Руб" << "\n";
        }
        cout << "\n";
    }
}

void Waiter::receiveOrder(Order& order) {
    cout << "Официант" << " получил заказ #" << order.getId() << ".\n";
}

void Waiter::deliverOrder(Order& order) {
    cout << "Официант" << " доставил заказ #" << order.getId() << " клиенту.\n";
}
