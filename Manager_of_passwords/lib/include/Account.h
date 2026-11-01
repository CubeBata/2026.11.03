#ifndef Account_H
#define Account_H
#include <string>
struct Account
{
    std::string login;
    std::string password;
    Account operator= (const Account& other);
};
#endif //Account_H