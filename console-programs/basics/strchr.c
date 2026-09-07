#include <stdio.h>
#include <string.h>
int main(void){
 char mot[50];
 printf("entrez un mot : ");
 fgets(mot, sizeof(mot), stdin);
 mot[strcspn(mot, "\n")] = '\0';
 printf("entrez le caractere a rechercher : ");
 char c[50];
 fgets(c, sizeof(c), stdin);
 c[strcspn(c, "\n")] = '\0';
 char * position = strstr(mot, c);
  if (position != NULL)
    {
        printf("Le caractere existe !\n");
        printf("Position : %td\n", (position - mot) + 1);
    }
    else
    {
    printf("Le caractere n'existe pas !\n");
}
}
