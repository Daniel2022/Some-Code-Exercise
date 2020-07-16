#include <stdio.h>
float power1(float x, int n);
void power2(float x, int n, float *y);
int main()
{
    float x,*y, out; int n;
    scanf("%f %d", &x, &n);
    out = power1(x, n);
    power2(x, n, y);
    printf("%f %f\n", out, *y);
}
float power1(float x, int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return power1(x,n-1) * x;
    else
        return power1(x,n+1) / x;
}
void power2(float x, int n, float *y)
{
    if(n==0)
        *y = 1;
    else if(n>0){
        power2(x,n-1,y);
        *y *= x;
    }
    else{
        power2(x,n+1,y);
        *y /= x;
    }
}