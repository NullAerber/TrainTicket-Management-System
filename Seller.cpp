#include "all.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Seller
{
public:
    Seller()
    {
         Username = "admin";
         Userkey = "admin";
    }

    bool Check()
    {
        string username,userkey;
        cout<<"管理员账户:";cin>>username;cout<<endl;
        cout<<"管理员密码:";cin>>userkey;cout<<endl;
        if(username == Username && userkey == Userkey) return 1;
        else return 0;
    }


    void Initial()//initialize the train information
    {
        Time time
        string cur,pre,s;
        cur = time.y_m_d + ".txt";
        pre = time.pre_d + ".txt";

        ifstream infile(pre);
        ofstream outfile(cur);

        if(!infile.is_open() || !outfile.is_open())
        {
            cout<<"Open the file failure..."<<endl;
            exit(1);
        }

        while(getline(infile,line))
        {
            if(line.find("[day]"))
            {
                outfile<<"[day] "<<time.y_m_d<<endl;
                outfile<<"[time] "<<time.h_m_s<<endl;
                outfile<<"[week] "<<time.week<<endl;
            }
            if(line.find("[noseat_selln]"))
                outfile<<"[noseat_selln] 100"<<endl;
            if(line.find("[hardseat_selln]"))
                outfile<<"[hardseat_selln] 180"<<endl;
            if(line.find("[hardbed_selln]"))
                outfile<<"[hardbed_selln] 200"<<endl;
            if(line.find("[softbed_selln]"))
                outfile<<"[softbed_selln] 60"<<endl;
            else  outfile<<line<<endl;
        }

        infile.close();outfile.close();
    }

    void Change();//change the train information,but the information of station can not change
    {
        string cur,dep_station,arr_station,line,change;
        Time time;
        cur = time.y_m_d + ".txt";
        ifstream infile(cur);
        ofstream outfile("temp.txt");

        cout<<"which station start:";
        cin>>dep_station;
        while(getline(ifstream,line))
        {
            if(line.find(dep_station))
            {
                outfile<<line<<endl;
                cout<<"which station arrive:";
                cin>>arr_station;
                pos = getline(ifstream,line)
                if(line.find(arr_station))
                {
                    outfile<<line<<endl;
                    cout>>"the change of departure time is:";cin<<change;
                    outfile<<"[dep_time] "<<change<<endl;
                    cout>>"the change of arrive time is:";cin<<change;
                    outfile<<"[arr_time] "<<change<<endl;
                    cout>>"the change of interval is:";cin<<change;
                    outfile<<"[interval] "<<change<<endl;

                    cout>>"the change of no seat's all number is:";cin<<change;
                    outfile<<"[noseat_an] "<<change<<endl;
                    cout>>"the change of no seat's have sold number is:";cin<<change;
                    outfile<<"[noseat_selln] "<<change<<endl;
                    cout>>"the change of no seat's price is:";cin<<change;
                    outfile<<"[noseat_pri] "<<change<<endl;

                    cout>>"the change of hardseat's all number is:";cin<<change;
                    outfile<<"[hardseat_an] "<<change<<endl;
                    cout>>"the change of hardseat's have sold number is:";cin<<change;
                    outfile<<"[hardseat_selln] "<<change<<endl;
                    cout>>"the change of hardseat's price is:";cin<<change;
                    outfile<<"[hardseat_pri] "<<change<<endl;

                    cout>>"the change of hardbed's all number is:";cin<<change;
                    outfile<<"[hardbed_an] "<<change<<endl;
                    cout>>"the change of hardbed's have sold number is:";cin<<change;
                    outfile<<"[hardbed_selln] "<<change<<endl;
                    cout>>"the change of hardbed's price is:";cin<<change;
                    outfile<<"[hardbed_pri] "<<change<<endl;

                    cout>>"the change of softbed's all number is:";cin<<change;
                    outfile<<"[softbed_an] "<<change<<endl;
                    cout>>"the change of softbed's have sold number is:";cin<<change;
                    outfile<<"[softbed_selln] "<<change<<endl;
                    cout>>"the change of softbed's price is:";cin<<change;
                    outfile<<"[softbed_pri] "<<change<<endl;

                    for(int n = 1;n < 20;++n)
                        pos = getline(ifstream,line);
                }
                else outfile<<line<<endl;

            }
            else outfile<<line<<endl;
        }

        infile.close();outfile.close();
        remove(cur);rename("temp.txt",cur);
    }

    void Search()//search the train information
    {
        Train train;
        Time time;
        string cur,line;
        cur = time.y_m_d + ".txt";
        ifstream infile(cur);

        cout<<"which station start:";cin>>train.dep_station;
        cout>>"which station arrive:";cin>>train.arr_station;
        //Train::operator>>(istream &in,Train &train);
        //Train::operator<<(ostream &out,Train &train);
        while(getline(ifstream,line))
        {
            if(line.find(train.dep_station))
            {
                cout<<line<<endl;
                pos = getline(ifstream,line);
                if(line.find(train.arr_station))
                {
                    cout<<line<<endl;
                    while(getline(ifstream,line))
                    {
                        if(line.find("[dep_station]")) break;
                        cout<<line<<endl;
                    }
                }
                else
                {
                    system("cls");
                    cout<<"no search information can find!"<<endl;
                }
            }
        }
        infile.close();
    }

    void Lookall()
    {
        Time time = time.get_time();
        string cur,line;
        cur = time.y_m_d + ".txt";
        ifstream infile(cur);
        while(getline(ifstream,line))
            cout<<line<<endl;
        infile.close();
    }

private:
     string Username;
     string Userkey;
};

ostream& operator>>(istream& in,  Seller& seller){}
ostream& operator<<(ostream&,  Seller&){}
