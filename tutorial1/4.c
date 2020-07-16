#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num[5];int i,j;char ch;
    srand((unsigned int)time(NULL));
    for(i=0;i<5;i++)
    {
        num[i] = rand()%13+1;
        printf("%d \n",num[i]);
    }
    printf("The first card (between 1 and 13): %d\n",num[0]);
    printf("Guess Higher (H) or Lower (L)\n");
    scanf("%c",&ch);
    for(j=1;j<5;j++)
    {
        printf("The next card (between 1 and 13): %d\n", num[j]);
        if((num[j-1]<num[j] && ch == 'H')||(num[j-1]>num[j] && ch == 'L'))
            printf("Guess Higher (H) or Lower (L)\n");
        else if(ch == 'L' || ch == 'H')
        {
            printf("You Lose\n");
            break;
        }
        else
        {
            printf("Please enter 'L' or 'H'\n");
            j -= 1;
        }
        scanf("\n%c",&ch);
    }
}