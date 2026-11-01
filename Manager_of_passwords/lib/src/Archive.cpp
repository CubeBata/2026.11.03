#include <Archive.h>


std::vector<Account> Archive::Get_Accounts(const std::string& environment)
{
    if (!this->signed_in) return {};
    if (this->archive.find(environment) != this->archive.end())
        return this->archive[environment];
    return {};
}
