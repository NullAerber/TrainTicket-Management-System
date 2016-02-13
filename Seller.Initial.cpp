#include "all.h"

void Seller::Initial()
{
    Time time;
    string line;
    if(time.Time_check())
    {
        cout<<"Have already initialized the train! Please do not repeat the initial!"<<endl;
        return;
    }

    _mkdir(time.Show_file_curdir());
    ifstream file_pre_index("train\\" + time.Show_pre() + "\\index.txt");
    ofstream file_cur_index("train\\" + time.Show_cur() + "\\index.txt");
    while(getline(file_pre_index,line))
    {
        if(line.find("[day]") != -1)
            file_cur_index<<"[day] "<<time.Show_cur()<<endl;
        else if(line.find("[time]") != -1)
            file_cur_index<<"[time] "<<time.Show_time()<<endl;
        else if(line.find("[week") != -1)
            file_cur_index<<"[week] "<<time.Show_week()<<endl;
        else if(line.find("arr_station") != -1)
        {
            file_cur_index<<line<<endl;
            getline(file_pre_index,line);
            file_cur_index<<line<<endl;
            ifstream file_orig("train\\" + time.Show_pre() + "\\" + line + ".txt");
            ofstream file_copy("train\\" + time.Show_cur() + "\\" + line + ".txt");
            while(getline(file_orig,line))
            {
                if(line.find("noseat_selln") != -1)
                    file_copy<<"[noseat_selln] 0"<<endl;
                else if(line.find("hardseat_selln") != -1)
                    file_copy<<"[hardseat_selln] 0"<<endl;
                else if(line.find("hardbed_selln") != -1)
                    file_copy<<"[hardbed_selln] 0"<<endl;
                else if(line.find("softbed_selln") != -1)
                    file_copy<<"[softbed_selln] 0"<<endl;
                else file_copy<<line<<endl;
            }
            file_orig.close();file_copy.close();
        }
        else file_cur_index<<line<<endl;
    }
    file_pre_index.close();file_cur_index.close();
    cout<<"Have already initialized the train!"<<endl;
}
