#include "admin.h"
#include "menuitem.h" 
#include <algorithm>
#include <iostream>

using namespace std;

Admin::Admin(const string& name, const string& password) : name(name), password(password) {}

void Admin::addMenuItem(vector<MenuItem>& items, const string& name, double price) {
    items.emplace_back(name, price);
}

void Admin::removeMenuItem(vector<MenuItem>& items, const string& name) {
    items.erase(remove_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == name;
        }), items.end());
}

void Admin::addEmployee(vector<Employee>& employees, const string& role, const string& lastName, const string& firstName, const string& middleName, const string& login, const string& password) {
    employees.emplace_back(role, lastName, firstName, middleName, login, password);
}

void Admin::removeEmployee(vector<Employee>& employees, const string& login) {
    employees.erase(remove_if(employees.begin(), employees.end(), [&](const Employee& emp) {
        return emp.getLogin() == login;
        }), employees.end());
}

void Admin::editEmployee(vector<Employee>& employees, const string& login) {
    auto it = find_if(employees.begin(), employees.end(), [&](const Employee& emp) {
        return emp.getLogin() == login;
        });

    if (it != employees.end()) {
        string newRole, newLastName, newFirstName, newMiddleName, newPassword;
        cout << "¬ведите новую роль: ";
        cin >> newRole;
        cout << "¬ведите новую фамилию: ";
        cin >> newLastName;
        cout << "¬ведите новое им€: ";
        cin >> newFirstName;
        cout << "¬ведите новое отчество: ";
        cin >> newMiddleName;
        cout << "¬ведите новый пароль: ";
        cin >> newPassword;

        it->setRole(newRole);
        it->setLastName(newLastName);
        it->setFirstName(newFirstName);
        it->setMiddleName(newMiddleName);
        it->setPassword(newPassword);
    }
    else {
        cout << "—отрудник с логином " << login << " не найден.\n";
    }
}
