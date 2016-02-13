#include "all.h"

bool Buyer::Check()
{
    string line;
    string username,userkey;

    cout<<"Please enter a user account:";cin>>username;
    cout<<"Please enter a user password:";cin>>userkey;

    ifstream file_user("user\\" + username + ".txt");
    if(!file_user.is_open())
    {
        cout<<"Open the file failure..."<<endl;
        cout<<"This user does not exist!"<<endl;
        fflush(stdin);
        cout << "Press enter to return to the main menu..." << endl;
        getchar();
        return 0;
    }

    while(getline(file_user,line))
    {
        if((line.find("[userkey]") != -1) && (line.find(userkey) != -1))
        {
            cout<<"Login success!"<<endl;
            Set_user(username,userkey);
            file_user.close();
            return 1;
        }
        else if((line.find("[userkey]") != -1) && (line.find(userkey) == -1))
        {
            cout<<"Password error!"<<endl;
            file_user.close();
            fflush(stdin);
            cout << "Press enter to return to the main menu..." << endl;
            getchar();
            return 0;
        }
    }
}

