#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

#define TAM 100

/** \brief inicia empleados
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna -1 si no pudo iniciar o un valor distinto si pudo
 *
 */
int initEmployees(eEmployee lista[], int tam);

/** \brief busca un lugar libre en el array de estructura
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna un slot vacio para que sea ocupado por un nuevo empleado
 *
 */
int freePlace(eEmployee lista[], int tam);

/** \brief chequea que haya empleados en el array
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna un valor para saber si se puede o no se puede ingresar a los menues de baja y modificacion
 *
 */
int checkEmployees(eEmployee lista[], int tam);

/** \brief añade un empleado al array
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \param id int* recibe puntero del id para incrementarlo
 * \return int retorna 1 o 0
 *
 */
int addEmployees(eEmployee lista[], int tam, int* id);

/** \brief modifica el empleado
 *
 * \param lista[] eEmployee  array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna 1 o 0
 *
 */
int modifyById(eEmployee lista[], int tam);

/** \brief busca un empleado por su id
 *
 * \param lista[] eEmployee eEmployee  array de empleados
 * \param tam int tamaño de empleados
 * \param id int recibe un id para modificar sus atributos
 * \return int retorna 1 o 0
 *
 */
int findEmployeeById(eEmployee lista[], int tam, int id);

/** \brief elimina un empleado del sistema
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna 1 o 0
 *
 */
int removeEmployee(eEmployee lista[], int tam);

/** \brief imprime todos los empleados
 *
 * \param lista[] eEmployee eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna 1 o 0
 *
 */
int printEmployees(eEmployee lista[], int tam);

/** \brief imprime un empleado
 *
 * \param oneEmployee eEmployee recibe una ubicacion de un empleado
 * \return void
 *
 */
void printOneEmployee(eEmployee oneEmployee);

/** \brief ordena a los empleados segun criterio
 *
 * \param list[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \param crit int criterio ascendente o descendente
 * \return int retorna 1 o 0
 *
 */
int sortEmployees(eEmployee lista[], int tam, int crit);

/** \brief promedio de salarios
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return int retorna 1 o 0
 *
 */
int averagesSalary(eEmployee lista[], int tam);

/** \brief en caso de que ingrese a la tercer opc del menu
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return void
 *
 */
void caseThreeEmployee(eEmployee lista[], int tam);

/** \brief en caso de que ingrese a la segunda opc del menu
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \return void
 *
 */
void caseTwoEmployee(eEmployee lista[], int tam);

/** \brief en caso de que ingrese a la cuarta opc del menu
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño de empleados
 * \param criterion int* criterio asc o desc
 * \param exit int* exit
 * \return void
 *
 */
void caseFourEmployee(eEmployee lista[], int tam, int *criterion, int *exit);



#endif /* ARRAYEMPLOYEES_H_ */
