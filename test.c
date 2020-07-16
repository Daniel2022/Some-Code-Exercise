#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    int count;
    printf("Command Line Arguments:\n");
    printf("argc = %d\n", argc);
    for (count=0; count < argc; count++) {
        printf("argv[%d] = %s\n", count, argv[count]);
    }
    return 0;
}
