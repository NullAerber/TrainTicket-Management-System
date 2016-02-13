#include "all.h"

void Seller::Lookall()
{
    Time time;
    string line;
    if(!time.Time_check())
    {
        cout<<"Today's train schedules are not updated!"<<endl;
        return;
    }

    chdir(time.Show_file_curdir());
    ifstream infile("index.txt");
    while(getline(infile,line))
    {
        if(line.find("[arr_station]") != -1)
        {
            getline(infile,line);
            line = line + ".txt";
            ifstream file_train(line);
            while(getline(file_train,line))
                cout<<line<<endl;
            file_train.close();
            cout<<endl;
        }
    }
    cout<<"Query end"<<endl;
    infile.close();
    chdir("..\\..");
}

