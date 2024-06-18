#include "waiter.h"
#include <iostream>

using namespace std;

Waiter::Waiter(const string& name, const string& password)
    : Employee(name, password) {}

void Waiter::viewOrders(const vector<Order>& orders) {
    cout << "--- ������ ������� ---\n";
    for (const auto& order : orders) {
        cout << "����� #" << order.getId() << " - ������: " << order.getStatus() << "\n";
        const auto& items = order.getItems();
        cout << "������ ������:\n";
        for (const auto& item : items) {
            cout << "- " << item.getName() << " " << item.getPrice() << " ���" << "\n";
        }
        cout << "\n";
    }
}

void Waiter::receiveOrder(Order& order) {
    cout << "��������" << " ������� ����� #" << order.getId() << ".\n";
}

void Waiter::deliverOrder(Order& order) {
    cout << "��������" << " �������� ����� #" << order.getId() << " �������.\n";
}
