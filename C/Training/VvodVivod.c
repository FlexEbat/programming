#include <stdio.h>
#include <string.h>
int main()
{
    int age;
    char name[50];
   printf("Введите ваш возраст: ");
   scanf("%d", &age);
   printf("Введите ваше имя: ");
   scanf("%49s", name);
   printf("Привет %s. Тебе %d лет", name, age);
   return 0;
}