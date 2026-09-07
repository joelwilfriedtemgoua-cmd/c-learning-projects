#include <stdio.h>
int main(void)
{
	float p;
	float t;
	float imc;
	printf("entrez votre poids en kg : ");
	scanf("%f", &p);
    printf("entrez votre taille en m : ");
	scanf("%f", &t);
    imc = p / (t * t);
    printf("votre imc est : %.2f\n", imc);
	return 0;
}