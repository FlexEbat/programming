#include <stdio.h>

int square(int x){
    return x*x;
}
int main()
{
    int x;
    printf("Введите число(x^x): ");
    scanf("%d", &x);
    printf("Результат: %d", square(x));
    return 0;
}