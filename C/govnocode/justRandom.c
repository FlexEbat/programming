#include <stdio.h>

int main ()
{
    short guess = 0;
    const short SECRET = 7;
    while (guess != SECRET) {
        
        printf("Введите число: ");   
        scanf("%hd", &guess);

        if(guess != SECRET) {
            printf("Попробуйте ещё раз\n");
    }   
    }
    printf("YES!!!\n");
    return 0;
}