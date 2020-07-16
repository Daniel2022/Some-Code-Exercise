#include <stdio.h>
int main()
{
    float Fahrenheit, Celsius;
    printf("Enter the temperature in degree F:");
    scanf("%f", &Fahrenheit);
    Celsius = (5.0/9.0)*(Fahrenheit - 32);
    printf("Converted degree in C:%f\n", Celsius);
    return 0;
}