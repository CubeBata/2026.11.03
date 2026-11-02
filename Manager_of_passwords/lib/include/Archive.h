#ifndef Archive_H
#define Archive_H
#include <iostream>
#include <Account.h>
#include <map>
#include <vector>
#include <chrono>
#include <stdexcept>

class Archive
{
protected:
    std::map<std::string, std::vector<Account>> archive;
    bool NeedEdit = true;
    bool HasAccount = false;
    bool signed_in = false;
    Account User;
    std::chrono::steady_clock::time_point Updated;
    Archive() = default;
public:
    std::vector<Account> Get_Accounts(const std::string &environment);
};
#endif //Archive_H