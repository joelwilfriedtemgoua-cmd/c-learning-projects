#include <stdio.h>
int main(void)
{
	int n;
	int x;
	printf("entrez un nombre : ");
	scanf("%d", &n);
	x = n % 2;
	if (x == 0)
	{
		printf("ce nombre est paire\n");
	} else {
		printf("ce nombre est impaire\n");
	}
	return 0;
}