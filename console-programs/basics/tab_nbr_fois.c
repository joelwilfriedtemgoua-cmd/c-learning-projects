#include <stdio.h>
int i, c, m;
int nb;
int main(void)
{
	printf("entrez le nombre de valeur du tableau : ");
	scanf("%d", &m);
	int f [m];
	for (int i = 0; i < m; ++i)
	{
		printf("entrez une valeur : ");
		scanf("%d", &f[i]);
	}
	printf("entrez le nombre rechercher : ");
	scanf("%d", &nb);
	c = 0;
	for (int i = 0; i < m; i++)
	{
        if (nb == f[i])
        		{
        			c = c + 1;
        		}		
	}
	printf("le nombre %d est present %d fois\n", nb, c);
	return 0;
}