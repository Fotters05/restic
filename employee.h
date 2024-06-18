#pragma once

#include <string>

using namespace std;

class Employee {
public:
    Employee(const string& name, const string& login, const string& password);
    Employee(const string& name, const string& password);
    Employee(const string& role, const string& lastName, const string& firstName,
        const string& middleName, const string& login, const string& password);

    string getName() const;
    string getLogin() const;
    string getPassword() const;
    string getRole() const;
    string getLastName() const;
    string getFirstName() const;
    string getMiddleName() const;

    void setRole(const string& newRole);
    void setLastName(const string& newLastName);
    void setFirstName(const string& newFirstName);
    void setMiddleName(const string& newMiddleName);
    void setPassword(const string& newPassword);
    void setLogin(const string& newLogin);

private:
    string name;
    string login;
    string password;
    string role;
    string lastName;
    string firstName;
    string middleName;
};
