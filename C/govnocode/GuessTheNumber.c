// Игра угадай число   
// Игра "Угадай число" - это простая игра, в которой игрок должен угадать случайное число, загаданное компьютером.
// Игра начинается с того, что компьютер генерирует случайное число в заданном диапазоне (например, от 1 до 100).
// Затем игрок вводит свои предположения, и компьютер сообщает ему, больше или меньше загаданное число по сравнению с его предположением.
// Игра продолжается до тех пор, пока игрок не угадает число или не исчерпает все попытки.
// В конце игры компьютер сообщает игроку, угадал ли он число и сколько попыток ему понадобилось.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    int choice;
    int random_number = rand() % (100 - 1 + 1) + 1;;
    do {
    printf("Will introduce a number from 1 to 100: ");
    
    scanf("%d", &choice);
    
    if (choice < 1 || choice > 100) {
    printf("An incorrect number has been introduced. It takes from 1 to 100\n");
    return 1;
    }
    if (choice == random_number){
        printf("Ты пидарас как ты угадал: %d\n", random_number);
    }
    else if (choice < random_number) {
        printf("Слишком мало, пидарас\n");
    } else {
        printf("Ты че долбаёб, много\n");
    }
} while(choice != random_number);
printf("A mystery = %d\n", random_number);
    return 0;
}
