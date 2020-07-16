#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void colfre(int n, int frecount[10]);
void displayhistogram(int frecount[10]);
int main(void)
{
    int n, i;int frecount[10] = {};
    printf("Please enter the amount of numbers: ");
    scanf("%d",&n);
    colfre(n, frecount);
    displayhistogram(frecount);
    return 0;
}
void colfre(int n, int frecount[10])
{
    int i, digit, index;
    srand((unsigned int)time(NULL));
    for(i=0;i<n;i++)
    {
        digit = rand()%100;
        index = digit / 10;
        frecount[index] += 1;
    }
}
void displayhistogram(int frecount[10])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        printf("%d - %d\t|", i*10,i*10+9);
        for(j=0;j<frecount[i];j++)
            printf("*");
        printf("%d\n", frecount[i]);
    }
}