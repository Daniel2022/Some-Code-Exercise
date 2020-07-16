#include <stdio.h>
#include <math.h>
struct circle{
    double radius;
    double x;
    double y;
};
int intersect(struct circle c1, struct circle c2);
int contain(struct circle c1, struct circle c2);
double getabs(double x);
int main()
{
    struct circle c1;
    struct circle c2;
    printf("Enter radius x y of c1:");
    scanf("%lf %lf %lf", &c1.radius, &c1.x, &c2.y);
    printf("Enter radius x y of c2:");
    scanf("\n%lf %lf %lf", &c2.radius, &c2.x, &c2.y);
    printf("%d\n%d\n", intersect(c1, c2), contain(c1, c2));
    return 0;
}
int intersect(struct circle c1, struct circle c2)
{
    double distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    if(distance>(getabs(c1.radius-c2.radius))&&distance<(c1.radius+c2.radius))
        return 1;
    else
        return 0;
}
int contain(struct circle c1, struct circle c2)
{
    double distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    if(c1.radius>=distance+c2.radius)
        return 1;
    else
        return 0;
}
double getabs(double x)
{
    if(x>=0)
        return x;
    else
        return -x;
}