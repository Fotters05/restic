#include "employee.h"

using namespace std;

Employee::Employee(const string& name, const string& login, const string& password)
    : name(name), login(login), password(password) {}

Employee::Employee(const string& name, const string& password)
    : name(name), password(password) {}

Employee::Employee(const string& role, const string& lastName, const string& firstName,
    const string& middleName, const string& login, const string& password)
    : role(role), lastName(lastName), firstName(firstName), middleName(middleName), login(login), password(password) {}

string Employee::getName() const {
    return name;
}

string Employee::getLogin() const {
    return login;
}

string Employee::getPassword() const {
    return password;
}

string Employee::getRole() const {
    return role;
}

string Employee::getLastName() const {
    return lastName;
}

string Employee::getFirstName() const {
    return firstName;
}

string Employee::getMiddleName() const {
    return middleName;
}

void Employee::setRole(const string& newRole) {
    role = newRole;
}

void Employee::setLastName(const string& newLastName) {
    lastName = newLastName;
}

void Employee::setFirstName(const string& newFirstName) {
    firstName = newFirstName;
}

void Employee::setMiddleName(const string& newMiddleName) {
    middleName = newMiddleName;
}

void Employee::setPassword(const string& newPassword) {
    password = newPassword;
}

void Employee::setLogin(const string& newLogin) {
    login = newLogin;
}
