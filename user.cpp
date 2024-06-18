#include "user.h"

using namespace std;

User::User(const string& login, const string& password)
    : login(login), password(password) {}

string User::getLogin() const {
    return login;
}

string User::getPassword() const {
    return password;
}
