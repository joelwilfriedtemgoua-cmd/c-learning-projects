#include <stdio.h>

float a, b, r;
char operateur;
int main(void)
{
	
    printf("entrez un nombre : ");
    scanf("%f", &a);
    printf("entrez un second nombre : ");
   scanf("%f", &b);
   printf("entrez un operateur (+, -, *, /) : ");
   scanf(" %c", &operateur);
   switch(operateur){
   	case '+' :
      r = a + b;
       printf("%.1f + %.1f = %.1f\n" ,a, b, r);
   	break;
    case '-' :
      r = a - b;
       printf("%.1f - %.1f = %.1f\n" ,a, b, r);
    break;
    case '*' :
      r = a * b;
       printf("%.1f * %.1f = %.1f\n" ,a, b, r);
    break;
    case '/' :
      if (b == 0)
      {
        printf("Error\n");
      } else{
         r = a / b;
         printf("%.1f / %.1f = %.1f\n" ,a, b, r);
      }
    break;
    default:
    printf("Operateur inconnu.\n");
   }
   return 0;
}