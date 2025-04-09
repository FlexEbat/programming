#include <stdio.h>

int main() {
    char name[50];
    unsigned short age;
    printf("Введит ваше имя: ");
    scanf("%49s", name);
    printf("Введите ваш возраст: ");
    scanf("%hu", &age);
    if (age > 1 && age < 100) {
        printf("Вас зовут: %s и вам: %hu лет\n", name, age);
    } else {
        printf("Ошибка: Вы ввели неправильный возраст. > 1 AGE < 100\n");
    }
        return 0;
    }
