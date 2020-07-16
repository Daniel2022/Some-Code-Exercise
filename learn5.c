#include <stdio.h>
int main() 
{ 
    /* 定义需要计算的日期 */
    int year = 2008;
    int month = 8;
    int day = 8;
    int sum, flag;
    /*
     * 请使用switch语句，if...else语句完成本题
     * 如有想看小编思路的，可以点击左侧任务中的“不会了怎么办”
     * 小编还是希望大家独立完成哦~
     */
    switch(month)
    {
        case 1 : sum = 0;break;
        case 2 : sum = 31;break;
        case 3 : sum = 59;break;
        case 4 : sum = 90;break;
        case 5 : sum = 120;break;
        case 6 : sum = 151;break;
        case 7 : sum = 181;break;
        case 8 : sum = 212;break;
        case 9 : sum = 243;break;
        case 10 : sum = 273;break;
        case 11 : sum = 304;break;
        case 12 : sum = 334;break;
        default : printf("一年只有12个月");break;
    }
    sum += day;
    if(year%400==0||(year%4==0&&year%100!=0))
        flag=1;
    else
        flag=0;
    if(flag==1&&month>2)
        sum++;
    printf("%d年%d月%d日是该年的第%d天\n",year, month, day, sum);
    return 0;
}