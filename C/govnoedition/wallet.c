#include <stdio.h>

int main()
{   
    int sum = 0,size;
    printf("Введите кол-во элементов в кошельке: ");
    if(scanf("%d", &size) !=1){
        printf("Че пиздим то тут А?");
        return 1;
    }
    int wallet[size];
    printf("Окей, в твоей кошелке: %d элементов\n", size);
    printf("Теперь заполним ваш кошелек деньгами: \n");
    for(int i = 0; i < size; i++){
        printf("Элемент %d: ", i+1);
        scanf("%d", &wallet[i]);
        sum+=wallet[i];
    }
    printf("ОГО!\n");
    for(int i = 0; i < size; i++){
        printf("%d ", wallet[i]);
    }
    printf("\nА это.... %d долларов", sum);
    return 0;
}