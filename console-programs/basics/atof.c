#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char donnees[50];

    printf("Entrez vos nombres (nombre1 nombre2) : ");
    fgets(donnees, sizeof(donnees), stdin);
    donnees[strcspn(donnees, "\n")] = '\0';

    char *nombre1 = strtok(donnees, " ");
    char *nombre2 = strtok(NULL, " ");

    double n1 = atof(nombre1);
    double n2 = atof(nombre2);

    printf("La somme est : %.2f\n", n1 + n2);

    return 0;
}
