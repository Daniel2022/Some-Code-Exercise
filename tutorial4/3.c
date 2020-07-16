#include <stdio.h>
int sumUp(int n);
int sumUp2(int n);
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n%d\n", sumUp(n), sumUp2(n));
    return 0;
}
int sumUp(int n)
{
    if(n == 1)
        return 1;
    else
        return n + sumUp(n-1);
}
int sumUp2(int n)
{
    int i; int SUM = 0;
    for(i=1;i<=n;i++)
    {
       SUM += i;
    }
    return SUM;
}