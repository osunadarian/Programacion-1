#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "validaciones.h"

int sum(float numA, float numB, float *sumResult)
{
    int error = -1;

    if( sumResult != NULL)
    {
        *sumResult = numA + numB;
        error = 1;
    }

    return error;
}
int rest(float numA, float numB, float *restResult)
{
    int error = -1;

    if( restResult != NULL)
    {
        *restResult = numA - numB;
        error = 1;
    }

    return error;

}
int multiplication(float numA, float numB, float *multResult)
{
    int error = -1;

    if(multResult != NULL)
    {
        *multResult = numA * numB;
        error = 1;
    }

    return error;

}
int division(float numA, float numB, float *divResult)
{
    int error = -1;

    if(divResult != NULL)
    {
    	if(numA!=0 && numB!=0)
    	{
    		*divResult = numA / numB;
    		error = 1;
    	}
    }

    return error;
}


int factorial(float num, long int *factResult)
{
    int error = -1;
    long int factorial;
    int entero;

    entero = numberInteger(num);

    if(num>0 && entero==1 && factResult!=NULL && num<=12)
    {
        factorial = 1;

        for(int i=1; i<=num; i++)
        {
            factorial = factorial * i;
        }
        error = 1;

        *factResult = factorial;
    }

    return error;
}
