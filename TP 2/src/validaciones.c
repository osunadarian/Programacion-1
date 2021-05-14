#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int validarCadena(char cadena[])
{
    int error = 0;

    for(int i=0; i<strlen(cadena); i++)
    {
        if(!((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122)))
        {
            error = 1;
        }
    }
    if(error)
    {
        printf("\n                 ERROR! INGRESE SOLO LETRAS.\n");
    }

    return error;
}

void formatearString(char cadena[])
{
	int i = 0;

	while(cadena[i])
	{
		cadena[i] = tolower(cadena[i]);
		i++;
	}

	cadena[0] = toupper(cadena[0]);
}
