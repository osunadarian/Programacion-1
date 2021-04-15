/*ALUMNO: OSUNA DARIAN
 * DIVISION: 1*E
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "menu.h"
#include "validaciones.h"

int main()
{
    setbuf(stdout, NULL);

    int flagA;
    int flagB;
    float numA;
    float numB;
    int option;
    int exit;
    int flagOperations;
    float resultSum;
    float resultRest;
    float resultMult;
    float resultDiv;
    long int factResultA;
    long int factResultB;

    flagA=0;
    flagB=0;
    exit=0;
    flagOperations=0;

    do
	{
		title();
		menuCalculator(numA, numB, flagA, flagB);
		printf("\n\n\n                         Digite la opcion a realizar: ");
		scanf("%d", &option);

		switch(option)
		{
        case 1:
            getNumber(&numA);
            flagA=1;
            break;
        case 2:
            getNumber(&numB);
            flagB=1;
            break;
        case 3:
            flagOperations = calculate(flagA,flagB,numA,numB,&resultSum,&resultRest,&resultMult,&resultDiv,&factResultA,&factResultB);
            break;
        case 4:
            showOperations(flagOperations,numA,numB,resultSum,resultRest,resultMult,resultDiv,factResultA,factResultB);
            break;
        case 5:
            closeProgram(&exit, &flagA, &flagB);
            break;
        default:
            printf("\n\n\n          Ha ocurrido un error. Por favor, digite una opcion valida.\n\n\n");
            break;
		}

	}while(exit==0);

	return 0;
}
