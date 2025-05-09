/* showf_pt.c -- отображает значение типа float двумя способами */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    char name[50], surname[50];
    printf("Введите в ваше имя, фамилия и возраст: \n");
    int16_t age;
    scanf("%49s", name);
    scanf("%49s", surname);
    scanf("%" SCNd16, &age);

    printf("Имя: %s\n", name);
    printf("Фамилия: %s\n", surname);
    printf("Ваш возраст: %" PRId16, age);
    return 0;


}


// ЗFind out what fprintf is