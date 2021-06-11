#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
#include "parser.h"
#include "menu.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pData = fopen(path,"r");

		if(parser_EmployeeFromText(pData,pArrayListEmployee)==0)
		{
			error = 0;
		}
	}

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pData = fopen(path,"rb");

		if(parser_EmployeeFromText(pData,pArrayListEmployee)==0)
		{
			error = 0;
		}
	}

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	int len;
	Employee* employee;

	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee!=NULL)
	{

		if(len>0){

			printf("\n\n\n  ID     NOMBRE              SUELDO        HORAS TRABAJADAS\t\n");
			printf("--------------------------------------------------------------------\n\n");

			for(int i=0;i<len;i++)
			{
				employee = (Employee*)ll_get(pArrayListEmployee, i);
				printOneEmployee(employee);
			}

		}else
		{
			printf("NO HAY EMPLEADOS CARGADOS EN EL SISTEMA!\n");
		}


		error = 0;
	}

    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

	Employee* newEmployee;
	int nuevoSueldo;
	int nuevasHorasTrabajadas;
	int nuevoId;
	char nuevoNombre[128];
	int tam;
	int proximoId;
	int validacionCadena;

	tam = ll_len(pArrayListEmployee);
	proximoId = tam + 1;

	if(pArrayListEmployee)
	{

		newEmployee = employee_new();

		if(newEmployee!=NULL)
		{

			nuevoId = proximoId;

			printf("\n                    INGRESE NOMBRE: ");
			fflush(stdin);
			gets(nuevoNombre);
			validacionCadena = validarCadena(nuevoNombre);
			fflush(stdin);
			formatearString(nuevoNombre);
			while(validacionCadena == 1)
			{
				printf("\n           ERROR EN LA LECTURA. REINGRESE NOMBRE: ");
				fflush(stdin);
				gets(nuevoNombre);
				validacionCadena = validarCadena(nuevoNombre);
				fflush(stdin);
				formatearString(nuevoNombre);
			}

			printf("\n                    INGRESE SUELDO: ");
			fflush(stdin);
			scanf("%d", &nuevoSueldo);
			while(nuevoSueldo < 23544)
			{
				printf("\n\n                         HA OCURRIDO UN ERROR");
				printf("\n  EL SUELDO INGRESADO NO PUEDE SER MENOR AL SUELDO MINIMO VITAL Y MOVIL [$23.544]");
				printf("\n\n                          NOMBRE: %s", nuevoNombre);
				printf("\n\n                  POR FAVOR, REINGRESE EL SUELDO: ");
				fflush(stdin);
				scanf("%d", &nuevoSueldo);
				printf("\n");
			}

			printf("\n                    INGRESE HORAS TRABAJADAS: ");
			fflush(stdin);
			scanf("%d", &nuevasHorasTrabajadas);
			while(nuevasHorasTrabajadas < 0)
			{
				printf("\n\n                         HA OCURRIDO UN ERROR");
				printf("\n          LAS HORAS INGRESADAS NO PUEDEN SER MENORES A CERO (0)\n");
				printf("\n\n                          NOMBRE: %s", nuevoNombre);
				printf("\n\n               POR FAVOR, REINGRESE LAS HORAS TRABAJADAS: ");
				fflush(stdin);
				scanf("%d", &nuevasHorasTrabajadas);
				printf("\n");
			}


			if((employee_setNombre(newEmployee,nuevoNombre)==0) &&
				(employee_setSueldo(newEmployee,nuevoSueldo)==0) &&
				(employee_setHorasTrabajadas(newEmployee,nuevasHorasTrabajadas)==0) &&
				(employee_setId(newEmployee,nuevoId)==0))
			{
				ll_add(pArrayListEmployee, newEmployee);
				printf("\n\n     EL NUEVO EMPLEADO HA SIDO CARGADO AL SISTEMA CON EXITO\n\n");
				system("pause");
				error=0;
			}else
			{
				printf("\n\n     HA OCURRIDO UN ERROR DURANTE LA CARGA DEL EMPLEADO\n\n");
				system("pause");
			}

		}

	}

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	Employee* modifyEmployee;
	int auxSueldo;
	int auxHorasTrabajadas;
	char auxNuevoNombre[128];
	int tam;
	int idBuscado;
	int idAcomparar;
	int validacionCadena;
	int opcion;


	tam = ll_len(pArrayListEmployee);

	if(pArrayListEmployee!=NULL && tam>0)
	{

		if(tam>0)
		{

			controller_ListEmployee(pArrayListEmployee);
			printf("\nPor favor, ingrese el ID a modificar: ");
			scanf("%d", &idBuscado);

			for(int i=0; i<tam; i++)
			{
				modifyEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(modifyEmployee,&idAcomparar);

				if(idBuscado==idAcomparar)
				{

					printf("\n\n\n                  QUE AREA DESEA MODIFICAR?  \n\n");
					printf("                        [1]  NOMBRE\n");
					printf("                        [2]  SUELDO\n");
					printf("                        [3]  HORAS TRABAJADAS\n");
					printf("\n                       DIGITE OPCION: ");
					fflush(stdin);
					scanf("%d", &opcion);

					switch(opcion)
					{
					case 1:
						printf("\n                    INGRESE NOMBRE: ");
						fflush(stdin);
						gets(auxNuevoNombre);
						validacionCadena = validarCadena(auxNuevoNombre);
						fflush(stdin);
						formatearString(auxNuevoNombre);
						while(validacionCadena == 1)
						{
							printf("\n           ERROR EN LA LECTURA. REINGRESE NOMBRE: ");
							fflush(stdin);
							gets(auxNuevoNombre);
							validacionCadena = validarCadena(auxNuevoNombre);
							fflush(stdin);
							formatearString(auxNuevoNombre);
						}

						if(employee_setNombre(modifyEmployee, auxNuevoNombre)==0)
						{
							printf("\n          EXITO EN LA MODIFICACION DEL NOMBRE!\n");
						}else
						{
							printf("\n          ERROR EN LA MODIFICACION DEL NOMBRE!\n");
						}
						break;

					case 2:
						printf("\n                    INGRESE SUELDO: ");
						fflush(stdin);
						scanf("%d", &auxSueldo);
						while(auxSueldo < 23544)
						{
							printf("\n\n                         HA OCURRIDO UN ERROR");
							printf("\n  EL SUELDO INGRESADO NO PUEDE SER MENOR AL SUELDO MINIMO VITAL Y MOVIL [$23.544]");
							printf("\n\n                          NOMBRE: %s", auxNuevoNombre);
							printf("\n\n                  POR FAVOR, REINGRESE EL SUELDO: ");
							fflush(stdin);
							scanf("%d", &auxSueldo);
							printf("\n");
						}

						if(employee_setSueldo(modifyEmployee, auxSueldo)==0)
						{
							printf("\n          EXITO EN LA MODIFICACION DEL SUELDO!\n");
						}else
						{
							printf("\n          ERROR EN LA MODIFICACION DEL SUELDO!\n");
						}
						break;

					case 3:
						printf("\n                    INGRESE HORAS TRABAJADAS: ");
						fflush(stdin);
						scanf("%d", &auxHorasTrabajadas);
						while(auxHorasTrabajadas < 0)
						{
							printf("\n\n                         HA OCURRIDO UN ERROR");
							printf("\n          LAS HORAS INGRESADAS NO PUEDEN SER MENORES A CERO (0)\n");
							printf("\n\n                          NOMBRE: %s", auxNuevoNombre);
							printf("\n\n               POR FAVOR, REINGRESE LAS HORAS TRABAJADAS: ");
							fflush(stdin);
							scanf("%d", &auxHorasTrabajadas);
							printf("\n");
						}

						if(employee_setHorasTrabajadas(modifyEmployee, auxHorasTrabajadas)==0)
						{
							printf("\n          EXITO EN LA MODIFICACION DE LAS HORAS TRABAJADAS!\n");
						}else
						{
							printf("\n          ERROR EN LA MODIFICACION DE LAS HORAS TRABAJADAS!\n");
						}

						break;
					default:
						printf("\n\n\n                            %d NO ES UNA OPCION VALIDA.", opcion);
						break;
					}
				}


			}
		}

		error = 0;

	}else
	{

		printf("\n\n\n	                    No hay empleados cargados en el sistema\n\n\n");

	}

    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	Employee* deleteEmployee;
	int tam;
	int idBuscado;
	int opcion;
	int idAcomparar;


	tam = ll_len(pArrayListEmployee);

	if(pArrayListEmployee!=NULL && tam>0)
	{

		if(tam>0)
		{
			controller_ListEmployee(pArrayListEmployee);
			printf("\nPor favor, ingrese el ID a eliminar del sistema: ");
			scanf("%d", &idBuscado);

			for(int i=0; i<tam; i++)
			{
				deleteEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(deleteEmployee,&idAcomparar);

				if(idBuscado==idAcomparar)
				{

					printf("\nEl siguiente empleado sera eliminado del sistema\n");
					printf("ID\t NOMBRE\t\t SUELDO\t HORAS TRABAJADAS\t\n");
					printOneEmployee(deleteEmployee);

					printf("DESEA DAR LA BAJA DEFINITIVA DEL EMPLEADO?\n\n");
					printf("SI -> 1\n");
					printf("NO -> 2\n\n");
					printf("OPCION ELEGIDA: ");
					scanf("%d", &opcion);

					if(opcion==1)
					{

						ll_remove(pArrayListEmployee, i);
						printf("\n          EXITO EN LA ELIMINACION DEL EMPLEADO!\n");
						error = 0;

					}else
					{
						printf("\n          EL EMPLEADO NO HA SIDO ELIMINADO POR DECISION DEL USUARIO!\n");
						error = 2;
						break;
					}

				}
			}
		}
	}else
	{
		printf("\n\n\n	                    No hay empleados cargados en el sistema\n\n\n");
	}

    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	int opcion;

	if(ll_isEmpty(pArrayListEmployee) == 0 && pArrayListEmployee != NULL)
	{
		do
			{
				menuOrdenamiento();
				printf("           				DIGITE OPCION: ");
				fflush(stdin);
				scanf("%d", &opcion);
			}while(isdigit(opcion)!=0);

			switch(opcion)
			{
			case 1:
				ll_sort(pArrayListEmployee, ordenarPorId, 1);
				break;
			case 2:
				ll_sort(pArrayListEmployee, ordenarPorId, 0);
				break;
			case 3:
				ll_sort(pArrayListEmployee, ordenarPorNombre, 1);
				break;
			case 4:
				ll_sort(pArrayListEmployee, ordenarPorNombre, 0);
				break;
			case 5:
				ll_sort(pArrayListEmployee, ordenarPorHorasTrabajadas, 1);
				break;
			case 6:
				ll_sort(pArrayListEmployee, ordenarPorHorasTrabajadas, 0);
				break;
			case 7:
				ll_sort(pArrayListEmployee, ordenarPorSueldo, 1);
				break;
			case 8:
				ll_sort(pArrayListEmployee, ordenarPorSueldo, 0);
				break;
			case 9:
				printf("\n				Opcion no valida\n");
			}
	}else
	{
		printf("\n\n\n	                    No hay empleados cargados en el sistema\n\n\n");
	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	int tam;

	char nuevoNombre[128];
	int nuevoSueldo;
	int nuevasHorasTrabajadas;
	int nuevoId;

	Employee* newEmployee = NULL;

	FILE* pFile=fopen(path,"w");

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{

		tam = ll_len(pArrayListEmployee);
		fprintf(pFile,"ID,NOMBRE,SUELDO,HORAS TRABAJADAS\n");

		for(int i=0;i<tam;i++)
		{

			newEmployee = (Employee*) ll_get(pArrayListEmployee,i);

			if((employee_getNombre(newEmployee,nuevoNombre)==0) &&
			(employee_getSueldo(newEmployee,&nuevoSueldo)==0) &&
			(employee_getHorasTrabajadas(newEmployee,&nuevasHorasTrabajadas)==0) &&
			(employee_getId(newEmployee,&nuevoId)==0))
			{

				fprintf(pFile,"%d,%s,%d,%d\n", nuevoId, nuevoNombre, nuevoSueldo, nuevasHorasTrabajadas);

			}
		}

		fclose(pFile);
		error = 0;
	}

	return error;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	int tam;

	Employee* newEmployee = NULL;
	FILE* pFile=fopen(path,"wb");


	if(pFile!=NULL && pArrayListEmployee!= NULL)
	{
		tam = ll_len(pArrayListEmployee);

		for(int i=0;i<tam;i++)
		{

			newEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			fwrite(newEmployee, sizeof(Employee),1,pFile);
		}

		fclose(pFile);
	}

	return error;
}

