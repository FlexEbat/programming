/*
 Регистрация > Авторизация > Выбор ресторана > Ресторан > Заказ из ресторана > Сохранение заказа > Курьер пидарас(1488)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 50
#define MAX_USERS 5
#define MAX_AGE 100
#define MIN_AGE 18

// int registration()
// {
//     char nickname[MAX_NAME];
//     char surname[MAX_NAME];
//     char age_str[10];
//     int age;

//     printf("Введите ваше имя: ");
//     if(fgets(nickname, sizeof(nickname), stdin) != NULL) {
//         size_t len = strlen(nickname);
//         if (len > 0 && nickname[len - 1] == '\n') {
//             nickname[len - 1] = '\0';
//         }
//     } else {
//         printf("Ошибка ввода имени.\n");
//         return 1; // Error code   
//     }
    
//     printf("Введите вашу фамилию: ");
//     if(fgets(surname, sizeof(surname), stdin) != NULL) {
//         size_t len = strlen(surname);
//         if (len > 0 && surname[len - 1] == '\n') {
//             surname[len - 1] = '\0';
//         }
//     } else {
//         printf("Ошибка ввода фамилии.\n");
//         return 1; // Error code
//     }

//     printf("Введите ваш возраст: ");
//     if(fgets(age_str, sizeof(age_str), stdin) != NULL) {
//         age = atoi(age_str);
//         if (age < MIN_AGE || age > MAX_AGE) {
//             printf("Возраст должен быть в диапазоне %d-%d.\n", MIN_AGE, MAX_AGE);
//             return 1; // Error code
//         }
//     } else {
//         printf("Ошибка ввода возраста.\n");
//         return 1; // Error code
//     }
//     return 0;
// }

int authorization(char nickname[MAX_NAME], char secret_phrase[MAX_NAME])
{
    char input_nick[MAX_NAME];
    char input_phrase[MAX_NAME];
    
    printf("Введите ваш никнейм, который вы указали во время регистрации: ");
    if(fgets(input_nick, MAX_NAME, stdin) != NULL) {
        input_nick[strcspn(input_nick, "\n")] = 0;
        if(strcmp(input_nick, nickname) != 0) {
            printf("Неверный никнейм\n");
            return 0;
        }
    }

    printf("Теперь введи вашу секретную фразу: ");
    if(fgets(input_phrase, MAX_NAME, stdin) != NULL) {
        input_phrase[strcspn(input_phrase, "\n")] = 0;
        if(strcmp(input_phrase, secret_phrase) != 0) {
            printf("Неверная секретная фраза\n");
            return 0;
        }
    }
    return 1;
}

void NogaMusulmanina() {
    char dish1[] = "Яйца с яйцами";
    char dish2[] = "Масло со снегом";
    char dish3[] = "Член под соусом из бараньих глаз";
    double price1 = 250.0;
    double price2 = 78.2;
    double price3 = 134.5;
    printf("Блюдо: %s; Цена: %3.1lf\n", dish1, price1);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish2, price2);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish3, price3);
}

void YDyadiAshota()
{
    char dish1[] ="Жаренные коровьи губы";
    char dish2[] = "Анальный сок марьяны сро";
    char dish3[] = "Ноги маджахета";
    double price1 = 14.88;
    double price2 = 633.0;
    printf("Блюдо: %s; Цена: %3.1lf\n", dish1, price1);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish2, price2);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish3, price3);
    double price3 = 0.88;
}

void YandexEda()
{
    char dish1[] = "Зубы залупы";
    char dish2[] = "Двойник Аллаха";
    char dish3[] = "Пизда Светы из Букиных";
    double price1 = 14.000;
    double price2 = 00.88;
    double price3 = 633.0;
    printf("Блюдо: %s; Цена: %3.1lf\n", dish1, price1);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish2, price2);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish3, price3);
}

void KFC()
{
    char dish1[] = "";
    char dish2[] = "";
    char dish3[] = "";
    double price1 = ;
    double price2 = ;
    double price3 = ;
    printf("Блюдо: %s; Цена: %3.1lf\n", dish1, price1);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish2, price2);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish3, price3);
}

void Macdonalds()
{
    char dish1[] = "";
    char dish2[] = "";
    char dish3[] = "";
    double price1 = ;
    double price2 = ;
    double price3 = ;
    printf("Блюдо: %s; Цена: %3.1lf\n", dish1, price1);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish2, price2);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish3, price3);
}

void ChlenBarana()
{
    char dish1[] = "";
    char dish2[] = "";
    char dish3[] = "";
    double price1 = ;
    double price2 = ;
    double price3 = ;
    printf("Блюдо: %s; Цена: %3.1lf\n", dish1, price1);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish2, price2);
    printf("Блюдо: %s; Цена: %3.1lf\n", dish3, price3);
}

void restaurants() {
    printf("СПИСОК РЕСТОРАНОВ: \n");
    printf("ВЫБОР РЕСТОРАНА\n");
    printf("1. Noga musulmanina\n");
    printf("2. Y dyadi ashota\n");
    printf("3. Yandex eda\n");
    printf("4. Kentyki fried Pig for muslims\n");
    printf("5. Y d9di allaha\n");
    printf("6. Chlen barana\n");
}

void Dishes(int* choice)
{
    if (*choice == 1)
    {
        printf("Noga musulmanina\n");
    }
    else if (*choice == 2)
    {
        printf("Вы выбрали ресторан Y dyadi ashota\n");
        printf("Блюда:\n");
        printf("1. Жаренные коровьи губы\n");
        printf("2. Анальный сок марьяны сро\n");
        printf("3. варенные лошадиные зубi\n");
    }
    else if (*choice == 3)
    {
        printf("Вы выбрали ресторан Yandex eda");
        printf("Блюда:\n");
        printf("1. Российские тапки\n");
        printf("2. Двойственная чума\n");
        printf("3. гречка под толстяком\n");
    }
    else if (*choice == 4)
    {
        printf("Вы выбрали ресторан KFC\n");
        printf("Блюда:\n");
        printf("1. Сельдь под шубой\n");
        printf("2. Стрипсы\n");
        printf("3. Бурджер\n");
    }
    else if (*choice == 5)
    {
        printf("Вы выбрали ресторан Macdonalds\n");
        printf("Блюда:\n");
        printf("1. Ганжубас по сливочной спермой\n");
        printf("2. Герман Цыганов\n");
        printf("3. Егор Евстафьев\n");
    }
    else if (*choice == 6)
    {
        printf("Вы выбрали ресторан Chlen barana\n");
        printf("Блюда: \n");
        printf("1. Дрюча под мефедроном\n");
        printf("2. кирпич с сюрпризом\n");
        printf("3. синяк под глазом\n");

    }
    else
    {
        printf("Ты долбаеб, нет такого рестика\n");
    }
}

int Check(int* choice)
{
        printf("\tSHOP RECEIPT\n");
        printf("%d", choice);
        printf("----------------------------------------------")
}

int main()
{
    char answer[3];
    printf("Перед тем, как ты увидишь наш прейскурант. Ты должен Zарегистрироваться, а потом уже пойдёшь нахуй\n");
    printf("Уверен, что ты не пидорас?: ");
    scanf("%2s", answer);
    getchar(); // Clear the newline

    if(strcmp(answer, "Yes") != 0) {
        printf("Иди нахуй отсюда\n");
        return 0;
    }
    
    printf("Ладно, фейс-контроль ты прошёл и можешь идти нахуй\n");

    return 0;
}