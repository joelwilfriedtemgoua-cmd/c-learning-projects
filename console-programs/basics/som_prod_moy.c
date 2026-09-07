#include <stdio.h>

	int a;
	int b;
	int s;
	int p;
	float m;
int main(void)
{
	printf("entrez un nombre");
	scanf("%d", &a);
	printf("\nentrez un autre nombre");
	scanf("%d", &b);
	p = a * b;
    s =a + b;
    m = s / 2.0;
    printf("la somme est : %d \n", s);
    printf("le produit est : %d \n", p);
    printf("la moyenne est : %.2f \n", m);
	return 0;
}