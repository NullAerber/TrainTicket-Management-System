#ifndef ALL_H
#define ALL_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <direct.h>
#include <sstream>
#include <map>

using namespace std;

class Time
{
public:
    Time();
    string Show_pre();
    string Show_cur();
    string Show_time();
    string Show_week();
    const char* Show_file_curdir();
    bool Time_check();
private:
    string Pre;
    string Cur;
    string File_curdir;
    string H_m_s;
    string Week;
};

class Seller
{
public:
    Seller();
    bool Check();
    void Initial();//initialize the train information
    void Change();//change the train information
    void Search();//search the train information
    void Transfer(string , string);//Providing transfer program
    void Lookall();

private:
    string Username;
    string Userkey;
};


class Buyer
{
public:
    Buyer() = default;
    void Set_user(string, string);//set username to Username and userkey to Userkey
    bool Check();//check whether the uaername and userkey are both right at the same time
    void Search();//search the train information
    void Lookall();//look the all train 's information
    void Buyticket();//buy the ticket
    void Quitticket();//quit the ticket
    void Changekey();//change the user's key
    void Changeinfo();//change the user's information
    bool Creatinfo();//only create the username and userkey,and check whether username have repeated
    bool Improveinfo();//improve the user's information
    const char* File_user();//Convert string into const char point
    void Transfer(string , string);//Providing transfer program

private:
    string Username;
    string Userkey;
};

#endif // ALL_H
