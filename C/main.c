#include <stdio.h>
#include <math.h>

double power(double n, int p) {
    double pow = 1;
    for (int i = 1; i <= p; i++) {
        pow *= n;
    }
    return pow;
}

int main() {
    double x, exp, xpow;

    printf("Введите число: ");
    if (scanf("%lf", &x) != 1) {
        printf("Че, еблан? Надо было число!\n");
        return 1;
    }

    printf("Введите степень: ");
    if (scanf("%lf", &exp) != 1) {
        printf("Ты совсем охуел? Где степень, мразь?\n");
        return 1;
    }

    xpow = power(x, (int)exp);
    printf("%.2lf в степени %d = %.2lf\n", x, (int)exp, xpow);
    printf("Q - quit\n");
    printf("ПОШЁЛ НАХУЙ\n");

    return 0;
}
