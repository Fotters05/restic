#include "restaurantsystem.h"
#include "guest.h"
#include "employee.h"
#include <iostream>

using namespace std;

void someFunction() {
    Guest guest("login", "password");
    Order order;

    guest.trackOrderStatus(order);

    Employee employee("role", "lastName", "firstName", "middleName", "login", "password");

    string password = employee.getPassword();
    cout << "Password: " << password << endl;
}
