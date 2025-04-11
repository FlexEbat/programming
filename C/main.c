#include <stdio.h>
#define ADJUST 7.31
int main (void)
{
    const double SCALE = 0.333; 
    double shoe, foot;
    printf("Размер обуви (^мужской) длина ступни\n");
    shoe = 3.0;
    while (shoe < 18.5)
{
    foot = SCALE * shoe + ADJUST;
    printf("%10.lf %20.2f даймов\n", shoe, foot);
    shoe = shoe + 1.0;
} 
printf("Если обувь подходит, носите ее.\n");
return 0;
}