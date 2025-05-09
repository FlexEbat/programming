#include <stdio.h>

int main()
{
    int age = 12;
    char name[] = "Name";
    double kilograms = 77.3;
    short days = 31;
    long years = 1999;

    printf("%d\n", age);
    printf("%s\n", name);
    printf("%.1lf\n", kilograms);
    printf("%hd\n", days);
    printf("%ld\n", years);
}