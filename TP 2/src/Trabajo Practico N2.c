/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Osuna, Darian
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	int option;
	int follow;
	int id;
	int exitReport;
	int criterion;

	criterion = 1;
	exitReport = 1;
	follow = 1;
	id = 1000;


	eEmployee list [TAM];/*={
		{1000,"Bruno","Zuculini",100000,4,0},
		{1001,"Franco","Armani",180000,1,0},
		{1002,"Enrique","Bologna",110000,1,0},
		{1003,"Agustin","Fontana",100000,5,0},
		{1004,"Matias","Suarez",210000,5,0},
		{1005,"Jorge","Carrascal",140000,4,0},
		{1006,"Nicolas","De la Cruz",150000,3,0},
		};*/

	initEmployees(list,TAM);

	do
	{

		do
		{
			menuOptions();
			printf("           DIGITE OPCION: ");
			fflush(stdin);
			scanf("%d", &option);
		}while(isdigit(option)!=0);

		switch(option)
		{
			case 1:
				addEmployees(list, TAM, &id);
				break;
			case 2:
				caseTwoEmployee(list,TAM);
				break;
			case 3:
				caseThreeEmployee(list,TAM);
				break;
			case 4:
				caseFourEmployee(list,TAM,&criterion,&exitReport);
				break;
			case 5:
				follow = exitMenu();
				break;
			default:
				printf("\n\nOPCION NO VALIDA.\n\n");
				break;
		}

	}while(follow==1);

	return EXIT_SUCCESS;
}



