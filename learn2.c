#include <stdio.h>
int main()
{
	int a,b;
	a = 3; b = 4;
	printf("%d\n",b);
	printf("%d\n",a);
	printf("%d\n",a+b%(a+b)/a+a*b-b);
	return 0;
}