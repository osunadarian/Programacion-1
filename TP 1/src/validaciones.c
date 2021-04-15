#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


int getNumber(float *num)
{
	int error = -1;

	if(num!=NULL)
	{
		printf("\n\n\nINGRESE OPERANDO: ");
		scanf("%f", num);
		error = 1;
	}

    return error;
}

int numberInteger(float numero)
{
    int entero;
    int error = -1;

    entero = numero;

    if(entero - numero == 0)
    {
        error = 1;
    }

    return error;
}
