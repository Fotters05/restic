#include <iostream>
#include "chef.h"

using namespace std;

Chef::Chef(const string& name) : name(name) {}

void Chef::selectItemsForPreparation(const vector<MenuItem>& menu, Order& order) {
    cout << "--- Меню для выбора продуктов для приготовления ---\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].getName() << " - $" << menu[i].getPrice() << "\n";
    }
    cout << "0. Завершить выбор\n";

    vector<MenuItem> selectedItems;
    int choice;
    do {
        cout << "Выберите продукт для приготовления (0 для завершения выбора): ";
        cin >> choice;

        if (choice > 0 && choice <= static_cast<int>(menu.size())) {
            selectedItems.push_back(menu[choice - 1]);
        }
        else if (choice != 0) {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    for (const auto& item : selectedItems) {
        order.addItem(item);
    }
}

void Chef::startPreparingOrder(Order& order) {
    if (order.getStatus() == "Оплачен") {
        order.setStatus("В процессе приготовления");
        cout << "Начало приготовления заказа.\n";
        const auto& items = order.getItems();
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "Приготовление: " << items[i].getName() << "\n";
        }
        order.setStatus("Готов");
        cout << "Заказ готов.\n";
    }
    else {
        cout << "Невозможно начать приготовление заказа. Заказ не оплачен или уже находится в другом состоянии.\n";
    }
}

void Chef::viewOrders(const vector<Order>& orders) {
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
