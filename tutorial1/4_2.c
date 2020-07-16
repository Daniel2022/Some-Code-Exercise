#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int num[5];int i,j,flag;char ch;
    srand((unsigned int)time(NULL));
    for(i=0;i<5;i++)
    {
        num[i] = rand()%13+1;
        //printf("%d \n",num[i]);
    }
    printf("The first card (between 1 and 13): %d\n",num[0]);
    for(j=0;j<4;j++)
    {
        printf("Guess Higher (H) or Lower (L)\n");
        scanf("\n%c",&ch);        
        if(ch!='L'&&ch!='H'&&ch!='E')
        {
            printf("Please enter 'L' or 'H'\n");
            j -= 1;
        }
        else
        {
            printf("The next card (between 1 and 13): %d\n",num[j+1]);
            if((num[j]<num[j+1] && ch == 'H')||(num[j]>num[j+1] && ch == 'L')||(num[j]==num[j+1]&&ch=='E'))
            {
                flag = 1;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        
    }
    if(flag==1)
        printf("You win\n");
    else
        printf("You lose\n");
}