#include <stdio.h>

void function0(void);
void function1(int h, int k);
void function2(int *h, int *k);
int main()
{
    int h, k;
    h = 5;
    k = 15;
    printf("main 1: \th = %d, k = %d\n", h, k);
    function0();
    printf("main 2: \th = %d, k = %d\n", h, k);
    function1(h, k);
    printf("main 3: \th = %d, k = %d\n", h, k);
    function2(&h, &k);
    printf("main 4: \th = %d, k = %d\n", h, k);
}
void function0()
{
    int h, k;
    h = k = -100;
    printf("function 0.1: \th = %d, k = %d\n", h, k);
}
void function1(int h, int k)
{
    printf("function 1.1: \th = %d, k = %d\n", h, k);
    h = k = 100;
    printf("function 1.2: \th = %d, k = %d\n", h, k);
}
void function2(int *h, int *k)
{
    printf("function 2.1: \th = %d, k = %d\n", *h, *k);
    *h = *k = 200;
    printf("function 2.2: \th = %d, k = %d\n", *h, *k);
}