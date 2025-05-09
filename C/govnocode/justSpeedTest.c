#include <stdio.h>


int main()
{
   double fileWeight, internetSpeed, time;
   printf("Введите вес вашего файла(в мегабайтах): ");
   scanf("%lf", &fileWeight);
   printf("Введите скорость вашего интернета(в мегабитах): ");
   scanf("%lf", &internetSpeed);
   time = (fileWeight * 8) / internetSpeed;
    printf("При скорости загрузки в %.2lf мб/сек файл размером %.2lf мегабайт загружается за %lf секунд\n", internetSpeed, fileWeight, time);
    return 0;
}
