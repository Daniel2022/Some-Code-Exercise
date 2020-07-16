/*
#include <stdio.h>
long function(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld\n", function(n));
    return 0;

}
long function(int n)
{
    if(n == 0){
        return 1;
    }
    else{
        return n*function(n-1);
    }
}
*/

/*
#include <stdio.h>
void fn(int x, int y, int *z);
int main(void)
{
    int n1=20, n2=15, n3=0;
    fn(n1, n2, &n3);
    printf("n1 = %d, n2 = %d, n3 = %d\n", n1, n2, n3);
    return 0;
}
void fn(int x, int y, int *z)
{
    if (x > y) {
        x = x - 2;
        y = y - 1;
        *z = x * y;
        //printf("x = %d, y = %d, *z = %d\n", x, y, *z);
        fn(x, y, z);
    }
    printf("x = %d, y = %d, *z = %d\n", x, y, *z);
}
*/

/*
#include <stdio.h>
void move(int count, int start, int finish, int temp, long *i);
int main() {
    int disks = 10;
    long re = 0;
    long *i;
    i = &re;
    printf("Disks: %d\n", disks);
    move(disks, 1, 3, 2, i);
    printf("%ld\n", re);
    return 0;
}
void move(int count, int start, int finish, int temp, long *i) {
    if (count == 1) {
        printf("%s %d %s %d %s %d\n", "move disk", count, "from tower", start, "to tower", finish);(*i)++;
        return;
    }
    move(count - 1, start, temp, finish, i);
    printf("%s %d %s %d %s %d\n", "move disk", count,"from tower", start, "to tower", finish);(*i)++;
    move(count - 1, temp, finish, start, i);
}
*/

/*
#include <stdio.h>
int foo(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", foo(n));
    return 0;
}
int foo(int n)
{
    if(n == 1)
        return 1;
    return foo(n-1) + n;
}
*/

#include <stdio.h>
void add1(int ar[], int size);
void display(int ar[3][4]);
int main()
{
    int h, k;
    int ar[3][4] = {
        {5, 10, 15, 20},
        {10, 20, 30, 40},
        {20, 40, 60, 80}
    };
    display(ar);
    for (h = 0; h < 3; h++)
    {
        add1(ar[0], 12);
    }
    printf("After line a: \n");
    display(ar);
    return 0;
}
void add1(int ar[], int size)
{
    int k;
    for (k = 0; k < size; k++)
        ar[k]++;
}
void display(int ar[3][4])
{
    int l, m;
    for (l = 0; l < 3; l++) {
        for (m = 0; m < 4; m++)
            printf("%5d", ar[l][m]);
        printf("\n");
    }
}