#include <stdio.h>
#include <math.h>

int main (void)
{
    double sumCredite, interestRate, r, powRate, annuitePayment;
    int month;
    printf("Привет. Это калькулятор ипотеки.\n");
    printf("Считаемтолько Аннуитетные платежи.\n");
    printf("Введит сумму кредита(Пример: 1000000): ");
    if(scanf("%lf", &sumCredite) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        return 1; // Возвращаем ошибку
    }
    if(sumCredite <= 0) {
        printf("Сумма кредита не может <=0.\n");
        return 1; // Возвращаем ошибку
    }
    printf("Введите срок кредита в месяцах(Пример: 10): ");
    if(scanf("%d", &month) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        return 1; // Возвращаем ошибку
    }
    if(month <= 0) {
        printf("Срок кредита не может <=0.\n");
        return 1; // Возвращаем ошибку
    }
    printf("Введите процентную ставку(Пример: 10): ");
    if(scanf("%lf", &interestRate) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        return 1; // Возвращаем ошибку
    }
    if(interestRate <= 0) {
        printf("Процентная ставка не может <=0.\n");
        return 1; // Возвращаем ошибку
    }
    r = (interestRate / 100.0) / 12.0;         // Месячная ставка
    powRate = pow(1 + r, month);                // Степень
    annuitePayment = sumCredite * (r * powRate) / (powRate - 1); // Готово
    
    printf("Ваши аннуитетные платежи составляют: %.2lf\n", annuitePayment);
    printf("Общая сумма выплат составит: %.2lf\n", annuitePayment * month);

    printf("Общая переплата составит: %.2lf\n", (annuitePayment * month) - sumCredite);
    printf("Сумма тела кредита составит: %.2lf\n", sumCredite);
    return 0; 
}




