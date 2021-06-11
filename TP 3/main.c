#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

int main()
{
	setbuf(stdout, NULL);

    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    	do
		{
			menuOptions();
			printf("           				DIGITE OPCION: ");
			fflush(stdin);
			scanf("%d", &option);
		}while(isdigit(option)!=0);

        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv",listaEmpleados)==0)
            	{
            		printf("\n\n\n 		----> El archivo de tipo texto se ha cargado correctamente! <----\n\n\n");
            	}else
            	{
            		printf("\n\n\n 		----> Atencion - ERROR EN CARGA DE ARCHIVO - Atencion! <----\n");
            	}
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
				{
					printf("\n\n\n ----> El archivo de tipo binario se ha cargado correctamente! <----\n\n\n");
				}else
				{
					printf("\n\n\n ----> Atencion - ERROR EN CARGA DE ARCHIVO - Atencion! <----\n");
				}
				break;
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	if(controller_saveAsText("pruebaDatos.csv", listaEmpleados)==0)
            	{
            		printf("\n\n\n 		----> El archivo de tipo texto se ha guardado correctamente! <----\n\n\n");
            	}else
            	{
            		printf("\n\n\n 		----> Atencion - EL ARCHIVO NO SE HA GUARDADO - Atencion! <----\n");
            	}

            	break;
            case 9:
            	if(controller_saveAsBinary("pruebaDatos.bin", listaEmpleados)==0)
            	{
            		printf("\n\n\n ----> El archivo de tipo binario se ha guardado correctamente! <----\n\n\n");
            	}else
            	{
            		printf("\n\n\n ----> Atencion - EL ARCHIVO NO SE HA GUARDADO - Atencion! <----\n");
            	}
            	break;
            default:
            	printf("\n\n\n ----> OPCION NO VALIDA! <----\n\n\n");
            	break;

        }
    }while(option != 10);
    return 0;
}

