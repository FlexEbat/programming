#include <stdio.h>

int main()
{
    int num, sum = 0;
    printf("Вводитее числа, пока не будет 0 - выход\n");
    while (1)
    {
        printf("Вводите числа: ");
        scanf("%d", &num);
        if(num == 0) {
            break;
        }
        sum+=num;
    }
    printf("Сумма чисел = %d", sum);
    return 0;
    
}