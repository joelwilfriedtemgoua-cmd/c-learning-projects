#include <stdio.h>

int jour;

int main(void)
{
	
   printf("entrez un jours de la semaine : ");
   scanf("%d", &jour);
   switch (jour) {
   	case 1 :
      printf("lundi\n");
   	break;
    case 2 :
      printf("mardi\n");
    break;
    case 3 :
      printf("mercredi\n");
    break;
    case 4 :
      printf("jeudi\n");
    break;
    case 5 :
      printf("vendredi\n");
    break;
    case 6 :
      printf("samedi\n");
    break;
    case 7 :
      printf("dimanche\n");
    break;
   }
   return 0;
}