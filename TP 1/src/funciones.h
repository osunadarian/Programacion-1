#ifndef DADA_H_INCLUDED
#define DADA_H_INCLUDED

/** \brief Titulo decorativo
 *
 * \return void no retorna nada
 *
 */
void title();

/** \brief menu del programa
 *
 * \param numA float recibe el numero A para mostrarlo en el menu
 * \param numB float recibe el numero para mostrarlo en el menu
 * \param flagA int recibe la bandera para saber si se ingreso un numero y mostrarlo
 * \param flagB int recibe la bandera para saber si se ingreso un numero y mostrarlo
 * \return void no retorna nada
 *
 */
void menuCalculator(float numA, float numB, int flagA, int flagB);



/** \brief funcion que recibe un numero
 *
 * \param num float* dato de tipo flotante que recibe la funcion
 * \return int retorna 1 o 0
 *
 */
int getNumber(float *num);

/** \brief funcion sumar
 *
 * \param numA float dato a de tipo float
 * \param numB float dato b de tipo float
 * \param resultSum float* el resultado de a+b
 * \return int retorna el valor del error
 *
 */
int sum(float numA, float numB, float *resultSum);

/** \brief funcion resta
 *
 * \param numA float dato a de tipo float
 * \param numB float dato b de tipo float
 * \param resultRest float* el resultado de a-b
 * \return int retorna el valor del error
 *
 */
int rest(float numA, float numB, float *resultRest);

/** \brief funcion multiplicar
 *
 * \param numA float dato a de tipo float
 * \param numB float dato b de tipo float
 * \param resultMult float* el resultado de a*b
 * \return int retorna el valor del error
 *
 */
int multiplication(float numA, float numB, float *resultMult);

/** \brief funcion division
 *
 * \param numA float dato a de tipo float
 * \param numB float dato b de tipo float
 * \param resultDiv float* el resultado de a/b
 * \return int retorna el valor del error
 *
 */
int division(float numA, float numB, float *resultDiv);

/** \brief funcion que realiza el factoreo de un numero
 *
 * \param num float dato de tipo float
 * \param factResult long int* resultado del factoreo del dato
 * \return int  retorna el valor del error
 *
 */
int factorial(float num, long int *factResult);


/** \brief funcion que realiza los calculos de la calculadora
 *
 * \param flagA int flag para ver si se pueden realizar los calculos
 * \param flagB int flag para ver si se pueden realizar los calculos
 * \param numA float dato a utilizar para las cuentas
 * \param numB float dato a utilizar para las cuentas
 * \param resultSum float* resultado suma
 * \param resultRest float* resultado resta
 * \param resultMult float* resultado multiplicacion
 * \param resultDiv float* resultado division
 * \param factResultA long int* resultado factoreo A
 * \param factResultB long int* resultado factoreo B
 * \return int retorna el valor del error
 *
 */
int calculate(int flagA, int flagB, float numA, float numB, float *resultSum, float *resultRest, float *resultMult, float *resultDiv, long int *factResultA, long int *factResultB);


/** \brief funcion que muestra los resultados de las operaciones
 *
 * \param flagOperations int variable con resultado de haber realizado los calculos o no
 * \param numA float variable para mostrar el numero A
 * \param numB float variable para mostrar el numero B
 * \param resultSum float variable que muestra resultado de la suma
 * \param resultRest float variable que muestra resultado de la resta
 * \param resultMult float  variable que muestra resultado de la multiplicacion
 * \param resultDiv float variable que muestra resultado de la division
 * \param factResultA long int variable que muestra resultado del factoreo del numero A
 * \param factResultB long int variable que muestra resultado del factoreo del numero B
 * \return int retorna el valor del error
 *
 */
int showOperations(int flagOperations, float numA, float numB, float resultSum, float resultRest, float resultMult, float resultDiv, long int factResultA, long int factResultB);

/** \brief funcion que se encarga de determinar si el numero ingresado es entero o no lo es
 *
 * \param num float dato flotante a analizar
 * \return int retorna el valor del error
 *
 */
int numberInteger(float num);

/** \brief funcion que cierra definitivamente el programa
 *
 * \param close int* dato de tipo int que se utiliza como opcion elegida por el usuario
 * \param flagA int* toma el flag para reiniciar los valores de los numeros si se apreto en salir
 * \param flagB int* toma el flag para reiniciar los valores de los numeros si se apreto en salir
 * \return int retorna valor del error
 *
 */
int closeProgram(int *close, int *flagA, int *flagB);

#endif // DADA_H_INCLUDED
