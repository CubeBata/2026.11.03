#include <Manager_Of_Passwords.h>

std::string input(const std::string& message = "") {
    std::string result;
    std::cout << message;
    std::getline(std::cin, result);
    return result;
}


void Manager_Of_Passwords::Manage()
{
    while (true) {
        std::string ans = input("\n\n\nYou want to exit?\n\t[#] Yes\n\t[Something] No\n[Write]: ");
        if (ans == "#") return;
        int ans_int;
        try {
            if (!this->HasAccount) {
                std::string start_ans = input(
                    "   CHOOSE OPTION: "
                    "\n\t[1] SIGN UP"
                    "\n\t[SOMETHING] SKIP"
                    "\n[WRITE]: "
                );
                if (start_ans == "1") Manage_the_account();
                continue;
            }
            if (!this->signed_in) {
                std::string start_ans = input(
                    "   CHOOSE OPTION: "
                    "\n\t[1] SIGN IN"
                    "\n\t[SOMETHING] SKIP"
                    "\n[WRITE]: "
                );
                if (start_ans == "1") Manage_the_account();
                continue;
            }
            ans_int = std::stoi(input(
                "   CHOOSE OPTION: "
                "\n\t[1] CREATE"
                "\n\t[2] EDIT"
                "\n\t[3] DELETE"
                "\n\t[4] CLEAR_ALL"
                "\n\t[5] EDIT_ACCOUNT"
                "\n\t[6] SIGN_OUT"
                "\n\t[7] DELETE_ACCOUNT"
                "\n\t[8] SHOW"
                "\n\t[SOMETHING] SKIP"
                "\n[WRITE]: "
            ));
        } catch (...) {
            ans_int = 0;
        }
        ans_int--;


        
        if (std::chrono::steady_clock::now() - this->Updated > std::chrono::minutes(10)) {
            std::cout << "The manager of password already forgotten you !!!" << std::endl;
            this->signed_in = false;
            continue;
        }

        std::cout << "++++++++++++++++++++++++++++" << std::endl;

        switch (ans_int)
        {
            case Command::CREATE:
                while(true)
                {
                    std::string ans = input("Are you ready to create? \n\t[Something] Yes \n\t[0] No\n[Write]: ");
                    if (ans == "0") break;
                    std::string environment = input("[Write name of environment]: ");
                    if (environment == "") {
                        std::cout << " You forgot write environment!!!";
                        continue;
                    }
                    std::string login = input("[Write login]: ");
                    if (login == "") {
                        std::cout << " You forgot write login!!!";
                        continue;
                    }
                    if (this->archive.find(environment) != this->archive.end()) {
                        bool font_login = false;
                        for (const Account& ac : this->archive[environment]) {
                            if (ac.login == login) {
                                std::cout <<  " You have the login \" " << login 
                                << " \" in the environment \"" << environment << " \"!!!" << std::endl;
                                font_login = true;
                                break;
                            }
                        }
                        if (font_login) continue;
                    }

                    std::string password = input("[Write password]: ");
                    this->archive[environment].push_back({login, password});
                    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<[\"" << environment << "\" keeps accounts]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
                    int i = 0;
                    for (const Account& ac : this->archive[environment])
                    {
                        std::cout << "<<<<<<<<<<<[ "<< i << " ]>>>>>>>>>>" << "\tLogin: " 
                        << ac.login << "\tPassword: " << ac.password << std::endl;
                        i++;
                    }
                    break;
                }
                break;

            case Command::EDIT:
                while(true)
                {
                    std::string ans = input("Are you ready to edit? \n\t[Something] Yes \n\t[0] No\n[Write]: ");
                    if (ans == "0") break;
                    std::string environment = input("[Write name of environment]: ");
                    if (environment == "") {
                        std::cout << " You forgot write environment!!!";
                        continue;
                    }
                    if (this->archive.find(environment) == this->archive.end()) {
                        std::cout << " The environment \" " << environment << " \" is not exists!!!!" << std::endl;
                        continue;
                    }
                
                
                    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<[ CHOOSE ]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
                    std::cout << "<<<<<<<<<<<[ SOMETHING ]>>>>>>>>>>         CANCEL" << std::endl;
                    unsigned int i = 0;
                    for (const Account& ac : this->archive[environment])
                    {
                        std::cout << "<<<<<<<<<<<[ "<< i << " ]>>>>>>>>>>" << "\tLogin: " << ac.login << "\n\tPassword: " << ac.password << std::endl;
                        i++;
                    }
                    std::string chosen = input("[CHOOSE]: ");
                    unsigned int index;
                    try {
                        index = std::stoi(chosen);
                        if (index >= i) {
                            std::cout << " Too big index, the environment \" " << environment << " \" doesn't have it!!!" << std::endl;
                            continue;
                        }
                    }
                    catch(...) {
                        break;
                    }
                
                
                    Account account = this->archive[environment][index];
                    std::cout << "If you don't change something, touch Enter/Return" << std::endl;
                
                
                    std::string login = input("Changing login from \" " + account.login + " \" to: ");
                    std::string password = input("Changing password from \" " + account.password + " \" to: ");
                    bool font_login = false;
                    for (const Account& ac : this->archive[environment]) {
                        if (ac.login == login && login != account.login) {
                            std::cout <<  "The new login \" " << login << " \" is already exist in the environment \" " << environment << " \"!!!" << std::endl;
                            font_login = true;
                            break;
                        }
                    }
                    if (font_login) break;
                    if (login == "" && password == "") break;
                    if (login == "") login = account.login;
                    if (password == "") password = account.password;
                
                
                
                
                    this->archive[environment][index] = {login, password};
                    break;
                }
                break;

            case Command::DELETE:
                while (true) {
                    std::string ans = input("Are you ready to delete? \n\t[Something] Yes \n\t[0] No\n[Write]: ");
                    if (ans == "0") break;
                    std::string environment = input("[Write name of environment]: ");
                    if (environment == "") {
                        std::cout << " You forgot write environment!!!";
                        continue;
                    }
                    if (this->archive.find(environment) == this->archive.end()) {
                        std::cout << " The environment \" " << environment << " \" is not exists!!!!" << std::endl;
                        continue;
                    }
                    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<[ CHOOSE ]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
                    std::cout << "<<<<<<<<<<<[ SOMETHING ]>>>>>>>>>>         CANCEL" << std::endl;
                    std::cout << "<<<<<<<<<<<[ # ]>>>>>>>>>>     DELETE the environment \" " << environment << " \"" << std::endl;
                    unsigned int i = 0;
                    for (const Account& ac : this->archive[environment])
                    {
                        std::cout << "<<<<<<<<<<<[ "<< i << " ]>>>>>>>>>>" << "\tLogin: " << ac.login << "\n\tPassword: " << ac.password << std::endl;
                        i++;
                    }
                    std::string chosen = input("[CHOOSE]: ");
                    if (chosen == "#") {
                        this->archive.erase(environment);
                        std::cout << "\" " << environment << " \" is deleted" << std::endl;
                        break;
                    }
                    unsigned int index;
                    try {
                        index = std::stoi(chosen);
                        if (index >= i) {
                            std::cout << " Too big index, the environment doesn't have it!!!" << std::endl;
                            continue;
                        }
                    }
                    catch(...) {
                        break;
                    }
                    this->archive[environment].erase(this->archive[environment].begin() + index);
                    std::cout << " The account is deleted" << std::endl;
                    break;
                }
                break;

            case Command::CLEAR_ALL: {
                std::string agree = "Yes, I am sure and I very want to you delete all accounts and environments, please!!!";
                std::string ans = input("Are you sure that you want delete all accounts and environments?"
                    "\t\n[Something] No\t\n[\""+agree+"\"] Yes\n[WRITE]: ");
                if (ans == agree) {
                    std::map<std::string, std::vector<Account>> cleaned;
                    this->archive =  cleaned;
                    std::cout << " I clear archive of accounts and environments!!!" << std::endl;
                }
                break;
            }
            case Command::EDIT_ACCOUNT: {
                this->NeedEdit = true;
                this->Manage_the_account();
                break;
            }

            case Command::SIGN_OUT: { 
                this->signed_in = false;
                std::cout << "You signed out!" << std::endl;
                break;
            case Command::DELETE_ACCOUNT:
                std::string agree = "Yes, I am sure and I very want to you delete my account, please!!!";
                std::string ans = input("Are you sure that you want delete your account?"
                    "\t\n[Something] No\t\n[\""+agree+"\"] Yes\n[WRITE]: ");
                if (ans == agree) {
                    Manager_Of_Passwords new_account;
                    *this = new_account;
                    std::cout << " I delete your account!!!" << std::endl;
                }
                break;
            }

            case Command::SHOW: 
                while (true){
                    std::string ans = input("What show?\n\t[*] All\n\t[@] A environment\n\t[$] Only environments\n\t[Something] Cancel\n[WRITE]: ");
                    std::string environment;
                    if (ans != "@" && ans != "*" && ans != "$") {
                        std::cout << "CANCEL---" << std::endl;
                        break;
                    }
                    if (ans == "@") {
                        environment = input("Environment: ");
                        if (environment == "") {
                            std::cout << "You forgot write a environment!!!" << std::endl;
                            continue;
                        }
                        if (this->archive.find(environment) == this->archive.end()) {
                            std::cout << " The environment is not exists!!!!" << std::endl;
                            continue;
                        }
                    }
                    std::cout << "\n\n\n===============================" << std::endl;
                    unsigned int i = 1;
                    if (ans == "*") {
                        std::cout << "The archive has: " << std::endl;
                        for (const auto& [env , acs] : this->archive) {
                            std::cout << "["<< i << "]===[\" " << env << " \"]" << std::endl;
                            unsigned int j = 1;
                            for (const Account& ac : acs) {
                                std::cout << "\t["<< j << "]===[\" " << ac.login 
                                << " \"]===[\" " << ac.password << " \"]" << std::endl;
                                j++;
                            }
                            i++;
                        }
                    }
                    else if (ans == "@") {
                        std::cout << "The \" " << environment << " \" has: " << std::endl;
                        for (const Account& ac : this->archive[environment]) {
                            std::cout << "["<< i << "]===[\" " << ac.login 
                            << " \"]===[\" " << ac.password << " \"]" << std::endl;
                            i++;
                        }
                    }
                    else if (ans == "$") {
                        std::cout << "The archive has: " << std::endl;
                        for (const auto& [env , acs] : this->archive){
                            std::cout << "["<< i << "]===[\" " << env << " \"]" << std::endl;
                            i++;
                        }
                    }

                    std::cout << "===============================\n\n\n" << std::endl;
                    break;
                }
                break;
            default: 
                std::cout << " I don't have the option" << std::endl;
        }
    }
}

bool Manager_Of_Passwords::Manage_the_account()
{
    if (this->NeedEdit || !this->HasAccount) {
        while (true) {
            std::string ans = input("Are you ready to " + 
            std::string(this->HasAccount ? "edit the account" : "sign up")
            + " ? \n\t[Something] Yes \n\t[0] No\n[Write]: ");

            if (ans == "0") {this->NeedEdit = false; return false;}
            std::cout << "Please, not use the characters witch are little 32 and more 126,\n"
            "they are character managers" << std::endl;
            std::string login = input("Login: ");
            if (login == "") {
                if (!this->HasAccount){
                    std::cout << "Where is login?" << std::endl;
                    continue;
                }
                login = this->User.login;
            }
            std::string password = input("Password: ");
            if (password == "") {
                if (!this->HasAccount){
                    std::cout << "Where is password?" << std::endl;
                    continue;
                } 
            }
            if (password != "" && password != input("Reaped Password: ")) {
                std::cout << " Reaped password is invalid!!!" << std::endl;
                continue;
            }
            std::cout << "\n\nLogin: " << login << "\nPassword: " << password << std::endl;
            ans = input("Right?\n\t[Something] Yes\n\t[0] No\n[Write]: ");
            if (ans != "0") {
                this->User.login = login;
                this->User.password = password;
                this->Updated = std::chrono::steady_clock::now();
                this->NeedEdit = false;
                this->HasAccount = true;
                this->signed_in = true;
                return true;
            }
        }
    }
    else {
        while (true) {
            std::string ans = input("Are you ready to sign in? \n\t[Something] Yes \n\t[0] No\n[Write]: ");
            if (ans == "0") return false;
            std::cout << "Please, not use the characters witch are little 32 and more 126,\n"
            "they are character managers" << std::endl;
            std::string login = input("Login: ");
            if (login == "") {
                std::cout << "Where is login?" << std::endl;
                continue;
            }
            std::string password = input("Password: ");
            if (password == "") {
                std::cout << "Where is password?" << std::endl;
                continue;
            }
            if (login == this->User.login && password == this->User.password) {
                this->Updated = std::chrono::steady_clock::now();
                this->signed_in = true;
                return true;
            }
            std::cout << " Your login or password are invalid!!!" << std::endl;
        }

    }
    std::cout << "        [  WELCOME TO THE MANAGER OF PASSWORDS  ]         " << std::endl;
}


bool Manager_Of_Passwords::Fast_Managing(
    FastCommand fcm, 
    const std::string& environment, 
    const Account& old_acc,
    const Account& new_acc
)
{
    if ((!this->signed_in || !this->HasAccount) && fcm != FastCommand::TO_My_ACCOUNT) {
        std::cout <<  "Sign up or sign in, please!" << std::endl;
        return false;
    }
    else if (fcm == FastCommand::TO_My_ACCOUNT)
    {
        if ((new_acc.login == Account().login && old_acc.login == Account().login && environment == "")) {
            return this->Manage_the_account();
        }
        std::cout <<  "Too much arguments!" << std::endl;
        return false;
    }
    else if (fcm == FastCommand::FAST_SIGN_OUT) {
        if ((new_acc.login == Account().login && old_acc.login == Account().login && environment == "")) {
            this->signed_in = false;
            return true;
        }
        std::cout <<  "Too much arguments!" << std::endl;
        return false;
    }

    switch (fcm) {
        case FastCommand::FAST_CREATE:{
            if (new_acc.login != Account().login) {
                std::cout <<  "Too much arguments!" << std::endl;
                return false;
            }
            if (old_acc.login == Account().login || environment == "") {
                std::cout <<  "Too few arguments!" << std::endl;
                return false;
            }
            if (this->archive.find(environment) != this->archive.end()) {
                bool font_login = false;
                for (const Account& ac : this->archive[environment]) {
                    if (ac.login == old_acc.login) {
                        std::cout <<  "You have the login \" " << old_acc.login << " \" in the environment \" " << environment << " \"!!!" << std::endl;
                        font_login = true;
                        break;
                    }
                }
                if (font_login) return false;
            }
            this->archive[environment].push_back(old_acc);
            break;}

        case FastCommand::FAST_EDIT:{
            if (old_acc.login == Account().login || environment == "" || new_acc.login == Account().login){
                std::cout <<  "Too few arguments!" << std::endl;
                return false;
            }
            if (this->archive.find(environment) == this->archive.end()) {
                std::cout <<  "The environment \" " 
                << environment << " \" is not exist!" << std::endl;
                return false;
            }

            if (old_acc.login == "" || new_acc.login == "") {
                std::cout <<  "Accounts have to have login!" << std::endl;
                return false;
            }

            bool font_login = false;
            for (const Account& ac : this->archive[environment]) {
                if (ac.login == old_acc.login) {
                    font_login = true;;
                }
            }
            if (!font_login) {
                std::cout << "The login \" " << old_acc.login << " \" for change is not exist in the environment \" " << environment << " \"!!!" << std::endl;
                return false;
            }

            font_login = false;
            for (const Account& ac : this->archive[environment]) {
                if (ac.login == new_acc.login && new_acc.login != old_acc.login) {
                    std::cout <<  "The your new login \" " << new_acc.login << " \" is already exist in the environment \" " << environment << " \"!!!" << std::endl;
                    font_login = true;
                    break;
                }
            }
            if (font_login) return false;

            for (Account& ac : this->archive[environment]) {
                if (ac.login == old_acc.login) {
                    ac.login = new_acc.login;
                    ac.password = new_acc.password;
                    break;
                }
            }
            break;}

        case FastCommand::FAST_DELETE:{
            if (new_acc.login != Account().login) {
                std::cout << "Too much arguments!" << std::endl;
                return false;
            }
            if (old_acc.login == Account().login || environment == "") {
                std::cout << "Too few arguments!" << std::endl;
                return false;
            }
            if (this->archive.find(environment) == this->archive.end()) {
                std::cout <<  "The environment \" " 
                << environment << " \" is not exist!" << std::endl;
                return false;
            }



            int index = 0;
            int i = 0;
            for (const Account& acc : this->archive[environment]) {
                if (acc.login == old_acc.login) {
                    index = i;
                }
                i++;
            }


            this->archive[environment].erase(this->archive[environment].begin() + index);
            break;
        }

        case FastCommand::FAST_DELETE_ENV:
            if (new_acc.login != Account().login || old_acc.login != Account().login) {
                std::cout <<  "Too much arguments!" << std::endl;
                return false;
            }
            if (environment == "") {
                std::cout <<  "Too few arguments!" << std::endl;
                return false;
            }
            if (this->archive.find(environment) == this->archive.end()) {
                std::cout <<  "The environment \" " 
                << environment << " \" is not exist!" << std::endl;
                return false;
            }
            this->archive.erase(environment);
            break;

        case FastCommand::FAST_CLEAR_ALL:{
            if (new_acc.login != Account().login || old_acc.login != Account().login || environment != "") {
                std::cout <<  "Too much arguments!" << std::endl;
                return false;
            }
            std::map<std::string, std::vector<Account>> archive;
            this->archive = archive;
            break;
        }

        default:
            if (fcm != FastCommand::TO_My_ACCOUNT) {
                std::cout <<  "The manager doesn't have the option!"  << std::endl;
                return false;
            }
    }
    return true;
}