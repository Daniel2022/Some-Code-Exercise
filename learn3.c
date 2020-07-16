#include <stdio.h>
int main()
{
	int a = 5; int b = 9;
	printf("%d\n", b++>=a*2 && b-a<=a);
	printf("%d\n", b++>=a*2 || b-a<=a);
	printf("%d\n", !(a*2-b));
	printf("试试%d\n", ++b-a*2);
	return 0;
}