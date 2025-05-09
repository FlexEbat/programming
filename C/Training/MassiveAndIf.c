#include <stdio.h>

int main()
{
    int numbers[5];
    int sum = 0;

    printf("Введите 5 рандомных чисел.\n");

    for(int i=0; i < 5; i++){
        printf("Введите число %d: ", i+1);
        scanf("%d", &numbers[i]);
        sum+=numbers[i];
    }
    printf("Сумма чисел = %d\n", sum);

    if(sum % 2 == 0) {
        printf("Число четное");
    } else {
        printf("Число нечетное");
    }
    return 0;
}