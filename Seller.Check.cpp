#include "all.h"

bool Seller::Check()
{
    string username,userkey;
    cout<<"Please enter a user account:";cin>>username;
    cout<<"Please enter a user password:";cin>>userkey;

    if(username == "admin")
    {
        if(userkey == "admin")
            return 1;
        else
        {
            cout<<"Password error!"<<endl;
            fflush(stdin);
            cout << "Press enter to return to the main menu..." << endl;
            getchar();
            return 0;
        }
    }
    else
    {
        cout<<"This admin does not exist!"<<endl;
        fflush(stdin);
        cout << "Press enter to return to the main menu..." << endl;
        getchar();
        return 0;
    }
}
