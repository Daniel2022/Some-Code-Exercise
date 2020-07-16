#include <stdio.h>
#include "def.h"
int main()
{
    int n,i,j,k;
    scanf("%d %d %d",&i,&j,&k);
    n = max3(i, j, k);
    printf("Max is %d\n",n);
    return 0;
}