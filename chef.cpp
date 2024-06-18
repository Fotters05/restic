#include <iostream>
#include "chef.h"

using namespace std;

Chef::Chef(const string& name) : name(name) {}

void Chef::selectItemsForPreparation(const vector<MenuItem>& menu, Order& order) {
    cout << "--- ���� ��� ������ ��������� ��� ������������� ---\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].getName() << " - $" << menu[i].getPrice() << "\n";
    }
    cout << "0. ��������� �����\n";

    vector<MenuItem> selectedItems;
    int choice;
    do {
        cout << "�������� ������� ��� ������������� (0 ��� ���������� ������): ";
        cin >> choice;

        if (choice > 0 && choice <= static_cast<int>(menu.size())) {
            selectedItems.push_back(menu[choice - 1]);
        }
        else if (choice != 0) {
            cout << "�������� �����. ���������� �����.\n";
        }
    } while (choice != 0);

    for (const auto& item : selectedItems) {
        order.addItem(item);
    }
}

void Chef::startPreparingOrder(Order& order) {
    if (order.getStatus() == "�������") {
        order.setStatus("� �������� �������������");
        cout << "������ ������������� ������.\n";
        const auto& items = order.getItems();
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "�������������: " << items[i].getName() << "\n";
        }
        order.setStatus("�����");
        cout << "����� �����.\n";
    }
    else {
        cout << "���������� ������ ������������� ������. ����� �� ������� ��� ��� ��������� � ������ ���������.\n";
    }
}

void Chef::viewOrders(const vector<Order>& orders) {
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
