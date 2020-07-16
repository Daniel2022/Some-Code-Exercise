#include <stdio.h>
float calculatefee(int length, int time)
{
    int startfee;
    float singlefee, fee;
    startfee = 13;
    if(time<23 && time>=5)
        singlefee = 3.3;
    else
        singlefee = 3.3*1.2;
    if(length<=3)
        fee = startfee;
    else
        fee = startfee+(length-3)*singlefee;
    return fee+1;
}
int main()
{
    float total = calculatefee(12,9)+calculatefee(12,18);
    printf("打车总费用为%f\n", total);
    return 0;
}