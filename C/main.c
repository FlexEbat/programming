/**
 * @file main.c
 * @brief A simple program that gets user input for name and displays it
 *
 * This program demonstrates basic input/output operations in C:
 * - Takes user's name as input using fgets
 * - Prints the entered name along with a predefined message
 * 
 * @def PIDOR Defines a constant string message
 * @def NAME Defines the maximum length for name input (40 characters)
 *
 * @note The program currently only implements name input functionality
 * @note Unused variables: weight, weight2, age, letters
 *
 * @return Returns 0 upon successful execution
 */
#include <stdio.h>
#include <string.h>
// #include <stdint.h>
// #include <inttypes.h>

#define PIDOR "Аллах пидар, кстати"
#define NAME 40

int main()
{
    double weight, weight2;
    int age, letters;
    char name[NAME];
    printf("Enter your name: ");
    fgets(name, NAME, stdin);
    // scanf("%11s", name);
    printf("Ваше имя: %s. %s", name, PIDOR);
    return 0;
}
