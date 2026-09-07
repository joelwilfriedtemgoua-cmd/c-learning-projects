#include <stdio.h>
#include <string.h>

int main(void){
  char mot[100] = "bonjour ";
  char phrase[] = "le monde !";
  strcat(mot, phrase);
  printf("%s", mot);
}
