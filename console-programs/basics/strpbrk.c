#include <stdio.h>
#include <string.h>
int main(){
  char phrase[50];
  printf("entrez un mot");
  fgets(phrase, sizeof(phrase), stdin);
  phrase[strcspn(phrase, "\n")] = '\0';
  char *position = strpbrk(phrase, "bcdfghjklmnpqrstvwxyz");
  if(position != NULL){
    printf("premiere consonne a la position : %td", (position - phrase) + 1);
  }
}
