#include <stdio.h>
#include <string.h>

int main(void){
  char mot1[50];
  char mot2[50];
  printf("entrez un mot : ");
  scanf("%s", mot1);
  printf("entrez un mot : ");
  scanf("%s", mot2);
  if (strcmp(mot1, mot2) == 0){
    printf("les mots sont identiques\n");
  } else {
    printf("les mots sont differents\n");
  }
}
