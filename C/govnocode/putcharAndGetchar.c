#include <stdio.h>

#define SPACE ' '

int main()
 {
   char ch = getchar();

   while(ch != '\n')
   {
    if(ch == SPACE){
        putchar(ch);
    } else 
        putchar(ch + 1);
    ch = getchar();

    }
    return 0;

}

