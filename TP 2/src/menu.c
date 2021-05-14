#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menuOptions()
{
    printf("****************************************");
    printf("\n       MENU SISTEMA EMPRESARIAL\n");
    printf("****************************************\n\n");
    printf("            [1] - ALTAS\n");
    printf("            [2] - MODIFICAR\n");
    printf("            [3] - BAJAS\n");
    printf("            [4] - INFORMAR\n");
    printf("            [5] - SALIR\n\n\n");
}

int exitMenu()
{
    int option = 0;
    int follow;


    printf("\n\n\n              ESTA SEGURO QUE DESEA SALIR?\n\n");
    printf("                       [1] - SI\n                       [2] - NO");
    printf("\n\n                    OPCION ELEGIDA: ");
    scanf("%d", &option);
    if(option==1)
    {
    	follow=0;
    }else
    {
    	follow=1;
    }

    return follow;
}

void menuReport(int crit)
{
	printf("\n\n\n");
    printf("****************************************");
    printf("\n            SUB-MENU INFORMES\n");
	printf("****************************************\n\n");
	if(crit==1)
	{
	printf("  CRITERIO: DESCENDENTE A ASCENDENTE\n\n\n");
	}else
	{
	printf("  CRITERIO: ASCENDENTE A DESCENDENTE\n\n\n");
	}

	printf("        [0] - CAMBIAR CRITERIO\n");
	printf("        [1] - ORDENAR POR APELLIDO Y SECTOR\n");
	printf("        [2] - INFORME DE SALARIOS\n");
	printf("        [3] - SALIR\n\n\n");
}
