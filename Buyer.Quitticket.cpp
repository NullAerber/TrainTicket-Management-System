#include "all.h"

void Buyer::Quitticket()
{
    Time time;
    int selln;
    string line,type,quit_schedule,temp;
    if(!time.Time_check())
    {
        cout<<"Today's train schedules are not updated!"<<endl;
        return;
    }

    ifstream file_user(File_user());
    while(getline(file_user,line))
    {
        if(line.find(time.Show_cur()) != -1)
        {
            cout<<temp<<endl;
            cout<<line<<endl;
            for(int i = 1; i < 5; ++i)
            {
                if(getline(file_user,line))
                    cout<<line<<endl;
            }
        }
        else
            temp = line;
    }
    cout<<endl;
    file_user.close();
    cout<<"Query end!"<<endl<<endl;
    cout<<"If there is no need to quit the schedule, please enter 'zero'"<<endl;
    cout<<"Which station quit? Please enter its schedule:";cin>>quit_schedule;

    if(quit_schedule == "zero") return ;

    ifstream quit(File_user());
    ofstream quit_temp("user\\temp.txt");
    while(getline(quit,line))
    {
        if(line.find(quit_schedule) != -1)
        {
            for(int i = 1; i < 6; ++i)
            {
                getline(quit,line);
                if(line.find("[ticket_tag]") != -1)
                    type = line.erase(0,13);
            }
        }
        else
            quit_temp<<line<<endl;
    }
    quit.close();quit_temp.close();
    remove(File_user());rename("user\\temp.txt",File_user());

    chdir(time.Show_file_curdir());
    quit_schedule = quit_schedule + ".txt";
    const char *quit_sche_char = quit_schedule.c_str();
    ifstream file_train(quit_sche_char);
    ofstream file_temp("temp.txt");
    while(getline(file_train,line))
    {
        if(line.find(type + "_selln") != -1)
        {
            stringstream str(line);
            while(str >> temp)
                selln = atoi(temp.c_str());
            --selln;
            file_temp<<"["<<type<<"_selln] "<<selln<<endl;
        }
        else file_temp<<line<<endl;
    }
    file_train.close();file_temp.close();
    remove(quit_sche_char);rename("temp.txt",quit_sche_char);
    chdir("..\\..");

    cout<<"End of a quit!"<<endl;
}
