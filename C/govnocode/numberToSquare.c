#include <stdio.h>
#include <math.h>

double numberToSquare(double number) {
	return pow(number, 3);
}

int main ()
{
	double number;
	printf("Введите число для возведения его в куб: ");
	scanf("%lf", &number);
	printf("Ваше число %.2lf и оно же в кубе: %.2lf\n", number, numberToSquare(number));
	return 0;
}