#include <stdio.h>

// USE GOOGLE TRANSLATE: ALT+SHIFT+T
// USE GOOGLE SEARCH:  CTRL + ALT + G

void addition() // функция сложения
{
        float a,b;
        printf("Введите первое число: ");
        scanf("%f", &a);
        printf("Введите первое число: ");
        scanf("%f", &b);

        printf("Результат: %.2f + %.2f = %.2f", a,b,a+b);
}

void subtraction() // функция сложения
{
        float a,b;
        printf("Введите первое число: ");
        scanf("%f", &a);
        printf("Введите первое число: ");
        scanf("%f", &b);

        printf("Результат: %.2f - %.2f = %.2f", a,b,a-b);
}

void multiplication() // функция сложения
{
        float a,b;
        printf("Введите первое число: ");
        scanf("%f", &a);
        printf("Введите первое число: ");
        scanf("%f", &b);

        printf("Результат: %.2f * %.2f = %.2f", a,b,a*b);
}


int main () 
{
    int choice; // переменная для выбора
    printf("This is a calculi.Select the operation from the proposed. All numbers are presented in Float (number with a floating comma)\n");
    printf("1. Addition\n2.Subtraction\n3.Multiplication\n4.Division\n8.Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        addition();
        break;
    case 2:
        subtraction();
        break;
    case 3:
        multiplication();
        break;
    default:
    printf("The wrong choice\n");
        break;
    }

}
