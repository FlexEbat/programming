#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для генерации матрицы случайных двузначных чисел
void generateMatrix(int mat[10][10]) {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            mat[i][j] = rand() % 90 + 10; // числа от 10 до 99
}

// Функция для вывода матрицы
void printMatrix(int mat[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

// Сортировка строк по возрастанию (сортировка пузырьком)
void sortRows(int src[10][10], int dst[10][10]) {
    // Копируем матрицу
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dst[i][j] = src[i][j];

    // Сортируем каждую строку пузырьком
    for (int i = 0; i < 10; ++i)
        for (int pass = 0; pass < 10 - 1; ++pass)
            for (int j = 0; j < 10 - pass - 1; ++j)
                if (dst[i][j] > dst[i][j + 1]) {
                    int temp = dst[i][j];
                    dst[i][j] = dst[i][j + 1];
                    dst[i][j + 1] = temp;
                }
}

// Сортировка столбцов по возрастанию (сортировка пузырьком)
void sortColumns(int src[10][10], int dst[10][10]) {
    // Копируем матрицу
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dst[i][j] = src[i][j];

    // Сортируем каждый столбец пузырьком
    for (int j = 0; j < 10; ++j)
        for (int pass = 0; pass < 10 - 1; ++pass)
            for (int i = 0; i < 10 - pass - 1; ++i)
                if (dst[i][j] > dst[i + 1][j]) {
                    int temp = dst[i][j];
                    dst[i][j] = dst[i + 1][j];
                    dst[i + 1][j] = temp;
                }
}

int main() {
    int matrix[10][10];
    int sorted[10][10];
    int choice;

    srand((unsigned int) time(NULL));

    generateMatrix(matrix);

    while (1) {
        printf("\nИсходная матрица:\n");
        printMatrix(matrix);
        printf("\nМеню:\n");
        printf("1 - Отсортировать по строкам (слева наименьшее, справа наибольшее)\n");
        printf("2 - Отсортировать по столбцам (сверху наименьшее, снизу наибольшее)\n");
        printf("3 - Генерировать новые случайные числа\n");
        printf("0 - Выход\n");
        printf("Выберите пункт меню: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) {
            printf("Выход из программы.\n");
            break;
        }

        switch (choice) {
            case 1:
                sortRows(matrix, sorted);
                printf("\nМатрица после сортировки по строкам:\n");
                printMatrix(sorted);
                break;
            case 2:
                sortColumns(matrix, sorted);
                printf("\nМатрица после сортировки по столбцам:\n");
                printMatrix(sorted);
                break;
            case 3:
                generateMatrix(matrix);
                printf("\nНовая матрица сгенерирована.\n");
                break;
            default:
                printf("Неправильный выбор, попробуйте снова.\n");
                break;
        }
    }
    return 0;
}
