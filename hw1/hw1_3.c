#include <stdio.h>
int main()
{
    int n, i, j;double result = 0;float n1,n2,x,frac;
    printf("Please enter the value of n:");
    scanf("%d", &n);
    printf("Please enter the value of x:");
    scanf("%f", &x);
    for(i=0;i<=n;i+=1)
    {
        if(i==0)
            frac = 1;
        else
        {
            n1 = 1;n2 = 1;
            for(j=1;j<=i;j+=1)
            {
                n1 *= x;
                n2 *= j;
            }
            frac = n1/n2;
        }
        result += frac;
    }
    printf("Result = %f\n", result);
    return 0;
}