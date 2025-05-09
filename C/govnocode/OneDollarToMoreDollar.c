#include <stdio.h>

#define SIZE 5

int main() {
    for(int i = 1; i <= SIZE; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("$");
        }
        printf("\n");
    }

    return 0;
}