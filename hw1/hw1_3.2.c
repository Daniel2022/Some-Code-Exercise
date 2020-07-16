#include <stdio.h>
int main()
{
    int n, i;double result = 1;float frac, x;
    printf("Please enter the value of n:");
    scanf("%d", &n);
    printf("Please enter the value of x:");
    scanf("%f", &x);
    frac = 1;
    for(i=1;i<=n;i++)
    {
        frac=frac*x/i;
        result += frac;
    }
    printf("Result = %f\n", result);
    return 0;
}