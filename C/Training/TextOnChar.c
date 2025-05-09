#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello Jacob";
    int lenght = strlen(str);
    printf("Длина строки: %d\n", lenght);
    
    for(int i=0; i < lenght; i++)
    {
        printf("%c\n", str[i]);
    }
    return 0;
}