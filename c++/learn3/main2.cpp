#include <stdlib.h>
#include <iostream>

void out(int &y)
{
    y++;
}

int main()
{
    int y=0;
    out(y);
    std::cout<<y<<std::endl;
}