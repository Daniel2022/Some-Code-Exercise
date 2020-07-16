#ifndef SHAPE_HPP
#define SHAPE_HPP

#include  <stdlib.h>
#include <stdio.h>
class Shape{
public:
  float size1;
  float size2;
  Shape(float s1);
  Shape(float s1, float s2);
};

class Rectangle : public Shape{
public:
  void out();
  Rectangle() =default;
  Rectangle(float s1, float s2):Shape(s1, s2){}
  
};
#endif