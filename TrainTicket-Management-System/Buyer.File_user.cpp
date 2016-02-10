#include "all.h"

const char* Buyer::File_user()
{
    string user = "user\\" + Username + ".txt";
    const char *p = user.c_str();
    return p;
}
