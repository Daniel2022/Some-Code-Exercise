#include <stdio.h>
typedef struct{
    int id;
    int totalLeave;
    int leaveTaken;
}leaveRecord;
void getInput(leaveRecord list[], int *n);
int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
int main()
{
    leaveRecord list[10] = {{0,0,0}};
    int n, id, leave;
    getInput(list, &n);
    printf("%d\n", n);
    //printf("%d %d %d\n", list[0].id, list[0].totalLeave, list[0].leaveTaken);
    scanf("%d %d", &id, &leave);
    printf("%d\n",mayTakeLeave(list, id, leave, n));
}
void getInput(leaveRecord list[], int *n)
{
    //int i=0;int id, totalLeave, leaveTaken;
    /*
    do{
        scanf("%d", &id);
        if(id == 0)
            break;
        else{
            scanf("%d %d", &totalLeave, &leaveTaken);
            list[i].id = id;
            list[i].totalLeave = totalLeave;
            list[i].leaveTaken = leaveTaken;
        }
        i++;
    }while(1);
    *n = i;
    */
   *n = 0;
   while(scanf("%d %d %d", &list[*n].id, &list[*n].totalLeave, &list[*n].leaveTaken) != EOF)
   {
       (*n)++;
   }
}
int mayTakeLeave(leaveRecord list[], int id, int leave, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(list[i].id == id)
            return (leave+list[i].leaveTaken<=list[i].totalLeave) ? 1 : 0;
    }
    return -1;
}