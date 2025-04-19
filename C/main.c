#include <stdio.h>
#include <math.h>

int main (void)
{
    char array[] = {1,2,3,4,5,6,7};
    for (int i = 0; i < sizeof(array); i++){
        printf("%d", array[i]);
    }
    printf("\n");
    int pizda = sizeof(array);
    printf("%d", pizda);
    return 0;
}