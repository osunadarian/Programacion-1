#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menuOptions()
{
    printf("\n\n                          ****************************************");
    printf("\n                                   MENU SISTEMA EMPRESARIAL\n");
    printf("                          ****************************************\n\n");
    printf("             [1] - Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("             [2] - Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("             [3] - Alta de empleado\n");
    printf("             [4] - Modificar datos de empleado\n");
    printf("             [5] - Baja de empleado\n");
    printf("             [6] - Listar empleados\n");
    printf("             [7] - Ordenar empleados\n");
    printf("             [8] - Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("             [9] - Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("            [10] - SALIR\n\n\n");
}

void menuOrdenamiento()
{
    printf("\n\n\n                     SUB-MENU ORDENAMIENTO\n");
    printf("           ------------------------------------------\n\n");
    printf("             1) - Ordenar empleados por ID ascendente.\n");
    printf("             2) - Ordenar empleados por ID descendente.\n");
    printf("             3) - Ordenar empleados por nombre ascendente\n");
    printf("             4) - Ordenar empleados por nombre descendente\n");
    printf("             5) - Ordenar empleados por horas trabajadas ascendente\n");
    printf("             6) - Ordenar empleados por horas trabajadas descendente\n");
    printf("             7) - Ordenar empleados por sueldo ascendente\n");
    printf("             8) - Ordenar empleados por sueldo descendente.\n");
    printf("            10) - Salir\n\n\n");
}
