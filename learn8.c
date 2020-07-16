#include <stdio.h>
int sum;
int getTotal(int score[])   //求总分
{
    int i; sum = 0;
    for(i=0;i<10;i++)
    {
        sum += score[0];
    }
    printf("总分为%d\n",sum);
    return sum;
}
void getMax(int score[])    //求最高分
{
    int max = score[0]; int i;
    for(i=1;i<10;i++)
    {
        if(score[i]>max)
            max = score[i];
    }
    printf("最高分为%d\n",max);
}
void getMin(int score[])   //求最低分
{
    int min = score[0]; int i;
    for(i=1;i<10;i++)
    {
        if(score[i]<min)
            min = score[i];    
    }
    printf("最低分为%d\n", min);
}
void getAverage()    //求平均分
{
    printf("平均分为%d\n", sum/10);
}
void sorted(int score[])    //倒序排列
{
    int i, j;
    for(i=8;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(score[j]<score[j+1])
            {
                int temp;
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
    printf("倒序排列为 ");
    for(i=0;i<10;i++)
    {
        if(i!=9)
            printf("%d, ", score[i]);
        else
            printf("%d\n",score[i]);
    }
}
int main()
{
    int score[10]={67,98,75,63,82,79,81,91,66,84};
    sum=getTotal(score);
    getMax(score);
    getMin(score);
    getAverage();
    sorted(score);
    return 0;
}