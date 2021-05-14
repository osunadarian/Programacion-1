#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include "menu.h"

int initEmployees(eEmployee lista[], int tam)
{
    int error = -1;
    if (lista!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int sortEmployees(eEmployee lista[], int tam, int crit)
{
    int error = 1;
    eEmployee auxEmployee;

    if(lista!=NULL && tam > 0) //VALIDO ARRAY Y TAMAÑO DEL MISMO
    {
        for(int i = 0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
            	if(crit==1)
            	{
                    if(strcmp(lista[i].lastName, lista[j].lastName)>0)
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                    }
                    else if((strcmp(lista[i].lastName,lista[j].lastName)==0) && (lista[i].sector > lista[j].sector))
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                    }
            	}else if(crit==0)
            	{
                    if(strcmp(lista[i].lastName, lista[j].lastName)<0)
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                    }
                    else if((strcmp(lista[i].lastName,lista[j].lastName)==0) && (lista[i].sector < lista[j].sector))
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                    }
            	}

            }
        }
        error = 0;
    }

    return error;
}

int freePlace(eEmployee lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice; //retorna un slot vacio para que sea ocupado por un nuevo empleado
}

int checkEmployees(eEmployee lista[], int tam)
{
    int counter = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            counter = 1;
            break;
        }
    }

    return counter; //retorna un valor para saber si se puede o no se puede ingresar a los menues de baja y modificacion
}

void printOneEmployee(eEmployee oneEmployee)
{
    printf("%10d%13s%15s         $ %.f%9d\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}

int printEmployees(eEmployee lista[], int tam)
{

    int error = 1;

    if(lista != NULL && tam > 0)
    {
        printf("**********************************************************************");
        printf("\n       ID        NOMBRE        APELLIDO        SALARIO      SECTOR\n");
        printf("**********************************************************************\n\n");

        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                printOneEmployee(lista[i]);
            }
        }
        printf("\n\n");
        error = 0;
    }

    return error;
}

int addEmployees(eEmployee lista[], int tam, int* id)
{
    int error = 1;
    int indice;
    int validacion = 1;

    eEmployee newEmployee; //creamos variable de tipo Empleado

    if(lista!=NULL && tam > 0 && id > 0)
    {
        indice = freePlace(lista, tam); // verificamos que exista lugar disponible mediante la funcion Freeplace

        if(indice == -1)
        {
            printf("\n\n            EL ALTA NO PUEDE REALIZARSE. EL SISTEMA ESTA COMPLETO.\n\n\n");
            system("pause");
        }
        else
        {

            newEmployee.id = *id; //Aumento el id
            newEmployee.isEmpty = 0; //Modifico campo isEmpty para que el programa sepa que existen datos
            do//    NOMBRE VALIDADO
            {
                printf("\n                    INGRESE NOMBRE: ");
                fflush(stdin);
                gets(newEmployee.name);
                validacion = validarCadena(newEmployee.name);
                fflush(stdin);
                formatearString(newEmployee.name);
            }while(validacion == 1);

            do
            {//     APELLIDO VALIDADO
                printf("\n                    INGRESE APELLIDO: ");
                fflush(stdin);
                gets(newEmployee.lastName);
                validacion = validarCadena(newEmployee.lastName);
                fflush(stdin);
                formatearString(newEmployee.lastName);

            }while(validacion == 1);

            printf("\n                    INGRESE SALARIO: ");//VALIDADO
            fflush(stdin);
            scanf("%f", &newEmployee.salary);
            while(newEmployee.salary < 23544)
            {
                printf("\n\n                         HA OCURRIDO UN ERROR");
                printf("\n  EL SALARIO INGRESADO NO PUEDE SER MENOR AL SALARIO MINIMO VITAL Y MOVIL [$23.544]");
                printf("\n\n                          NOMBRE: %s", newEmployee.name);
                printf("\n                          APELLIDO: %s", newEmployee.lastName);
                printf("\n\n                  POR FAVOR, REINGRESE EL SALARIO: ");
                fflush(stdin);
                scanf("%f", &newEmployee.salary);
                printf("\n");
            }

            printf("\n                    INGRESE SECTOR [1 AL 10]: ");
            fflush(stdin);
            scanf("%d", &newEmployee.sector);
            while(newEmployee.sector<1 || newEmployee.sector>10)
            {
                printf("\n\n                         HA OCURRIDO UN ERROR");
                printf("\n      EL SECTOR INGRESADO NO ES CORRECTO. DIGITE UN SECTOR DEL 1 AL 10");
                printf("\n\n                          NOMBRE: %s", newEmployee.name);
                printf("\n                          APELLIDO: %s", newEmployee.lastName);
                printf("\n                          SALARIO: %.0f", newEmployee.salary);
                printf("\n\n                          REINGRESE SECTOR: ");
                fflush(stdin);
                scanf("%d", &newEmployee.sector);
            }

            lista[indice] = newEmployee;

            printf("\n\n                    ALTA REALIZADA CON EXITO\n\n\n\n");
            system("pause");
            error = 0;
            *id = *id + 1;
        }
    }

    return error;
}

