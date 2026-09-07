#include <stdio.h>
#include <string.h>
int main(void){
char source[] = "ordinateur";
char destination[11];
strcpy(destination, source);
printf("source : %s\n", source);
printf("destination : %s\n", destination);
printf("taille destination %zu\n", strlen(destination));
return 0;
}
