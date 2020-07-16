#include <stdlib.h>
#include <iostream>

class Date{
public:
    int m_month = 0;
    int m_day;
    Date() = default;
    Date(int m, int d);
};

Date::Date(int m, int d)
{
    m_month = m;
    m_day = d;
}

int main()
{
    Date day;
    std::cout << day.m_month << std::endl;
    Date day2(10,20);
    std::cout << day2.m_month << std::endl;
    return 0;
}