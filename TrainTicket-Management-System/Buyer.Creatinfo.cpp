#include "all.h"

bool Buyer::Creatinfo()
{
    string username,userkey;
    cout<<"Please enter a user account:";cin>>username;
    cout<<"Please enter a user password:";cin>>userkey;
    Set_user(username,userkey);

    ofstream file_create(File_user());
    if(!file_create.is_open())
        return 0;

    file_create<<"[username] "<<username<<endl;
    file_create<<"[userkey] "<<userkey<<endl;
    file_create.close();
    return 1;
}
