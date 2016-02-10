#include "all.h"

void Buyer::Changekey()
{
    string line,userkey;
    ifstream file_user(File_user());
    ofstream file_temp("user\\temp.txt");
    if(!file_user.is_open())
    {
        cout<<"Change password failure!"<<endl;
        return;
    }

    cout<<"Please enter a new password:";cin>>userkey;
    while(getline(file_user,line))
    {
        if(line.find("[userkey] ") != -1)
            file_temp<<"[userkey] "<<userkey<<endl;
        else file_temp<<line<<endl;
    }
    file_user.close();file_temp.close();
    remove(File_user());rename("user\\temp.txt",File_user());

    cout<<"Change password success!"<<endl;
}
