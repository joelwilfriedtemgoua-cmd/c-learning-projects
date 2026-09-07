#include <stdio.h>

float number1;
float number2;
float result;
char signe;

float addition(float a, float b){
 return a + b;
}

float soustraction(float a, float b){
 return a - b;
}

float multiplication(float a, float b){
 return a * b;
}

float division(float a, float b){
	if (b == 0)
	{
		printf("ERROR\n");
	} else {
       return a / b;
	}
}

int main(void) {
	
        printf ("entrer un nombre : ");

        scanf ("%f", &number1);

        printf ("entrer un second nombre : ");

        scanf ("%f", &number2);

        printf ("entrer un signe : +, -, *, / ou q pour quitter : ");

        scanf ("%c", &signe);

    	if (signe == '+'){
    		result = addition(number1, number2);
    	}

    	 else 	if (signe == '-')
    	 {
    		result = soustraction(number1, number2);
    	}

    	else	if (signe == '*')
    	{
    		result = division(number1, number2);
    	}

    	else	if (signe == '/')
    	{
    		result = division(number1, number2);

    	}

       printf("%f", result);

    }

