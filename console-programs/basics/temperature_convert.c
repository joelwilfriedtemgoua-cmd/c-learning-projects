#include <stdio.h>
int main(void)
{
	float c, f;
    printf("veuillez entrer une temperature en degres celsus : ");
    scanf("%f", &c);
    f= (c *(9/5.0))+32;
    printf("la temperature en Fahrenheit est : %.2f", f);
	return 0;
}