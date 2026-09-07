#include <stdio.h>

int i, som;

int main(void)
{
    som = 0;
   for (int i = 1;i <= 1000; ++i)
   {
    som = som + i;   	
   }
    printf("%d\n", som);
   return 0;
}
