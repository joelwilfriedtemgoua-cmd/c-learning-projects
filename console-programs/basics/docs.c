#include <stdio.h> /*inclusion de la bibliotheque gerant
les entrees/sorties
*/

int main(void) //fonction principal a obligatoirement mettre
{
    int a = 100;
    float b = a-(a/2);

	printf("bonjour le monde ! :)\n");
	printf("%.2f", b);

	return 0; //retourner un entier
}
