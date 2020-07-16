#include <stdio.h>
int main()
{
    int i,n,sum,num;float average;
    printf("Enter the number of input lines: 2\n");
    for(i=1;i<3;i++)
    {
        sum = 0;num = 0;
        printf("Enter input line %d: ",i);
        do{
            scanf("%d",&n);
            if(n!=-1)
            {
                sum += n;
                num += 1;
            }
        }while(n!=-1);
        average = (float)sum/num;
        printf("Average: %f\n",average);
    }
}