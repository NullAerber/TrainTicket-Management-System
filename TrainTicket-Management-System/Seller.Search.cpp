#include "all.h"

void Seller::Search()
{
    Time time;
    string line,dep_station,arr_station;
    if(!time.Time_check())
    {
        cout<<"Today's train schedules are not updated!"<<endl;
        return;
    }

    chdir(time.Show_file_curdir());
    ifstream infile("index.txt");

    cout<<"which station start:";cin>>dep_station;
    cout<<"which station arrive:";cin>>arr_station;
    while(getline(infile,line))
    {
        if(line.find(dep_station) != -1)
        {
            getline(infile,line);
            if(line.find(arr_station) != -1)
            {
                getline(infile,line);
                ifstream file_train(line + ".txt");
                while(getline(file_train,line))
                    cout<<line<<endl;
                file_train.close();
            }
            else cout<<"no search information can find!"<<endl;
        }
    }
    cout<<"Query end!"<<endl;
    infile.close();
    chdir("..\\..");
}
