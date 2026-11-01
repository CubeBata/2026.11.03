#ifndef Manager_Of_Passwords_H
#define Manager_Of_Passwords_H
#include <Archive.h>

class Manager_Of_Passwords : public Archive
{
    public:
        enum FastCommand {
            TO_My_ACCOUNT,
            FAST_SIGN_OUT,
            FAST_CREATE,
            FAST_EDIT,
            FAST_DELETE,
            FAST_DELETE_ENV,
            FAST_CLEAR_ALL
        };

        void Manage();

        bool Manage_the_account();


        bool Fast_Managing(
            FastCommand fcm, 
            const std::string& environment = "", 
            const Account& old_acc = Account(),
            const Account& new_acc = Account()
        );


    private:

        enum Command {
            CREATE,
            EDIT,
            DELETE, 
            CLEAR_ALL,
            EDIT_ACCOUNT,
            SIGN_OUT,
            DELETE_ACCOUNT,
            SHOW
        };
        


};
#endif //Manager_Of_Passwords_H