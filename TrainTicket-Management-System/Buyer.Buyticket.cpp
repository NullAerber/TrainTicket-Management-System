#include "all.h"

void Buyer::Buyticket()
{
    Time time;
    int tag,selln;
    string line,type,dep_station,arr_station,temp,schedule;
    if(!time.Time_check())
    {
        cout<<"Today's train schedules are not updated!"<<endl;
        return;
    }

    chdir(time.Show_file_curdir());
    ifstream file_index("index.txt");

    cout<<"which station start:";cin>>dep_station;
    cout<<"which station arrive:";cin>>arr_station;
    cout<<endl;

    while(getline(file_index,line))
    {
        if(line.find(dep_station) != -1)
        {
            getline(file_index,line);
            if(line.find(arr_station) != -1)
            {
                getline(file_index,line);
                schedule = line;
                line = line + ".txt";
                //const char *File_train = line.c_str();
                ifstream file_train(line);
                while(getline(file_train,line))
                    cout<<line<<endl;
                file_train.close();

                cout<<endl;
                cout<<"Noseat   => 1"<<endl;
                cout<<"Hardseat => 2"<<endl;
                cout<<"Hardbed  => 3"<<endl;
                cout<<"Softbed  => 4"<<endl;
                cout<<endl;
                cout<<"Buy what kind of ticket:"<<endl;
                cout<<"Please enter the number behind the type:";cin>>tag;

                chdir("..\\..");
                ifstream file_check(File_user());
                while(getline(file_check,line))
                {
                    if(line.find("[dep_station] " + dep_station) != -1)
                    {
                        getline(file_check,line);
                        if(line.find("[arr_station] " + arr_station) != -1)
                        {
                            cout<<"repeat!"<<endl;
                            return;
                        }
                    }
                }

                switch(tag)
                {
                    case 1 : type = "noseat"; break;
                    case 2 : type = "hardseat"; break;
                    case 3 : type = "hardbed"; break;
                    case 4 : type = "softbed"; break;
                    default: cout<<"No such select !"<<endl; return;
                }
                ofstream file_user(File_user(), ios::out | ios::app);
                file_user<<endl;
                file_user<<"[schedule] "<<schedule<<endl;
                file_user<<"[date] "<<time.Show_cur()<<endl;
                file_user<<"[dep_station] "<<dep_station<<endl;
                file_user<<"[arr_station] "<<arr_station<<endl;
                file_user<<"[ticket_tag] "<<type<<endl;

                file_user.close();

                chdir(time.Show_file_curdir());
                ifstream infile(schedule + ".txt");
                ofstream outfile("temp.txt");
                while(getline(infile,line))
                {
                    if(line.find(type + "_selln") != -1)
                    {
                        stringstream str(line);
                        while(str >> temp)
                            selln = atoi(temp.c_str());
                        ++selln;
                        outfile<<"["<<type<<"_selln] "<<selln<<endl;
                    }
                    else outfile<<line<<endl;
                }
                infile.close();outfile.close();
                temp = schedule + ".txt";
                const char *p = temp.c_str();
                remove(p);rename("temp.txt",p);
            }
        }
    }
    cout<<"Query end!"<<endl;
    chdir("..\\..");
}
