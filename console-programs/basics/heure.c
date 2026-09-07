#include <stdio.h>
int main(void)
{
int secondes;
printf("Secondes depuis minuit: ");
scanf("%d", &secondes);
int heures = secondes / 3600;
int reste = secondes % 3600;
int minutes = reste / 60;
int sec = reste % 60;

printf("%02d:%02d:%02d\n", heures, minutes, sec);
return 0;
}