#include "Date.hpp"
#include <stdio.h>

void Date::Outputdate()
{
    printf("%d-%d-%d\n", m_year, m_month, m_day);
}
/*
Date::Date (int y, int m, int d)
{
    m_year = y;
    m_month = m;
    m_day = d;
}*/