int modifyById(eEmployee lista[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int option;
    int validacion = 1;

    if(lista != NULL && tam > 0)
    {
        printEmployees(lista, tam);
        printf("                   INGRESE ID DE EMPLEADO A MODIFICAR: ");
        scanf("%d", &id);

        indice = findEmployeeById(lista, tam, id);

        if( indice == -1)
        {
            printf("\n\n            ERROR. ID INGRESADO NO VALIDO.\n\n\n\n");
            system("pause");
        }
        else
        {
            printf("\n\n\n         ID        NOMBRE        APELLIDO        SALARIO      SECTOR\n");

            printOneEmployee(lista[indice]);
            printf("\n\n\n                  QUE AREA DESEA MODIFICAR?  \n\n");
            printf("                        [1]  NOMBRE\n");
            printf("                        [2]  APELLIDO\n");
            printf("                        [3]  SALARIO\n");
            printf("                        [4]  SECTOR\n");
            printf("\n                       DIGITE OPCION: ");
            fflush(stdin);
            scanf("%d", &option);

            switch(option)
            {
                case 1:
                    do//    NOMBRE VALIDADO
                    {
                    printf("\n\n                    INGRESE NOMBRE NUEVO: ");
                    fflush(stdin);
                    gets(lista[indice].name);
                    validacion = validarCadena(lista[indice].name);
                    fflush(stdin);
                    formatearString(lista[indice].name);

                    printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                    system("pause");
                    }while(validacion == 1);

                    break;
                case 2:
                    do
                    {//     APELLIDO VALIDADO
                        printf("\n\n                    INGRESE APELLIDO NUEVO: ");
                        fflush(stdin);
                        gets(lista[indice].lastName);
                        validacion = validarCadena(lista[indice].lastName);
                        fflush(stdin);
                        formatearString(lista[indice].lastName);

                        printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                        system("pause");

                    }while(validacion == 1);

                    break;
                case 3:
                    printf("\n\n                   INGRESE SALARIO NUEVO: ");//VALIDADO
                    fflush(stdin);
                    scanf("%f", &lista[indice].salary);
                    while(lista[indice].salary < 23544)
                    {
                        printf("\n\n                         HA OCURRIDO UN ERROR");
                        printf("\n  EL SALARIO INGRESADO NO PUEDE SER MENOR AL SALARIO MINIMO VITAL Y MOVIL [$23.544]");
                        printf("\n\n                          NOMBRE: %s", lista[indice].name);
                        printf("\n                          APELLIDO: %s", lista[indice].lastName);
                        printf("\n\n                  POR FAVOR, REINGRESE EL SALARIO: ");
                        fflush(stdin);
                        scanf("%f", &lista[indice].salary);
                    }
                    printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                    system("pause");

                    break;
                case 4:
                    printf("\n\n                    INGRESE SECTOR NUEVO [0 AL 10]: ");
                    fflush(stdin);
                    scanf("%d", &lista[indice].sector);
                    while(lista[indice].sector<1 || lista[indice].sector>10)
                    {
                        printf("\n\n                         HA OCURRIDO UN ERROR");
                        printf("\n      EL SECTOR INGRESADO NO ES CORRECTO. DIGITE UN SECTOR DEL 1 AL 10");
                        printf("\n\n                          NOMBRE: %s", lista[indice].name);
                        printf("\n                          APELLIDO: %s", lista[indice].lastName);
                        printf("\n                          SALARIO: %.0f", lista[indice].salary);
                        printf("\n\n                          REINGRESE SECTOR: ");
                        fflush(stdin);
                        scanf("%d", &lista[indice].sector);
                    }
                    printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                    system("pause");
                    break;
                default:
                    printf("\n\n\n                            %d NO ES UNA OPCION VALIDA.", option);
            }
        }
    }
    return error;
}

int findEmployeeById(eEmployee lista[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(eEmployee lista[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;

    if(lista != NULL && tam > 0)
    {

        printEmployees(lista, tam);
        printf("        POR FAVOR, INGRESE EL ID DEL EMPLEADO A REMOVER: ");
        scanf("%d", &id);

        indice = findEmployeeById(lista, tam, id);

        if(indice == -1)
        {
            printf("\n\n               ----> EL ID INGRESADO ES INVALIDO <----\n\n\n\n");
            system("pause");
        }
        else
        {
            printf("\n\n              EL SIGUIENTE EMPLEADO SERA BORRADO DEL SISTEMA\n\n");
            printf("************************************************************************\n\n");
            printf("       ID        NOMBRE        APELLIDO        SALARIO      SECTOR\n");
            printOneEmployee(lista[indice]);
            printf("\n************************************************************************\n");
            printf("\n\n                         DESEA CONFIRMAR BAJA?");
            printf("\n\n                         [1] - SI  [2] - NO");
            printf("\n\n                          DIGITE RESPUESTA: ");
            fflush(stdin);
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                lista[indice].isEmpty = 1;
                system("cls");
                printf("\n\n                   BAJA DEL EMPLEADO COMPLETA\n\n\n");
                error = 0;
                system("pause");
            }else
            {
                system("cls");
                printf("\n\n          BAJA DEL EMPLEADO CANCELADA POR EL USUARIO\n\n\n");
                error = 2;
                system("pause");
            }
        }
    }

    return error;
}

int averagesSalary(eEmployee lista[], int tam)
{
    int acumuladorSalarios = 0;
    int contadorPersonas = 0;
    int contPersonasSalarioPromedio = 0;
    float promedio;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            contadorPersonas++;
            acumuladorSalarios = acumuladorSalarios + lista[i].salary;
        }
    }

    promedio = acumuladorSalarios / contadorPersonas;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            if(lista[i].salary > promedio)
            {
                contPersonasSalarioPromedio++;
            }
        }
    }

    printf("**********************************************************************");
    printf("\n                       INFORMES SALARIOS                              \n");
    printf("**********************************************************************");
    printf("\n\n    --> TOTAL DE LA SUMA DE SALARIOS DE LOS EMPLEADOS $%d\n", acumuladorSalarios);
    printf("\n    --> EL SALARIO PROMEDIO ES DE $%.0f\n", promedio);
    printf("\n    --> DE %d EMPLEADO/S REGISTRADO/S, %d SUPERA/N EL SALARIO PROMEDIO\n\n\n\n", contadorPersonas, contPersonasSalarioPromedio);

    return 0;
}

