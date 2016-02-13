#include "all.h"

void Buyer::Changeinfo()
{
    string line,name,identity_card,sex,address;
    ifstream file_user(File_user());
    ofstream file_temp("user\\temp.txt");
    if(!file_user.is_open())
    {
        cout<<"Change password failure!"<<endl;
        return;
    }

    cout<<"Please enter a new name:";cin>>name;
    cout<<"Please enter a new identity_card:";cin>>identity_card;
    cout<<"Please enter a new sex:";cin>>sex;
    cout<<"Please enter a new address:";cin>>address;
    while(getline(file_user,line))
    {
        if(line.find("[name] ") != -1)
            file_temp<<"[name] "<<name<<endl;
        else if(line.find("[identity_card] ") != -1)
            file_temp<<"[identity_card] "<<identity_card<<endl;
        else if(line.find("[sex] ") != -1)
            file_temp<<"[sex] "<<sex<<endl;
        else if(line.find("[address] ") != -1)
            file_temp<<"[address] "<<address<<endl;
        else file_temp<<line<<endl;
    }
    file_user.close();file_temp.close();
    remove(File_user());rename("user\\temp.txt",File_user());

    cout<<"Change user information success!"<<endl;
}
