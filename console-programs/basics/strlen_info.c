#include <stdio.h>
#include <string.h>
int main(void){
size_t i;
char mot[] = "informatique";
size_t l = strlen(mot);
printf("mot : %s\n",mot);
printf("longueur : %zu\n",strlen(mot));
printf ("le dernier caractere est : %c\n",mot[11]);
for(i = 0; i < l; i++){
 printf("caractere %zu %c\n",i+1 , mot[i]);
}
return 0;
}
