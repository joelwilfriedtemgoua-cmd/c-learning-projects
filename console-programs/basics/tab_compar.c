#include <stdio.h>
int tab [10];
int i, m, p;
int main(void)
{
	
	for (int i = 0; i < 10; ++i)
	{
		printf("entrez une valeur : ");
		scanf("%d", &tab[i]);
	}
	m = tab[1];
	for (int i = 0; i < 10; i++)
	{
		if (m < tab[i])
		{
			m = tab[i];
		}
		if (p > tab[i])
		{
			p = tab[i];
		}
	}
	printf("la plus grande valeur est : %d et la plus petite valeur est : %d\n", m, p);
	return 0;
}