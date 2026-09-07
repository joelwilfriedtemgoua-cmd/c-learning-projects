#include <stdio.h>
#include "operations.h"
 int main(){
 int choix;
 double a, b, resultat;

  printf ("1 addition 2 soustraction 3 multiplication 4 division \n");

 while(1){
   printf("ton choix : ");
   scanf("%d", &choix);
   if (choix == 5){
     printf("fin du programme !\n");
     break;
   }

   printf("entrez un nombre : ");
   scanf("%lf", &a);
   printf("entrez un nombre : ");
   scanf("%lf", &b);

   switch(choix){
    case 1 : resultat = addition(a, b);
      printf("%.2lf\n", resultat);
    break;

    case 2 : resultat = soustraction(a, b);
      printf("%.2lf\n", resultat);
    break;

    case 3 : resultat = multiplication(a, b);
      printf("%.2lf\n", resultat);
    break;

      switch(choix)
    case 4 : resultat = division(a, b);
      printf("%.2lf\n", resultat);
    break;
   }

 }
 return 0;
}
