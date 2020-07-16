#ifndef DATE_HPP
#define DATE_HPP

#include  <stdlib.h>
#include <stdio.h>
class Date{
  //private:
  public:
    int m_day;
    int m_month;
    int m_year;
    void Outputdate();
    Date(int y, int m, int d):m_day(d),m_month(m),m_year(y){}
};

class Holiday:public Date{
  public:
    char *m_name;
    Holiday(int y, int m, int d, char name[]):Date(y, m, d),m_name(name){};
    void get(){printf("%d-%d-%d %s",m_year, m_month, m_day, m_name);}
};

#endif