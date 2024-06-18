#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include "menuitem.h"
#include "employee.h"

using namespace std;

class Admin {
public:
    Admin(const string& name, const string& password);

    void addMenuItem(vector<MenuItem>& items, const string& name, double price);
    void removeMenuItem(vector<MenuItem>& items, const string& name);
    void addEmployee(vector<Employee>& employees, const string& role, const string& lastName, const string& firstName, const string& middleName, const string& login, const string& password);
    void removeEmployee(vector<Employee>& employees, const string& login);
    void editEmployee(vector<Employee>& employees, const string& login);

private:
    string name;
    string password;
};

#endif
