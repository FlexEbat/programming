#include <stdio.h>

int main()
{
    int code[4];
    printf("Введите свой пароль.\n");
    printf("Введите первый символ пароля: ");
    scanf("%d", &code[0]);
    printf("Введите второй символ пароля: ");
    scanf("%d", &code[1]);
    printf("Введите третий символ пароля: ");
    scanf("%d", &code[2]);
    printf("Введите четвертый символ пароля: ");
    scanf("%d", &code[3]);
     
    printf("Ваш пароль: "); 
    for(int i = 0; i < sizeof(code)/sizeof(code[0]); i++)
    {
        printf("%d", code[i]);
    }
    return 0;
}
