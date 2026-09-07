#include <stdio.h>
int i;
int j, som;
int main()
{	
    int tab [3] [3];
	for (int i = 0; i < 3 ; i++)
	{
	 for (int j = 0; j < 3 ; j++)
	{
	 printf("entrez un nombre : ");
	 scanf("%d", &tab [i] [j]);
	}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (i == 0)
		{
			som = 0;
			for (int j = 0; j < 3; j++)
		    {
			  som = som + tab[i] [j];
		    }
		    printf("ligne 1 : somme = %d\n", som);
		}

		if (i == 1)
		{
			som = 0;
			for (int j = 0; j < 3; j++)
		    {
			  som = som + tab[i] [j];
		    }
		    printf("ligne 2 : somme = %d\n", som);
		}

		if (i == 2)
		{
			som = 0;
			for (int j = 0; j < 3; j++)
		    {
			  som = som + tab[i] [j];
		    }
		    printf("ligne 3 : somme = %d\n", som);
		}
	}
	return 0;
}