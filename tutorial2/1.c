#include <stdio.h>
int main(void)
{
    int number, *p;
    p = 100; number = 8;
    printf("number = %d &number = %p p = %p &p = %p *p = %d",number,&number,p,&p,*p);
    number = p;
    printf("number = %d &number = %p p = %p &p = %p *p = %d",number,&number,p,&p,*p);
    p = &number;
    printf("number = %d &number = %p p = %p &p = %p *p = %d",number,&number,p,&p,*p);
    *p = 10;
    printf("number = %d &number = %p p = %p &p = %p *p = %d",number,&number,p,&p,*p);
    number = &p;
    printf("number = %d &number = %p p = %p &p = %p *p = %d",number,&number,p,&p,*p);
    p = &p;
    printf("number = %d &number = %p p = %p &p = %p *p = %d",number,&number,p,&p,*p);
}