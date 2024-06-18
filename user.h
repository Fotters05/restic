#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
public:
    User(const string& login, const string& password);
    virtual ~User() = default;

    string getLogin() const;
    string getPassword() const;

private:
    string login;
    string password;
};

#endif
