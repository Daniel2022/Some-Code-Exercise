#include <stdio.h>
#include <stdlib.h>
class Point{
public:
    int value;
    Point(int x);
    ~Point();
};
Point::Point(int x){
    value = x;
    printf("create p\n");
}
Point::~Point(){
    printf("delete p\n");
}
int main(){
    Point p(1);
    Point *c = new Point(2);
    printf("%d\n", p.value);
    return 0;
}