// из целььсия в фаренгейты

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    printf("Enter the temperature in Celsiusus: ");
    double celsius;
    scanf("%lf", &celsius);
    double fahrenheit = (celsius * 1.8) + 32;
    printf("Temp to fahrenheit: %.3f\n", fahrenheit);
    return 0;
}
