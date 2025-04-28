#include <stdio.h>
#include <string.h>

#define NEWS_COUNT 3
#define MAX_LEN 32

const char *news[NEWS_COUNT] = {
    "1. В стране прошёл дождь.",
    "2. Курс доллара стабилен.",
    "3. Учёные открыли новый элемент."
};

typedef struct {
    char handle[MAX_LEN];
    char realname[MAX_LEN];
    char city[MAX_LEN];
    char birthdate[MAX_LEN];
    char email[MAX_LEN];
    char password[MAX_LEN];
} UserProfile;

void print_line(int width, char ch) {
    for (int i = 0; i < width; ++i) putchar(ch);
    putchar('\n');
}

void print_section_line(const char *title, int width) {
    int len = (int)strlen(title);
    printf("-[ %s ]", title);
    for (int i = 7 + len; i < width; ++i) putchar('_');
    putchar('\n');
}

void print_field(const char *label, const char *value) {
    printf(" %-14s : %-30s\n", label, value ? value : "");
}

void input_field(const char *prompt, char *buf, int buflen) {
    printf("%s: ", prompt);
    if (fgets(buf, buflen, stdin)) {
        size_t l = strlen(buf);
        if (l && buf[l-1] == '\n') buf[l-1] = 0;
    }
}

void registration(UserProfile *user) {
    print_section_line("Регистрация", 60);
    input_field("Handle (ник)", user->handle, MAX_LEN);
    input_field("Real Name", user->realname, MAX_LEN);
    input_field("City/State", user->city, MAX_LEN);
    input_field("Birthdate", user->birthdate, MAX_LEN);
    input_field("Email", user->email, MAX_LEN);
    input_field("Password", user->password, MAX_LEN);
    printf("\nРегистрация завершена! Нажмите Enter для продолжения...");
    getchar();
}

void show_profile(const UserProfile *user) {
    printf("\n");
    print_section_line("Профиль пользователя", 60);
    print_field("Handle", user->handle);
    print_field("Real Name", user->realname);
    print_field("City/State", user->city);
    print_field("Birthdate", user->birthdate);
    print_field("Email", user->email);
    printf("\nНажмите Enter для возврата в меню...");
    getchar();
}

void show_news() {
    printf("\n");
    print_section_line("Новости дня", 60);
    for (int i = 0; i < NEWS_COUNT; ++i) {
        print_field("", news[i]);
    }
    printf("\nНажмите Enter для возврата в меню...");
    getchar();
}

void main_menu(UserProfile *user) {
    int choice = 0;
    do {
        printf("\n");
        print_section_line("Главное меню", 60);
        printf(" 1. Профиль\n");
        printf(" 2. Новости\n");
        printf(" 0. Выход\n");
        printf("Выберите пункт: ");
        char buf[8];
        if (!fgets(buf, sizeof(buf), stdin)) break;
        choice = buf[0] - '0';
        switch (choice) {
            case 1: show_profile(user); break;
            case 2: show_news(); break;
            case 0: printf("Выход...\n"); break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 0);
}

int main(void) {
    UserProfile user = {0};
    registration(&user);
    main_menu(&user);
    return 0;
}
