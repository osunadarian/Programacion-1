#ifndef CALCULOS_H_
#define CALCULOS_H_

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

#endif /* CALCULOS_H_ */
