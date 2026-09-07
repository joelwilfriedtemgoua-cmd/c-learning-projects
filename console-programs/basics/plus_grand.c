#include <stdio.h>

int main(void)
{
   float a;
   float b;
   float c;
   float x;
   printf("entrez un nombre : ");
   scanf("%f", &a);
   x = a;
   printf("entrez un second nombre : ");
   scanf("%f", &b);
   if (x < b){
     x = b;
   }
   printf("entrez un troisieme nombre : ");
   scanf("%f", &c);
    if (x < c){
     x = c;
   }
   printf("le prlus grand nombre est : %.1f \n", x);
	return 0;

}