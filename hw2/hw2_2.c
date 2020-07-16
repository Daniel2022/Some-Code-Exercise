#include <stdio.h>
void extOdDigits(long n, long *nd);
int main(void)
{
    long n, *nd;
    nd = &n;
    printf("Please enter a postive int: ");
    scanf("%ld", &n);
    extOdDigits(n, nd);
    printf("Output: %ld\n",n);
    return 0;
}
void extOdDigits(long n, long *nd)
{
    long i = 1;long digits = 0;long j = 1;
    while(n / i != 0)
    {
        int d = (n%(i*10) - n%i) / i;  //get digit from right
        if(d%2==1)   //decide if the digit is odd
        {
            digits = digits + d * j;
            j *= 10;
            //put digits together
        }
        i *= 10;
    }
    if(digits==0)
        digits = -1;
    //if no odd digits output -1
    *nd = digits;
}