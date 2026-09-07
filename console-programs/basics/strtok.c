#include <stdio.h>
#include <string.h>

int main(void)
{
    char donnees[50];

    printf("Entrez vos infos (nom;age;ville) : ");
    fgets(donnees, sizeof(donnees), stdin);
    donnees[strcspn(donnees, "\n")] = '\0';

    char *nom = strtok(donnees, ";");
    char *age = strtok(NULL, ";");
    char *ville = strtok(NULL, ";");

    printf("Nom : %s\n", nom);
    printf("Age : %s\n", age);
    printf("Ville : %s\n", ville);

    return 0;
}
