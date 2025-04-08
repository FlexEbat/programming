#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_SIZE = 100;

void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 90 + 10; // числа от 10 до 99
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotateRight(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int temp[MAX_SIZE][MAX_SIZE];
    
    // Копируем в временный массив
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[j][size-1-i] = matrix[i][j];
        }
    }
    
    // Копируем обратно
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

void rotateLeft(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int temp[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[size-1-j][i] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

void flip(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int temp[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[size-1-i][size-1-j] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

void transpose(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    
    srand(time(NULL));
    
    printf("Введите размер матрицы (не больше %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size > MAX_SIZE) {
        printf("Слишком большой размер!\n");
        return 1;
    }
    
    fillMatrix(matrix, size);
    
    int choice;
    do {
        printf("Матрица:\n");
        printMatrix(matrix, size);
        
        printf("Что сделать?\n");
        printf("1 - Повернуть вправо\n");
        printf("2 - Повернуть влево\n");
        printf("3 - Перевернуть\n");
        printf("4 - Транспонировать\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                rotateRight(matrix, size);
                break;
            case 2:
                rotateLeft(matrix, size);
                break;
            case 3:
                flip(matrix, size);
                break;
            case 4:
                transpose(matrix, size);
                break;
            case 0:
                printf("Вiхiд!\n");
                break;
            default:
                printf("Неправильный выбор!\n");
        }
    } while (choice != 0);
    
    return 0;
}
