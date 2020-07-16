#include <stdio.h>
int *function();
int main(){
    int *p;
    if(true){
        int x = 5;
        //p = &x;
    }
    p = function();
    printf("%d\n",*p);
    return 0;
}
int *function(){
    int *x = new int;
    *x = 5;
    return x;
}