#include <stdio.h>
#include <string.h>

int main(void)
{
     char mot[50];
     printf("entrez un mot : ");
     fgets(mot, sizeof(mot), stdin);
     printf("entrez le caractere a rechercher : ");
     char c[50];
     fgets(c, sizeof(c), stdin);
     mot[strcspn(mot, "\n")] = '\0';
     c[strcspn(c, "\n")] = '\0';

    if (strncmp(mot, c, 3) == 0)
    {
        printf("Les 3 premiers caracteres sont identiques.\n");
    }
    else
    {
        printf("Les 3 premiers caracteres sont differents.\n");
    }

    return 0;
}
