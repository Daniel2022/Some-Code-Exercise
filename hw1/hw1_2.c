#include <stdio.h>
#include <math.h>
int main()
{
    float a1, a2, b1, b2, c1, c2;double x, y, denominater;
    printf("Enter the values for a1, b1, c1, a2, b2, c2: ");
    scanf("%f %f %f %f %f %f", &a1, &b1, &c1, &a2, &b2, &c2);
    denominater = a1*b2-a2*b1;
    if((double)denominater<0.0001)
        printf("Error!The denominater is zero!\n");
    else
    {
        x = fabs((b2*c1-b1*c2)/denominater);y = fabs((a1*c2-a2*c1)/denominater);
        printf("x = %f and y = %f\n", x, y);
    }
    return 0;
}