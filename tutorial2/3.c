#include <stdio.h>
long groupDigits1(long n);
void groupDigits2(long n, long *nd);
int main()
{
    long n, *nd;
    scanf("%ld", &n);
    nd = &n;
    //groupDigits1(n);
    groupDigits2(n, nd);
    printf("%ld\n", n);
}
long groupDigits1(long n)
{
    long i = 1;long digits = 0;long j = 1;
    while(n / i != 0)
    {
        int d = (n%(i*10) - n%i)/i;
        //printf("%d\n",d);
        if(d<5)
        {
            digits = digits + d * j;
            j *= 10;
        }
        i *= 10;
    }
    if(digits==0)
        digits = -1;
    return digits;
}
void groupDigits2(long n, long *nd)
{
    *nd = groupDigits1(n);
}