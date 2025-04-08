#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size;
    // Запрашиваем размер матрицы у пользователя
    printf("Введите размер матрицы: ");
    scanf("%d", &size);
    if(size > 10 || size < 1) {
        printf("Размер матрицы должен быть от 1 до 10.\n");
        return 1; // Завершаем программу с ошибкой
    }
    // Создаем двумерный массив (матрицу)
    int matrix[size][size];

    // Настраиваем генератор случайных чисел
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
        main_sum += matrix[i][i];                // Сумма главной диагонали
        second_sum += matrix[i][size - 1 - i];   // Сумма побочной диагонали
    }

    // Вычисляем отношение диагоналей
    float ratio = (float)main_sum / second_sum;
    printf("\nОтношение диагоналей: %.2f\n\n", ratio);

    // Выводим результат в зависимости от отношения
    if (ratio > 1) {
        // Выводим нечетные числа
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
    }
    else if (ratio < 1) {
        // Выводим четные числа
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
    }
    else {
        // Выводим только диагонали
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
