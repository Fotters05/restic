#ifndef RESTAURANTSYSTEM_H
#define RESTAURANTSYSTEM_H

#include "guest.h"
#include "employee.h"
#include "product.h"
#include "menuitem.h"
#include "order.h"
#include <vector>
#include <string>

using namespace std;

class RestaurantSystem {
public:
    RestaurantSystem();
    void loadData();
    void saveData();
    void login(const string& login, const string& password);
    void guestLogin();
    void addMenuItem(const MenuItem& item);
    void addProduct(const Product& product);
    void addEmployee(const Employee& employee);

    void addToOrder(const Order& order);
    void confirmOrder();
    void trackOrderStatus() const;

private:
    vector<Guest> guests;
    vector<Employee> employees;
    vector<Product> products;
    vector<MenuItem> menuItems;
    vector<Order> orders;

    Guest* currentGuest;
    Employee* currentEmployee;
};

#endif 
