#include <Account.h>

Account Account::operator=(const Account& other) {
    this->login = other.login;
    this->password = other.password;
}