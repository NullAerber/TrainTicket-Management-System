#include "all.h"

bool Buyer::Improveinfo()
{
    string line,name,identity_card,sex,address;
    cout<<"Please enter a new name:";cin>>name;
    cout<<"Please enter a new identity_card:";cin>>identity_card;
    cout<<"Please enter a new sex:";cin>>sex;
    cout<<"Please enter a new address:";cin>>address;

    ofstream file_improve(File_user(),ios::out | ios::app);
    if(!file_improve.is_open())
        return 0;

    file_improve<<"[name] "<<name<<endl;
    file_improve<<"[identity_card] "<<identity_card<<endl;
    file_improve<<"[sex] "<<sex<<endl;
    file_improve<<"[address] "<<address<<endl;

    file_improve.close();
    return 1;
}
