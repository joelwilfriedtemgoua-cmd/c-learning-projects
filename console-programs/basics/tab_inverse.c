#include <stdio.h>
int tab [10];
int i;
int main(void)
{
	
	for (int i = 0; i < 10; ++i)
	{
		printf("entrez une valeur : ");
		scanf("%d", &tab[i]);
	}
	printf("les valeurs inverses sont : \n");
	for (int i = 9; i >= 0; i= i-1)
	{
		printf("%d\n", tab[i]);
	}
	return 0;
}