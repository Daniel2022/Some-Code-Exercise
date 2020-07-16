#include <stdio.h>
void transpose(int M[3][3]);
void swap2Rows(int M[3][3],int r1, int r2);
void swap2Cols(int M[3][3],int c1, int c2);
int main(void)
{
    int M[3][3];
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", M[i]+j);
        }
    }
    printf("\n");
    transpose(M);
    printf("\n");
    swap2Rows(M, 1, 2);
    printf("\n");
    swap2Cols(M, 1, 2);
    return 0;
}
void transpose(int M[3][3])
{
    int temp[3][3];int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            temp[j][i] = M[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            M[i][j] = temp[i][j];
            printf("%-6d",M[i][j]);
        }
        printf("\n");
    }
}
void swap2Rows(int M[3][3],int r1, int r2)
{
    int i,j,temp;
    for(i=0;i<3;i++)
    {
        temp = M[r1][i];
        M[r1][i] = M[r2][i];
        M[r2][i] = temp;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%-6d",M[i][j]);
        }
        printf("\n");
    }
}
void swap2Cols(int M[3][3],int c1, int c2)
{
    int i,j,temp;
    for(i=0;i<3;i++)
    {
        temp = M[i][c1];
        M[i][c1] = M[i][c2];
        M[i][c2] = temp;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%-6d",M[i][j]);
        }
        printf("\n");
    }
}