void caseThreeEmployee(eEmployee lista[], int tam)
{
    if(checkEmployees(lista, tam)==1)
    {
        removeEmployee(lista,tam);
    }else
    {
        printf("\n\n\n              ERROR. NO HAY EMPLEADOS CARGADOS EN EL SISTEMA\n\n");
        system("pause");
    }

}

void caseTwoEmployee(eEmployee lista[], int tam)
{
    if(checkEmployees(lista, tam)==1)
    {
        modifyById(lista,tam);
    }else
    {
        printf("\n\n\n              ERROR. NO HAY EMPLEADOS CARGADOS EN EL SISTEMA\n\n");
        system("pause");
    }
}

void caseFourEmployee(eEmployee lista[], int tam, int *criterion, int *exit)
{
    if(checkEmployees(lista, tam)==1)
    {

    	int option;
    	int optCrit;

    	do
    	{
    		menuReport(*criterion);
    		printf("DIGITE OPCION: ");
    		scanf("%d", &option);

    		switch(option)
    		{
    		case 0:
    			do{
    				do
    				{
        				printf("\n\n            QUE CRITERIO DESEA USAR?\n\n");
        				printf("            [1]- DESCENDENTE A ASCENDENTE\n");
        				printf("            [2]- ASCENDENTE A DESCENDENTE\n\n");
    					printf("           DIGITE OPCION: ");
    					fflush(stdin);
    					scanf("%d", &optCrit);

    				}while(isdigit(optCrit)!=0);

    				if(optCrit!=1 && optCrit != 2)
    				{
    					printf("\n\n            ERROR! OPCION NO VALIDA!\n");
    				}

    			}while(optCrit!=1 && optCrit!=2);

    			if(optCrit==1)
    			{
    				*criterion = 1;
    			}
    			else if(optCrit==2)
    			{
    				*criterion = 0;
    			}
    			break;

    		case 1:
    			sortEmployees(lista, tam, *criterion);
    			printEmployees(lista, tam);
    			system("pause");
    			break;
    		case 2:
    			averagesSalary(lista, tam);
    			system("pause");
    			break;
    		case 3:
    			*exit = 0;
    			break;
    		default:
                printf("\n\n\n            OPCION NO VALIDA.\n\n");
                break;

    		}

    	}while(*exit==1);

    }else
    {
        printf("\n\n\n              ERROR. NO HAY EMPLEADOS CARGADOS EN EL SISTEMA\n\n");
        system("pause");
    }
}

