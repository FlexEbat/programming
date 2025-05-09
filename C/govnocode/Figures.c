#include <stdio.h>

void drawSquare() 
{
    int width, lenghth;
    printf("Введите ширину: ");
    scanf("%d", &width);
    printf("Введите длину: ");
    scanf("%d", &lenghth);
    
    if (width == lenghth) {
        for(int i = 0; i < width; ++i) {
            for(int i = 0; i < lenghth; ++i) {
                printf("* ");
            }
            printf("\n");
    }
    } else {
        printf("Это не квадрат, а прямоугольник\n");
    }
}

void drawRectangle() 
{
    int width, lenghth;
    printf("Введите ширину: ");
    scanf("%d", &width);
    printf("Введите длину: ");
    scanf("%d", &lenghth);
    
    if (lenghth > width) {
        for(int i = 0; i < width; ++i) {
            for(int i = 0; i < lenghth; ++i) {
                printf("* ");
            }
            printf("\n");
    }
    } else {
        printf("Это не прямоугольник, а квадрат\n");
    }
}

int main() 
{
    int figure;

    printf("Вывод простейших фигур на экран в виде (*). Выберите фигуру из меню и ловите культурный шок\n");
    printf("Выбор осуществляется одной буквой: a - квадрат, b - прямоугольник\n");
    printf("1. Квадрат\n2. Прямоугольник\n");
    printf("Вaш выбор: ");
    scanf("%d", &figure);
    
    if (figure == 1) {
        drawSquare();
    } else if (figure == 2) {
        drawRectangle();
        }
    }

