#include "all.h"

bool Buyer::Check_tic_rep(string dep_station, string arr_station)
{
    string line;
    dep_station = "[dep_station] " + dep_station;
    arr_station = "[arr_station] " + arr_station;

    ifstream file_user(File_user());
    while(getline(file_user,line))
    {
        if(line.find(dep_station))
        {
            getline(file_user,line);
            if(line.find(arr_station))
                return 1;
        }
    }
    file_user.close();
    return 0;
}
