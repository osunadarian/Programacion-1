#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief funcion que retorna espacio en memoria dinamica para un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{

	return (Employee*)malloc(sizeof(Employee));

}

/** \brief funcion que retorna un nuevo empleado precargado con sus campos
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

	Employee* auxEmployee = employee_new();

	if(auxEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr > 0)
	{
		if((employee_setId(auxEmployee,atoi(idStr))!=0) ||
				(employee_setNombre(auxEmployee,nombreStr)!=0) ||
				(employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr))!=0) ||
				(employee_setSueldo(auxEmployee,atoi(sueldoStr)) != 0)
				)
			{

				printf("\n -> Error en la carga de datos <-\n");
				free(auxEmployee);
				auxEmployee = NULL;

			}
	}

	return auxEmployee;
}

/** \brief obtiene id de empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
	int error = -1;

	if(this!=NULL && id!=NULL)
	{

		*id = this->id;
		error = 0;

	}

	return error;
}

/** \brief asigna id de un empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
	int error = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		error = 0;
	}

	return error;
}

/** \brief asigna nombre para un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int error = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		error = 0;
	}

	return error;
}

/** \brief obtiene nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int error = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		error = 0;
	}

	return error;
}

/** \brief asigna horas trabajadas para un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int error = -1;

	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas = horasTrabajadas;
		error = 0;
	}

	return error;
}

/** \brief obtiene horas trabajadas por un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int error = -1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		error = 0;
	}

	return error;
}

/** \brief asigna sueldo a un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int error = -1;

	if(this!=NULL)
	{
		this->sueldo = sueldo;
		error = 0;
	}

	return error;
}

/** \brief obtiene sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int error = -1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->sueldo;
		error = 0;
	}

	return error;
}

/** \brief printea un solo empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void printOneEmployee(Employee* this)
{

	printf("%4d     %-15s     %-6d              %-4d\n", ((*(this)).id), (*(this)).nombre, (*(this)).sueldo, (*(this)).horasTrabajadas);

}

/** \brief funcion que compara a dos empleados por nombre
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int
 *
 */
int ordenarPorNombre(void* empleado1, void* empleado2)
{

	int retorno;

	char* nombre1 =(char*) malloc(sizeof(char) * 128);
	char* nombre2 = (char*) malloc(sizeof(char) * 128);

	employee_getNombre(empleado1, nombre1);
	employee_getNombre(empleado2, nombre2);

	retorno = strcmp(nombre1, nombre2);

	free(nombre1);
	free(nombre2);

	return retorno;

}

/** \brief funcion que compara a dos empleados por horas trabajadas
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int
 *
 */
int ordenarPorHorasTrabajadas(void* empleado1, void* empleado2)
{
	int hora1;
	int hora2;
	int retorno;

	employee_getHorasTrabajadas(empleado1, &hora1);
	employee_getHorasTrabajadas(empleado2, &hora2);

	if((hora1-hora2)>0)
	{
		retorno = 1;
	}else
	{
		if((hora1-hora2) == 0)
		{
			retorno = 0;
		}else
		{
			retorno = -1;
		}
	}

	return retorno;

}

/** \brief funcion que compara a dos empleados por Sueldo
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int
 *
 */
int ordenarPorSueldo(void* empleado1, void* empleado2)
{
	int sueldo1;
	int sueldo2;
	int retorno;

	employee_getHorasTrabajadas(empleado1, &sueldo1);
	employee_getHorasTrabajadas(empleado2, &sueldo2);

	if((sueldo1-sueldo2)>0)
	{
		retorno = 1;
	}else
	{
		if((sueldo1-sueldo2) == 0)
		{
			retorno = 0;
		}else
		{
			retorno = -1;
		}
	}

	return retorno;

}

/** \brief funcion que compara a dos empleados por ID
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int
 *
 */
int ordenarPorId(void* empleado1, void* empleado2)
{
	int id1;
	int id2;
	int retorno;

	employee_getHorasTrabajadas(empleado1, &id1);
	employee_getHorasTrabajadas(empleado2, &id2);

	if((id1-id2)>0)
	{
		retorno = 1;
	}else
	{
		if((id1-id2) == 0)
		{
			retorno = 0;
		}else
		{
			retorno = -1;
		}
	}

	return retorno;

}

