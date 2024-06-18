#ifndef RESTIC_H
#define RESTIC_H

#include "waiter.h"
#include "chef.h"
#include "admin.h"
#include <vector>
#include <string>
#include "MenuItem.h"
#include "Employee.h"
#include "Order.h"

void saveMenu(const vector<MenuItem>& menu, const string& filename);
void loadMenu(vector<MenuItem>& menu, const string& filename);
void saveEmployees(const vector<Employee>& employees, const string& filename);
void loadEmployees(vector<Employee>& employees, const string& filename);

void handleWaiterRole(Waiter& waiter, vector<Order>& orders);
void handleChefRole(Chef& chef, vector<Order>& orders);
void handleAdminRole(Admin& admin,
    vector<MenuItem>& fries,
    vector<MenuItem>& burgers,
    vector<MenuItem>& hotDrinks,
    vector<MenuItem>& drinks,
    vector<MenuItem>& desserts,
    vector<MenuItem>& iceCreams,
    vector<Employee>& employees);

#endif 
