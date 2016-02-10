#include "all.h"

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <direct.h>

using namespace std;

void Seller::Change()
{
    Time time;
    string schedule,line,temp;
    cout<<"Please enter the schedule which need change:";cin>>schedule;
    if(!time.Time_check())
    {
        cout<<"Today's train schedules are not updated!"<<endl;
        return;
    }

    ifstream file_train("train\\" + time.Show_cur() + "\\" + schedule + ".txt");
    ofstream file_temp("train\\" + time.Show_cur() + "\\temp.txt");

    while(getline(file_train,line))
    {
        if(line.find("interval") != -1)
            break;
        else
        {
            cout<<"                     "<<line<<endl;
            file_temp<<line<<endl;
        }
    }
    cout<<"Please enter the new [interval]:";cin>>temp;
    file_temp<<"[interval] "<<temp<<endl<<endl;
    cout<<endl;

    cout<<"Please enter the new [noseat_an]:";cin>>temp;
    file_temp<<"[noseat_an] "<<temp<<endl;
    cout<<"Please enter the new [noseat_selln]:";cin>>temp;
    file_temp<<"[noseat_selln] "<<temp<<endl;
    cout<<"Please enter the new [noseat_pri]:";cin>>temp;
    file_temp<<"[noseat_pri] "<<temp<<endl<<endl;
    cout<<endl;

    cout<<"Please enter the new [hardseat_an]:";cin>>temp;
    file_temp<<"[hardseat_an] "<<temp<<endl;
    cout<<"Please enter the new [hardseat_selln]:";cin>>temp;
    file_temp<<"[hardseat_selln] "<<temp<<endl;
    cout<<"Please enter the new [hardseat_pri]:";cin>>temp;
    file_temp<<"[hardseat_pri] "<<temp<<endl<<endl;
    cout<<endl;

    cout<<"Please enter the new [hardbed_an]:";cin>>temp;
    file_temp<<"[hardbed_an] "<<temp<<endl;
    cout<<"Please enter the new [hardbed_selln]:";cin>>temp;
    file_temp<<"[hardbed_selln] "<<temp<<endl;
    cout<<"Please enter the new [hardbed_pri]:";cin>>temp;
    file_temp<<"[hardbed_pri] "<<temp<<endl<<endl;
    cout<<endl;

    cout<<"Please enter the new [softbed_an]:";cin>>temp;
    file_temp<<"[softbed_an] "<<temp<<endl;
    cout<<"Please enter the new [softbed_selln]:";cin>>temp;
    file_temp<<"[softbed_selln] "<<temp<<endl;
    cout<<"Please enter the new [softbed_pri]:";cin>>temp;
    file_temp<<"[softbed_pri] "<<temp<<endl<<endl;

    file_train.close();file_temp.close();
    temp = "train\\" + time.Show_cur() + "\\" + schedule + ".txt";
    const char *p_train = temp.c_str();
    temp = "train\\" + time.Show_cur() + "\\temp.txt";
    const char *p_temp = temp.c_str();
    remove(p_train);rename(p_temp,p_train);
}
