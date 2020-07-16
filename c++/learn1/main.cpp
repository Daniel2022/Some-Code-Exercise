#include "Date.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //gets();
    Date today(2018,10,31);
    today.Outputdate();
    char str[10] = "Helloween";
    Holiday day(2018,10,31,str);
    day.get();
}