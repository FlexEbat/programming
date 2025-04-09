#include <stdio.h>

int main()
{
    char name[50];
    int width, widthforname;
    printf("Введите ширину поля: ");
    scanf("%d", &width);

    printf("Введите ширину поля для имени: ");
    scanf("%d", &widthforname);

    printf("Введите ваше имя: ");
    scanf("%49s", name);

    printf("%*sПривет, \"%*s\"\n", width, "", widthforname, name);

}
