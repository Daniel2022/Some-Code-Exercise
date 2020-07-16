#include <stdio.h>
int main()
{
    printf("%d\n",125);
    printf("%+6d\n",125);
    printf("%-6d\n",125);
    printf("%-11.5f001\n",125.1112);
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d,%d\n",n1,n2);
    char ch, ch2;
    putchar('\n');
    ch2 = getchar();
    putchar(ch2);
    putchar('\n');
    return 0;
}