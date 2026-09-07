#include <stdio.h>

int i, n, fact;
int main(void)
{
	
   printf("entrez un nombre : ");
   scanf("%d", &n);
   fact = 1;
   for (int i = 2;i <= n; ++i)
   {
   	fact = fact * i;
   }
   printf("le factoriel est : %d\n", fact);
   return 0;
}