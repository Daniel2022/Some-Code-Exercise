#include <stdio.h>
void add2(int n);
int main()
{
    int num = 5;
    add2(num);
    printf("num is %d\n",num);
    return 0;
}
void add2(int n)
{
    ++n;
}