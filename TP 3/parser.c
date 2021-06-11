#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = -1;
	char buffer[4][128];
	int contadorTotal = 0;

	Employee* newEmployee = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{

		fscanf(pFile, "%[^,] , %[^,] , %[^,] , %[^,\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			contadorTotal = fscanf(pFile, "%[^,] , %[^,] , %[^,] , %[^,\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if(contadorTotal<4)
			{
				break;

			}else
			{
				newEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				ll_add(pArrayListEmployee, newEmployee);
				error = 0;
			}
		}
	}

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = -1;
	int contadorTotal = 0;

	Employee* newEmployee = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			contadorTotal = fread(newEmployee,sizeof(Employee*),1,pFile);

			if(contadorTotal<4)
			{
				break;

			}else
			{
				ll_add(pArrayListEmployee, newEmployee);
				error = 0;
			}
		}
	}

	return error;

}
