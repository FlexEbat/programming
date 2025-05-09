// Sviniy OS ver. 14.88
// Welcome to the our OS. This's os for noob users. Our OS can perform many functions.
// You need a registration. Just write: /reg
// To see the information about the teams, enter: /help
// > 1. /calculator
// > 2. /moneytomoney
// > 3. /Funny: 1. Casino; ... ... 
// > 4. 
// 
// 
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void infoAboutOS() {    
    printf("This is a system with minimalism and unique! \n");
    printf("written completely on pure SI - no excesses. \n");
    printf("Welcome to the world of console magic! \n");
}

void Fetch() {
    printf("   █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████\n");
    printf(" ████       FATAL OS - SYSTEM DUMP       ████\n");
    printf("██▒▒   Version      : 14.88-BETA-HYSTERIA   ▒▒██\n");
    printf("██▒▒   Kernel       : BRUTALCORE 0.0.1       ▒▒██\n");
    printf("██▒▒   Arch         : x86_64 (chaos-ready)   ▒▒██\n");
    printf("██▒▒   Uptime       : ∞ (segfault-resistant) ▒▒██\n");
    printf("██▒▒   Packages     : 666 (preinstalled sins)▒▒██\n");
    printf("██▒▒   Shell        : /bin/fucksh            ▒▒██\n");
    printf("██▒▒   Window Mngr  : Bare Metal (no mercy)  ▒▒██\n");
    printf("██▒▒   Hostname     : fucktank.local         ▒▒██\n");
    printf("██▒▒   RAM          : 666MB / 1337MB          ▒▒██\n");
    printf("████  ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠ ☠  ████\n");
    printf("   █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████\n");
}

void welcoming() {
    char *red = "\033[1;31m";
    char *green = "\033[1;32m";
    char *yellow = "\033[1;33m";
    char *blue = "\033[1;34m";
    char *reset = "\033[0m";

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf(" _____ _  _____  _    _        ___  ____ \n");
    printf("|  ___/ \\|_   _|/ \\  | |      / _ \\/ ___|\n");
    printf("| |_ / _ \\ | | / _ \\ | |     | | | \\___ \\ \n");
    printf("|  _/ ___ \\| |/ ___ \\| |___  | |_| |___) |\n");
    printf("|_|/_/   \\_\\_/_/   \\_\\_____|  \\___/|____/ \n");
    printf("\n\t\t[ BRUTALIX BOOTLOADER v0.0.1 ]\n\n");

    printf("%s>> Initializing sheer chaos...         %s", red, reset);
    sleep(1);
    printf("[%sOK%s]\n", green, reset);
    printf("%s>> Mounting filesystem from the void. %s", red, reset);
    sleep(1);
    printf("[%sPARTIALLY OK%s]\n", yellow, reset);
    printf("%s>> Loading custom kernel: BRUTALCORE  %s", red, reset);
    sleep(1);
    printf("[%sHELL YES%s]\n", blue, reset);
    printf("%s>> Enabling aggressive mode...        %s", red, reset);
    sleep(1);
    printf("[%sENABLED%s]\n", green, reset);
    printf("%s>> Disabling logic checks...          %s", red, reset);
    sleep(1);
    printf("[%sDONE%s]\n", green, reset);
    printf("%s>> Running sanity check...            %s", red, reset);
    sleep(1);
    printf("[%sFAILED%s]\n\n", red, reset);
}

void Calculator() {
    int num1, num2;
    char op;

    printf("Введите выражение в формате: число оператор число (например: 10 + 5): ");
    scanf("%d %c %d", &num1, &op, &num2);

    switch (op) {
        case '+':
            printf("Результат: %d\n", num1 + num2);
            break;
        case '-':
            printf("Результат: %d\n", num1 - num2);
            break;
        case '*':
            printf("Результат: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0)
                printf("Ошибка: деление на 0\n");
            else
                printf("Результат: %d\n", num1 / num2);
            break;
        case '%':
            if (num2 == 0)
                printf("Ошибка: деление на 0\n");
            else
                printf("Результат: %d\n", num1 % num2);
            break;
        default:
            printf("Ошибка: неизвестный оператор %c\n", op);
    }
}

void Funny() {
    printf("Добро пожаловать в казино!\n");
    printf("Бросаем кости...\n");
    sleep(2);

    int roll = rand() % 100;
    if (roll < 30)
        printf("Поздравляем, ты выиграл! Пошёл нахуй!\n");
    else
        printf("ХАХАХА! Ты всё проебал!\n");
}

void Help() {
    printf("\n--- /HELP ---\n");
    printf("/calculator - Calculatro\n");
    printf("/fetch      - Information about system\n");
    printf("/casino      - Casino\n");
    printf("/help       - Help\n");
    printf("/exit       - Exit\n");
}

int main() {
    srand(time(NULL));
    char command[32];
    welcoming();

    while (1) {
        printf("\n--- [User]: (Try /help): >> ");
        scanf(" %31s", command);

        if (strcmp(command, "/calculator") == 0) {
            Calculator();
        } else if (strcmp(command, "/fetch") == 0) {
            Fetch();
        } else if (strcmp(command, "/casino") == 0) {
            Funny();
        } else if (strcmp(command, "/help") == 0) {
            Help();
        } else if (strcmp(command, "/exit") == 0) {
            printf("Смерть процессу. Выход.\n");
            break;
        } else {
            printf("Команда не распознана. Ты чё, хуйню ввёл?\n");
        }
    }

    return 0;
}