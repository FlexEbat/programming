
#include <stdio.h>

int main() {
    int p, q;
    
    scanf("%d", &p);
    while (p > 0) {
        printf("%d\n", p);
        scanf("%d", &q);
        
        while (q > 0) {
            printf("%d\n", p * q);
            if (q > 100)
                break;  // выход из внутреннего цикла
            scanf("%d", &q);
        }
        
        if (q > 100)
            break;  // выход из внешнего цикла
        scanf("%d", &p);
    }
    
    return 0;
}