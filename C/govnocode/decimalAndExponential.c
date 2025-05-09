#include <stdio.h>

int main()
{
    unsigned short choice; 
    double number;
    
    printf("The program displays the usual number in decimal or exponential form.\n");
    printf("1.Decimal form \ n2. Exponential form\n");
    printf("Your choice: ");
    
    scanf("%hu", &choice);
    if (choice == 1) {
        printf("Enter the number: ");
        scanf("%lf", &number);
        printf("%lf", number);
    } else if (choice == 2) {
        printf("Enter the number: ");
        scanf("%lf", &number);
        printf("%e", number);
    }
    return 0;
}
