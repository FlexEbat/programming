#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint8_t num = 255;
    printf("num = %" PRId8 "\n", num); // = 255
    num++;
    printf("num = %" PRId8 "\n", num); // = 0
    return 0;
}