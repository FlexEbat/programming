[[C]]
![[Pasted image 20250428212432.png]]
```
#include <stdio.h>

#define SIZE 5
  
int main()
{
    for(int i = 1; i <= SIZE; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("$");
        }
        printf("\n");
    }
    return 0;
}
```
![[Pasted image 20250428212458.png]]
![[Pasted image 20250428212845.png]]
```
#include <stdio.h>
  
int main() {
    int lower, upper;
    printf("ВВедите нижнюю границу диапазона(>=1): ");
    scanf("%d", &lower);
    if(lower <= 0)
    {
      printf("Нижняя граница диапазона должна быть больше 0\n");
        return 1;
    }
    printf("ВВедите верхнюю границу диапазона: ");
    scanf("%d", &upper);
  
    printf("Число\tКвадрат\tКуб\n");
    for(int i = lower; i <= upper; i++)
    {
        printf("%d\t%d\t%d\n", i, i*i, i*i*i);
    }
    return 0;
  
}
```
![[Pasted image 20250428213929.png]]











