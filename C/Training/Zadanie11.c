#include <stdio.h>

int main()
{
    int x = 1337;
    int* p = &x;
    printf("x = %d, p = %p, *p = %d\n", x, p, *p);
    return 0;
}