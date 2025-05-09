#include <stdio.h>

#define WEEK 7

int main ()
{
	unsigned short day, lastDays; 
	printf("Введи кол-во дней: ");
	scanf("%hu", &day);
	if (day == 0) {
		printf("Дней должно быть больше 0\n");
		return 1;
	} else{
	lastDays = day % WEEK;
	if (lastDays < 1) {
		printf("Ваши дня в неделях: %hu", day/WEEK);
		
	} else{
		printf("Ваши дня в неделях: %hu и %hu дней", day/WEEK, lastDays);
	}
}
	return 0;
}