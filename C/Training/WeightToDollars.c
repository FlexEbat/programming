#include <stdio.h>

int main()
{
    const double pounds = 2.2046;
    double kilogram;
    printf("Введите вес в КГ: ");
    if(scanf("%lf", &kilogram) !=1){
        printf("Неправильный ввод");
        return 1;
    }
    printf("Вы ввели %.2lf килограмм.\n", kilogram);
    double kgToPounds = kilogram * pounds; 
    printf("Что равняется %.2lf фунтов\n", kgToPounds);
    double PoundsToDollars = kgToPounds * 38;
    printf("Цена за фунт - 38$. Итоговая стоимость: %.1lf долларов", PoundsToDollars);
    return 0;

}