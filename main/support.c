#include <stdio.h>
#include "def.h"
int max2(int x, int y)
{
    return x > y ? x:y;
}
int max3(int x, int y, int z)
{
    return max2(max2(x,y),max2(y,z));
}