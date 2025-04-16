#include <stdio.h>

int main()
{
	const int secret_code = 1488;
	int entered_code;

	
	while (entered_code != secret_code) {
		printf("Чобi войти в рехаб, введите пiроль: ");
		scanf("%d", &entered_code);
	}
	printf("Давай не заёбывай!");
	return 0;
}