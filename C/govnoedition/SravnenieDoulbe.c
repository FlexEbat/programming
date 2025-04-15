#include <stdio.h>
#include <math.h>
int main ()
{
	const double ANSWER = 3.14159;
	double response;
	printf("Каково значение числа pi?: ");
	scanf("%lf", &response);
	while (fabs(response - ANSWER) > 0.0001)
{
	printf("Bвeдитe значение еще раз: ");
	scanf("%lf", &response);
}
	printf("Достаточно близко!\n");
	return 0;
}