#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size;

    // Запрашиваем размер матрицы у пользователя
    printf("Введите размер матрицы: ");
    scanf("%d", &size);

    if (size > 10 || size < 1) {
        printf("Размер матрицы должен быть от 1 до 10.\n");
        return 1;
    }

    int matrix[size][size];

    srand(time(NULL));

    // Заполняем матрицу случайными числами от 100 до 999
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 900 + 100;
        }
    }

    // Выводим исходную матрицу
    printf("\nИсходная матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Считаем суммы главной и побочной диагоналей
    int main_sum = 0, second_sum = 0;
    for (int i = 0; i < size; i++) {
        main_sum += matrix[i][i];
        second_sum += matrix[i][size - 1 - i];
    }

    printf("\nСумма главной диагонали: %d", main_sum);
    printf("\nСумма побочной диагонали: %d", second_sum);

    // Проверка на деление на ноль
    if (second_sum == 0) {
        printf("\n\nНу круто чо?\n");
        return 1;
    }

    float ratio = (float)main_sum / second_sum;
    printf("\nОтношение диагоналей: %.2f\n\n", ratio);

    if (ratio > 1) {
        printf("Нечетные числа:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] % 2 != 0)
                    printf("%4d ", matrix[i][j]);
                else
                    printf("     ");
            }
            printf("\n");
        }
    } else if (ratio < 1 && ratio != 0) {
        printf("Четные числа:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] % 2 == 0)
                    printf("%4d ", matrix[i][j]);
                else
                    printf("     ");
            }
            printf("\n");
        }
    } else if (ratio == 0) {
        printf("Отношение равно НУЛЮ. Это полный пиздец.\n"
               "Вот тебе вся матрица, может найдёшь там тайный смысл:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%4d ", matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Диагонали матрицы:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j || i + j == size - 1)
                    printf("%4d ", matrix[i][j]);
                else
                    printf("     ");
            }
            printf("\n");
        }
    }

    return 0;
}
