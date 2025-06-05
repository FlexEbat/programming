#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rubToDollar() {
    char buffer[64];
    double rub, dollar;
    printf("Введите сумму в рублях (округление до 2-х знаков): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;

        if (sscanf(buffer, "%lf", &rub) != 1) {
            printf("Неверный ввод. Введи нормальное число, долбоёб.\n");
            return;
        }
        dollar = rub / 77.5000;
        printf("Курс доллара: 77.5000\n");
        printf("Сумма в долларах: %.2lf$\n", dollar);
    }
}

void CountingStrings() {
    int n1 = 0;
    char buffer[256];
    printf("Вводи строки (пустая строка - выход):\n");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
        if (buffer[0] == '\n') {
            break;
        }
        n1++;
    }
    printf("Кол-во строк: %d\n", n1);
    printf("Жми Enter, чтобы в меню вернуться...");
    fgets(buffer, sizeof(buffer), stdin);
}

void CountingCharacters() {
    char buffer[1024];
    printf("Введи строку: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Считаем символы без учета '\n'
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            len--;
        }
        printf("Кол-во символов: %zu\n", len);
    }
}

int Note(void) {
    char path[250];
    char line[1024];
    FILE *f;

    printf("Введи полный путь до заметки: ");
    if (!fgets(path, sizeof(path), stdin)) {
        fprintf(stderr, "Не смог прочитать путь\n");
        return 1;
    }
    size_t len = strlen(path);
    if (len > 0 && path[len - 1] == '\n') {
        path[len - 1] = '\0';
    }

    f = fopen(path, "w");
    if (!f) {
        perror("Не могу открыть файл");
        return 1;
    }

    printf("Вводи текст. Точка (.) на отдельной строке — конец:\n");

    while (1) {
        if (!fgets(line, sizeof(line), stdin)) {
            fprintf(stderr, "Ввод прерван, пиздец\n");
            fclose(f);
            return 1;
        }

        if (strcmp(line, ".\n") == 0 || strcmp(line, ".\r\n") == 0) {
            break;
        }

        fputs(line, f);
    }

    if (fclose(f) != 0) {
        perror("Ошибка при закрытии файла, пиздец");
        return 1;
    }

    printf("Готово. Заметка сохранена: %s\n", path);
    return 0;
}

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int MassiveAndArray(void) {
    char buffer[64];
    int SIZE;

    printf("Введи размер массива: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &SIZE) != 1 || SIZE < 1) {
        printf("Ну блядь, нормально введи размер массива, а не эту хуйню.\n");
        return 1;
    }

    int *number = malloc(sizeof(int) * SIZE);
    if (!number) {
        printf("Пиздец, не хватает памяти.\n");
        return 1;
    }

    printf("У тебя пустой массив на %d элементов. Заполняй!\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        while (1) {
            printf("Введи значение для элемента %d: ", i + 1);
            if (fgets(buffer, sizeof(buffer), stdin) && sscanf(buffer, "%d", &number[i]) == 1) {
                break;
            }
            printf("Ну введи нормально число, идиот!\n");
        }
    }

    printf("Твой массив: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", number[i]);
    }
    printf("\nРазмер массива: %d\n", SIZE);

    free(number);
    return 0;
}

int main() {
    char buffer[8];
    int choice;

    while (1) {
        printf("\n");
        printf("__  __               _ _______________   _____ ___   ___  _     _     \n");
        printf("\\ \\/ /   _ _ __ ___ / |___ /___ /___  | |_   _/ _ \\ / _ \\| |   ( )___ \n");
        printf(" \\  / | | | '_ ` _ \\| | |_ \\ |_ \\  / /    | || | | | | | | |   |// __|\n");
        printf(" /  \\ |_| | | | | | | |___) |__) |/ /     | || |_| | |_| | |___  \\__ \\\n");
        printf("/_/\\_\\__,_|_| |_| |_|_|____/____//_/      |_| \\___/ \\___/|_____| |___/\n");
        printf("\n[!]https://github.com/flexebat\n");
        printf("[!]For educational use only, don't be a fuckhead!\n\n");

        printf("Выбери действие:\n");
        printf("1. Посчитать количество строк\n");
        printf("2. Посчитать количество символов\n");
        printf("3. Конвертировать рубли в доллары\n");
        printf("4. Создать заметку\n");
        printf("5. Работа с массивом чисел\n");
        printf("0. Выход\n");
        printf("$$<>$$: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Ошибка ввода, пиздец.\n");
            break;
        }
        if (sscanf(buffer, "%d", &choice) != 1) {
            printf("Нужно ввести число, долбоёб!\n");
            continue;
        }

        switch (choice) {
            case 1:
                CountingStrings();
                break;
            case 2:
                CountingCharacters();
                break;
            case 3:
                rubToDollar();
                break;
            case 4:
                Note();
                break;
            case 5:
                MassiveAndArray();
                break;
            case 0:
                printf("Пошёл на хуй!\n");
                return 0;
            default:
                printf("Неправильный выбор, ебанат!\n");
                break;
        }
    }
    return 0;
}
