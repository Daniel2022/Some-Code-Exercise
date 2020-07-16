#include "Shape.hpp"
#include <stdio.h>

Shape::Shape(float s1)
{
    size1 = s1;
}
Shape::Shape(float s1, float s2)
{
    size1 = s1;
    size2 = s2;
}

void Rectangle::out()
{
    printf("%f %f\n",size1, size2);
}