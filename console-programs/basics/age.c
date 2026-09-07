#include <stdio.h>

int a;
int main(void)
{
	
   printf("entrez votre age : ");
   scanf("%d", &a);
   if (a < 6)
   {
     printf("vous etes un bebe\n");
   } else if (a < 12)
   {
     printf("vous etes un enfant\n");
   } else if (a < 18)
   {
     printf("vous etes un ado\n");
   } else {
    printf("vous etes un adulte\n");
   }
   return 0;
}