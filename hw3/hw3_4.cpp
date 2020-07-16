#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <list>

/***********************************************************************
 *         Declaration/Definition of the base-class Shape              *
 ***********************************************************************/

class Shape{
protected:
  float size1;
  float size2;
  float area;
  float perimeter;
  int corners;
public:
  void OutputArea();
  void OutputPerimeter();
  void OutputNumberCorners();
  Shape(float s1);
  Shape(float s1, float s2);
};
void Shape::OutputArea(){
  std::cout << "Area: " << area << std::endl;
} 
void Shape::OutputPerimeter(){
  std::cout << "Perimeter: " << perimeter << std::endl;
}
void Shape::OutputNumberCorners(){
  std::cout << "Corners: " << corners << std::endl;
}
Shape::Shape(float s1){
  size1 = s1;
}
Shape::Shape(float s1,float s2):Shape(s1){
  size2 = s2;
}
/***********************************************************************
 *         Declaration/Definition of the child-classes                 *
 ***********************************************************************/

class Rectangle : public Shape{
public:
  Rectangle(float s1, float s2);
};
Rectangle::Rectangle(float s1, float s2):Shape(s1,s2){
  area = size1*size2;
  perimeter = 2*(size1+size2);
  corners = 4;
}
class Square : public Shape{
public:
  Square(float s1);
};
Square::Square(float s1):Shape(s1){
  area = pow(size1,2);
  perimeter =4*size1;
  corners = 4;
}
class Triangle : public Shape{
public:
  Triangle(float s1, float s2);
};
Triangle::Triangle(float s1, float s2):Shape(s1,s2){
  area = 0.5*size1*size2;
  perimeter = size1+size2+sqrt(pow(size1,2)+pow(size2,2));
  corners = 3;
}
class Circle : public Shape{
public:
  Circle(float s1);
};
Circle::Circle(float s1):Shape(s1){
  area = M_PI*pow(size1,2);
  perimeter = 2*M_PI*size1;
  corners = 0;
}
/***************************************************************************
 *  Main Function which is creating/reporting database (do not change!)    *
 ***************************************************************************/

int main() {

  //initialize an empty list of shapes
  std::list<Shape*> shapeDatabase;

  //interact with the user: ask the user to enter shapes one by one
  while(1) {
    //print instructions as to how to enter a shape
    std::cout << "Enter a type (Circle, Triangle, Square, or Rectangle) ";
    std::cout << "and one or two size parameters, ";
    std::cout << "separated with blank spaces:\n";

    float size1;
    float size2;

    //check which shape has been requested and store in the database
    std::string shapeType;
    std::cin >> shapeType;
    if( shapeType == std::string("Circle") ) {
      std::cin >> size1;
      shapeDatabase.push_back( new Circle( size1 ) );
    }
    else if ( shapeType == std::string("Triangle") ) {
      std::cin >> size1 >> size2;
      shapeDatabase.push_back( new Triangle(size1,size2) );
    }
    else if ( shapeType == std::string("Square") ) {
      std::cin >> size1;
      shapeDatabase.push_back( new Square(size1) );
    }
    else if (shapeType == std::string("Rectangle") ) {
      std::cin >> size1 >> size2;
      shapeDatabase.push_back( new Rectangle(size1,size2) );
    }
    else {
      std::cout << "Unrecognized shape!!\n";
    }

    //check if the user wants to add more shapes
    std::cout << "Do you want to add more shapes? (Enter Y or N)\n";
    std::string answer;
    std::cin >> answer;
    if( answer != std::string("Y") )
      break;
  }

  //iterate through the list and output the area, perimeter, 
  //and number of corners of each entered shape
  std::list<Shape *>::iterator it = shapeDatabase.begin();
  int shapeCounter = 0;
  while( it != shapeDatabase.end() )
  {
    std::cout << "Properties of shape " << shapeCounter++ << ":\n";
    (*it)->OutputArea();
    (*it)->OutputPerimeter();
    (*it)->OutputNumberCorners();
    it++;
  }

  return 0;
}