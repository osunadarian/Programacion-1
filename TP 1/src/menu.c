#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

void title()
{
    printf("\n");
    printf("                        |-----------------------------|\n");
    printf("                        |    C A L C U L A D O R A    |\n");
    printf("                        |-----------------------------|\n\n");
}

void menuCalculator(float numA, float numB, int flagA, int flagB)
{
	if( flagA==0 && flagB == 0 )
	{

		printf("[1] Ingrese primer operando (A = X)");
		printf("            [2] Ingrese segundo operando (B = Y)\n\n");
		printf("                    [3] Calcular todas las operaciones\n\n");
		printf("                          a- Calcular la suma (A + B)\n");
		printf("                          b- Calcular la resta (A - B)\n");
		printf("                          c- Calcular la division (A / B)\n");
		printf("                          d- Calcular la multiplicacion (A * B)\n");
		printf("                          e- Calcular el factorial (A!)\n");
		printf("                          f- Calcular el factorial (B!)\n\n");
		printf("[4] Informar resultados                        [5] Salir");

	}else if( flagA == 1 && flagB == 0)
	{

		printf("[1] Ingrese primer operando (A = %.2f)", numA);
		printf("            [2] Ingrese segundo operando (B = Y)\n\n");
		printf("                    [3] Calcular todas las operaciones\n\n");
		printf("                          a- Calcular la suma (%.2f + B)\n", numA);
		printf("                          b- Calcular la resta (%.2f - B)\n", numA);
		printf("                          c- Calcular la division (%.2f / B)\n", numA);
		printf("                          d- Calcular la multiplicacion (%.2f * B)\n", numA);
		printf("                          e- Calcular el factorial (%.2f!)\n", numA);
		printf("                          f- Calcular el factorial (B!)\n\n");
		printf("[4] Informar resultados                           [5] Salir");

	}else if( flagA == 0 && flagB == 1)
	{

		printf("[1] Ingrese primer operando (A = X)");
		printf("            [2] Ingrese segundo operando (B = %.2f)\n\n", numB);
		printf("                    [3] Calcular todas las operaciones\n\n");
		printf("                          a- Calcular la suma (A + %.2f)\n", numB);
		printf("                          b- Calcular la resta (A - %.2f)\n", numB);
		printf("                          c- Calcular la division (A / %.2f)\n", numB);
		printf("                          d- Calcular la multiplicacion (A * %.2f)\n", numB);
		printf("                          e- Calcular el factorial (A!)\n");
		printf("                          f- Calcular el factorial (%.2f!)\n\n", numB);
		printf("[4] Informar resultados                           [5] Salir");

	}else if( flagA == 1 && flagB == 1 )
	{

        printf("[1] Ingrese primer operando (A = %.2f)", numA);
        printf("            [2] Ingrese segundo operando (B = %.2f)\n\n", numB);
        printf("                    [3] Calcular todas las operaciones\n\n");
        printf("                          a- Calcular la suma (%.2f + %.2f)\n", numA, numB);
        printf("                          b- Calcular la resta (%.2f - %.2f)\n", numA, numB);
        printf("                          c- Calcular la division (%.2f / %.2f)\n", numA, numB);
        printf("                          d- Calcular la multiplicacion (%.2f * %.2f)\n", numA, numB);
        printf("                          e- Calcular el factorial (%.2f!)\n", numA);
        printf("                          f- Calcular el factorial (%.2f!)\n\n", numB);
        printf("[4] Informar resultados                           [5] Salir");

	}
}


int calculate(int flagA, int flagB, float numA, float numB, float *resultSum, float *resultRest, float *resultMult, float *resultDiv, long int *factResultA, long int *factResultB)
{
    int error = -1;

    if(flagA==1 && flagB==1)
    {
        sum(numA,numB,resultSum);
        rest(numA,numB,resultRest);
        multiplication(numA,numB,resultMult);
        division(numA,numB,resultDiv);
        factorial(numA,factResultA);
        factorial(numB,factResultB);
        error = 1;
        printf("\n\n\n                      - - - CALCULOS REALIZADOS CON EXITO - - - \n\n\n");
    }else
    {
        printf("\n\n\n              - - - ATENCION! LOS CALCULOS NO HAN SIDO REALIZADOS - - - ");
        printf("\n              - - - VERIFIQUE HABER INGRESADO AMBOS OPERANDOS - - - \n\n\n");
    }

    return error;
}

int showOperations(int flagOperations, float numA, float numB, float resultSum, float resultRest, float resultMult, float resultDiv, long int factResultA, long int factResultB)
{

    if(flagOperations==1)
    {
        if(sum(numA,numB,&resultSum)!=-1)
        {
            printf("\n\n\n               ------> La suma entre %.2f y %.2f es %.2f\n", numA, numB, resultSum);
        }else
        {
            printf("               ------> No hay nada que sumar ya que ambos numeros son 0\n");
        }

        if(rest(numA,numB,&resultRest)!=-1)
        {
            printf("               ------> La resta entre %.2f y %.2f es %.2f\n", numA, numB, resultRest);
        }else
        {
            printf("               ------> No hay nada que restar ya que ambos numeros son 0\n");
        }

        if(multiplication(numA,numB,&resultMult)!=-1)
        {
            printf("               ------> La multiplicacion entre %.2f y %.2f es %.2f\n", numA, numB, resultMult);
        }else
        {
            printf("              ------> Todo numero multiplicado por 0 da 0\n");
        }

        if(division(numA,numB,&resultDiv)!=-1)
        {
            printf("               ------> La division entre %.2f y %.2f es %.2f\n", numA, numB, resultDiv);
        }else
        {
            printf("               ------> No se puede dividir si alguno de los dos operandos es 0\n");
        }

        if(factorial(numA,&factResultA)!=-1)
        {
            printf("               ------> El factorial de %.2f es %li\n", numA, factResultA);
        }else
        {
            printf("               ------> No es posible realizar el factorial de %.2f\n", numA);
        }


        if(factorial(numB,&factResultB)!=-1)
        {
            printf("               ------> El factorial de %.2f es %li\n\n\n\n", numB, factResultB);
        }else
        {
            printf("               ------> No es posible realizar el factorial de %.2f\n\n\n\n", numB);
        }

    }else
    {
        printf("\n\n\n      PARA MOSTRAR LOS CALCULOS, PRIMERO DEBE REALIZAR LAS CUENTAS [OPCION 3 DEL MENU]\n\n\n");
    }

    return 0;
}

int closeProgram(int *close, int *flagA, int *flagB)
{
    int error = -1;
    int option;

    printf("\n\n\n                        Esta segurx que desea salir?\n");
    printf("\n                                 [1] - SI");
    printf("\n                                 [2] - NO");
    printf("\n\n                              OPCION ELEGIDA: ");
    scanf("%d", &option);
    if(option==1)
    {
        *close = 1;
    }else
    {
        *flagA = 0;
        *flagB = 0;
    }

    return error;
}

