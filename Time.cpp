#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

#include "all.h"

using namespace std;

Time::Time()
{
    time_t t = time(0);
    time_t yestd = time(0) - 24 * 3600;
    char pre_d[5],y_m_d[5],h_m_s[10],week[10];

    strftime(pre_d,sizeof(pre_d),"%Y",localtime(&yestd));
    Pre = Pre + pre_d + "-";
    strftime(pre_d,sizeof(pre_d),"%m",localtime(&yestd));
    Pre = Pre + pre_d + "-";
    strftime(pre_d,sizeof(pre_d),"%d",localtime(&yestd));
    Pre = Pre + pre_d;

    strftime(y_m_d,sizeof(y_m_d),"%Y",localtime(&t));
    Cur = Cur + y_m_d + "-";
    strftime(y_m_d,sizeof(y_m_d),"%m",localtime(&t));
    Cur = Cur + y_m_d + "-";
    strftime(y_m_d,sizeof(y_m_d),"%d",localtime(&t));
    Cur = Cur + y_m_d;
    File_curdir = "train\\" + Cur;//File_curdir = train\\2016-02-06

    strftime(h_m_s,sizeof(h_m_s),"%X",localtime(&t));
    strftime(week,sizeof(week),"%A",localtime(&t));

    H_m_s = h_m_s;
    Week = week;
}

string Time::Show_pre()
{
    return Pre;
}

string Time::Show_cur()
{
    return Cur;
}

string Time::Show_time()
{
    return H_m_s;
}

string Time::Show_week()
{
    return Week;
}

const char* Time::Show_file_curdir()
{
    const char *p = File_curdir.c_str();
    return p;
}

bool Time::Time_check()
{
    string File = File_curdir + "\\index.txt";
    ifstream check_time(File);
    if(!check_time.is_open())
        return 0;//open fail : return 0
    return 1;//open success : return 1
}
