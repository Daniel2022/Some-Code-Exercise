#include <stdio.h>
int digitValue(int n, int k);
int main(void)
{
    int n, k;
    scanf("%d",&n);
    scanf("\n%d",&k);
    printf("%d\n",digitValue(n, k));
    return 0;
}
int digitValue(int n, int k)
{
    int i; int j = 1;
    for(i=1;i<k;i++)
    {
        j *= 10;
    }
    if(n<j)
        return 0;
    else
        return (n%(j*10)-n%j)/j;
}