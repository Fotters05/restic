#include "order.h"
#include "menuitem.h"
#include <iostream>

using namespace std;

int Order::nextId = 1;

Order::Order() : id(nextId++), status("�����") {}

int Order::getId() const {
    return id;
}

string Order::getStatus() const {
    return status;
}

void Order::setStatus(const string& status) {
    this->status = status;
}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

const vector<MenuItem>& Order::getItems() const {
    return items;
}

bool Order::isEmpty() const {
    return items.empty();
}

double Order::getTotalPrice() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
    return total;
}

void Order::display() const {
    cout << "����� ������: " << id << ", ������: " << status << endl;
    cout << "�������� � ������:" << endl;
    for (const auto& item : items) {
        cout << "- " << item.getName() << " " << item.getPrice() << " ���." << endl;
    }
}
