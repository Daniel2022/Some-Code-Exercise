#include  <stdio.h>
class Date {
private:
    int m_day;
    int m_month;
    int m_year;
public:
    void Outputdate();
    Date(int y, int m, int d);
};

void Date::Outputdate()
{
    printf("%d-%d-%d", m_year, m_month, m_day);
}

Date::Date (int y, int m, int d)
{
    m_year = y;
    m_month = m;
    m_day = d;
}
int main()
{
    Date today(2018,10,31);
    today.Outputdate();
    
}
