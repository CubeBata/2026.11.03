#include <Manager_Of_Passwords.h>

int main() {
    Manager_Of_Passwords manager;
    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::TO_My_ACCOUNT
    );
    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "first", {"boba", "123"});

        manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "first", {"biba", "gfdsgfdsg"});

        manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "first", {"combo", "123"});

        manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "second", {"combo", "123"});

        manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "second", {"combo", "4dg"});

        manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "second", {"tptptp", "4dg"});

    manager.Manage();

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_EDIT, 
        "first", {"boba", "123"},
        {"boba", "4488t"}
    );

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_EDIT, 
        "first", {"biba", "123"},
        {"bomba", "T-34"}
    );

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_EDIT, 
        "first", {"biba", "123"},
        {"bomba", "T-34"}
    );

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_EDIT, 
        "firrst", {"biba", "123"},
        {"bomba", "T-34"}
    );

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_EDIT, 
        "first", {"biffffba", "123"},
        {"bomba", "T-34"}
    );

    manager.Manage();

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_DELETE, 
        "first", {"bomba", "T-34"}
    );

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "third", {"boba", "123"}
    );

    manager.Manage();

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_DELETE_ENV, 
        "first"
    );

    manager.Manage();

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CLEAR_ALL
    );


    manager.Manage();

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "third", {"boba", "123"}
    );

    manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_SIGN_OUT
    );

    manager.Manage();

    Manager_Of_Passwords second_manager;


    second_manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "HU", {"HI", "HO"}
    );

    second_manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::TO_My_ACCOUNT
    );

    second_manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "HU", {"HI", "HO"}
    );

     second_manager.Fast_Managing(
        Manager_Of_Passwords::FastCommand::FAST_CREATE, 
        "RER", {"HI", "HO"}
    );

    std::vector<Account> 
    accounts = second_manager.Get_Accounts("RER");
    for (const Account& ac : accounts) {
        std::cout << "Login: \" " << ac.login 
        << " \", Password: \" " << ac.password << " \"; ";
    }
    std::cout << std::endl;

    second_manager.Manage();

    return 0;
}