#include <stdio.h>
int tab [10];
int i, som, moy;
int main(void)
{
	som = 0;
	for (int i = 0; i < 10; ++i)
	{
		printf("entrez une valeur : ");
		scanf("%d", &tab[i]);
		som = som + tab[i];
	}
	moy = som / 10;
	printf("la moyenne est : %d\n", moy);
	return 0;
}