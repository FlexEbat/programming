#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MIN_AGE 16
#define MAX_AGE 25

typedef struct {
    char name[50], surname[50], middleName[50];
    unsigned int age;
    double average_score;
} Student;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_student(Student students[MAX_STUDENTS], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("[-] Нельзя добавить больше студентов!\n");
        return;
    }

    clear_input_buffer();

    printf("Введите фамилию: ");
    fgets(students[*count].surname, sizeof(students[*count].surname), stdin);
    students[*count].surname[strcspn(students[*count].surname, "\n")] = 0;

    printf("Введите имя: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    printf("Введите отчество: ");
    fgets(students[*count].middleName, sizeof(students[*count].middleName), stdin);
    students[*count].middleName[strcspn(students[*count].middleName, "\n")] = 0;

    while (1) {
        printf("Введите возраст (%d-%d): ", MIN_AGE, MAX_AGE);
        if (scanf("%u", &students[*count].age) != 1) {
            printf("[-] Ошибка: возраст — это ЧИСЛО!\n");
            clear_input_buffer();
            continue;
        }
        if (students[*count].age < MIN_AGE || students[*count].age > MAX_AGE) {
            printf("[-] Возраст вне допустимого диапазона!\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Введите средний балл: ");
        if (scanf("%lf", &students[*count].average_score) != 1) {
            printf("[-] Ошибка: балл — это ЧИСЛО!\n");
            clear_input_buffer();
            continue;
        }
        break;
    }

    (*count)++;
    printf("[+] Студент успешно добавлен!\n");
}

void show_students(Student students[MAX_STUDENTS], int count) {
    if (count == 0) {
        printf("[-] Студентов пока нет.\n");
        return;
    }

    printf("Список студентов:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s %s %s | Возраст: %u | Ср. балл: %.2lf\n",
               i + 1,
               students[i].surname,
               students[i].name,
               students[i].middleName,
               students[i].age,
               students[i].average_score);
    }
}

void show_best_student(Student students[MAX_STUDENTS], int count) {
    if (count == 0) {
        printf("[-] Студентов нет.\n");
        return;
    }

    int best = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].average_score > students[best].average_score) {
            best = i;
        }
    }

    printf("\nЛучший студент:\n%s %s %s | Возраст: %u | Ср. балл: %.2lf\n",
           students[best].surname,
           students[best].name,
           students[best].middleName,
           students[best].age,
           students[best].average_score);
}

void menu() {
    Student students[MAX_STUDENTS];
    int count = 0;
    char input[20];

    while (1) {
        printf("\n  МЕНЮ  \n");
        printf("ADD   - Добавить студента\n");
        printf("SHOW  - Показать всех студентов\n");
        printf("BEST  - Показать лучшего студента\n");
        printf("EXIT  - Выйти\n");
        printf(">>> ");

        scanf("%19s", input);

        if (strcmp(input, "ADD") == 0) {
            add_student(students, &count);
        } else if (strcmp(input, "SHOW") == 0) {
            show_students(students, count);
        } else if (strcmp(input, "BEST") == 0) {
            show_best_student(students, count);
        } else if (strcmp(input, "EXIT") == 0) {
            printf("Пака\n");
            break;
        } else {
            printf("[-] Неизвестная команда: %s\n", input);
        }
    }
}

int main() {
    menu();
    return 0;
}
