/*
 ============================================================================
 Name        : 0-ApuntesClase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*	CLASE 14/9

	Recursividad (No se usa):

	char nombre[5][100]; seria 5 nombres con 100 char cada uno. una regla de estilos seria. si tengo tantos nombres
						 y tantos apellidos ponele.
	nunca usar array[4] = algo; no seas tonto usar strncpy(Donde copio, que copio).
	swap cambiar dos valores.
	cuando no swapea, esta ordenado.


	array[] = {23,43,68,9,0};
int ordenarArray (int Array[], int len){

	int flagSwap;
	int i;

	if(array[] != NULL && len > 0){

		do{



	}while(flagSwap);
}

/*string.h
 * strlen
 * strcpy
 * strcmp
 * stricmp
 * strcat
 * strupr (win)
 * strlwr (win)
 * */

/*stdio.h
 * gets (win)
 * fgets -> manejo de archivos :
 * scanf
 * printf
 * puts
 * sprintf
 * */

/*ctype.h
 *tolower
 *toupper
 *isspace
 *isdigit
 *isalpha
 * */

/*stdlib.h
 *atoi (parseInt)
 *atof (parseFloat)
 *itoa (entero a cadena)
 * */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	char numero[1] = {'9'};
	int prueba;

	prueba = atoi(numero);

	if(prueba == 9){
		printf("Es igualito");
	}else{
		printf("NKV");
	}
	return EXIT_SUCCESS;
}

int mostrarMenu(int* eleccionMenu, int* numeroA, int* numeroB)
{
	int flagA = 0;
	int flagB = 0;
	int flag3 = 0;
	int resultSuma;
	int resultResta;
	int resultMultiplicacion;
	float resultDivision;
	int resultFactorialA;
	int resultFactorialB;
	int flagMenu = 0;


	do
	{
		if(flagMenu == 0 && flagA == 0 && flagB ==0)
		{
			printf("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=y)\n"
				"3. Calcular todas las operaciones\n"
				"\ta) Calcular la suma (A+B)\n"
				"\tb) Calcular la resta (A-B)\n"
				"\tc) Calcular la division (A/B)\n"
				"\td) Calcular la multiplicacion (A*B)\n"
				"\te) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"\ta) El resultado de A+B es: r\n"
				"\tb) El resultado de A-B es: r\n"
				"\tc) El resultado de A/B es: r\n"
				"\td) El resultado de A*B es: r\n"
				"\te) El factorial de A es: r1 y El factorial de B es: r2\n"
				"5. Salir\n");

			scanf("\n%d", &*eleccionMenu);
		}
		if(flagA == 1 && flagB == 0)
		{
			printf("1. Ingresar 1er operando (A=%d)\n"
				"2. Ingresar 2do operando (B=y)\n"
				"3. Calcular todas las operaciones\n"
				"\ta) Calcular la suma (A+B)\n"
				"\tb) Calcular la resta (A-B)\n"
				"\tc) Calcular la division (A/B)\n"
				"\td) Calcular la multiplicacion (A*B)\n"
				"\te) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"\ta) El resultado de A+B es: r\n"
				"\tb) El resultado de A-B es: r\n"
				"\tc) El resultado de A/B es: r\n"
				"\td) El resultado de A*B es: r\n"
				"\te) El factorial de A es: r1 y El factorial de B es: r2\n"
				"5. Salir\n", *numeroA);

			scanf("\n%d", &*eleccionMenu);
		}
		if(flagB == 1 && flagA == 0)
		{
			printf("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=%d)\n"
				"3. Calcular todas las operaciones\n"
				"\ta) Calcular la suma (A+B)\n"
				"\tb) Calcular la resta (A-B)\n"
				"\tc) Calcular la division (A/B)\n"
				"\td) Calcular la multiplicacion (A*B)\n"
				"\te) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"\ta) El resultado de A+B es: r\n"
				"\tb) El resultado de A-B es: r\n"
				"\tc) El resultado de A/B es: r\n"
				"\td) El resultado de A*B es: r\n"
				"\te) El factorial de A es: r1 y El factorial de B es: r2\n"
				"5. Salir\n", *numeroB);

			scanf("\n%d", &*eleccionMenu);
		}

		if(flagA == 1 && flagB ==1 && flagMenu == 0)
		{
			printf("1. Ingresar 1er operando (A=%d)\n"
				"2. Ingresar 2do operando (B=%d)\n"
				"3. Calcular todas las operaciones\n"
				"\ta) Calcular la suma (A+B)\n"
				"\tb) Calcular la resta (A-B)\n"
				"\tc) Calcular la division (A/B)\n"
				"\td) Calcular la multiplicacion (A*B)\n"
				"\te) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"\ta) El resultado de A+B es: r\n"
				"\tb) El resultado de A-B es: r\n"
				"\tc) El resultado de A/B es: r\n"
				"\td) El resultado de A*B es: r\n"
				"\te) El factorial de A es: r1 y El factorial de B es: r2\n"
				"5. Salir\n", *numeroA, *numeroB);

			scanf("\n%d", &*eleccionMenu);
		}
		if(flagMenu == 1)
		{
			printf("1. Ingresar 1er operando (A=%d)\n"
					"2. Ingresar 2do operando (B=%d)\n"
					"3. Calcular todas las operaciones\n"
					"\ta) Calcular la suma (A+B)\n"
					"\tb) Calcular la resta (A-B)\n"
					"\tc) Calcular la division (A/B)\n"
					"\td) Calcular la multiplicacion (A*B)\n"
					"\te) Calcular el factorial (A!)\n"
					"4. Informar resultados\n"
					"\ta) El resultado de A+B es: %d\n"
					"\tb) El resultado de A-B es: %d\n", *numeroA, *numeroB, resultSuma, resultResta);

			if(*numeroB != 0)
			{
				printf("\tc) El resultado de A/B es: %.2f\n", resultDivision);
			}
			else
			{
				printf("\tc) No es posible dividir por cero\n");
			}
			printf("\td) El resultado de A*B es: %d\n"
				   "\te) El factorial de A es: %d y El factorial de B es: %d\n"
				   "5. Salir\n", resultMultiplicacion, resultFactorialA, resultFactorialB);

			scanf("\n%d", &*eleccionMenu);
		}


		switch(*eleccionMenu)
		{
			case 1:
				printf("Ingrese valor de A\n");
				scanf("\n%d", &*numeroA);
				flagA = 1;
				break;
			case 2:
				printf("Ingrese valor de B\n");
				scanf("\n%d", &*numeroB);
				flagB = 1;
				break;
			case 3:
				if(flagA == 1 && flagB == 1)
				{
					sumar(*numeroA, *numeroB, &resultSuma);
					restar(*numeroA, *numeroB, &resultResta);
					multiplicar(*numeroA, *numeroB, &resultMultiplicacion);
					dividir(*numeroA, *numeroB, &resultDivision);
					factorizar(*numeroA, *numeroB, &resultFactorialA, &resultFactorialB);
					flag3 = 1;
				}
				else
				{
					printf("Falta ingresar un valor\n");
				}
				flag3 = 1;
				break;
			case 4:
				if(flag3 == 1)
				{
					flagMenu = 1;
				}
				else
				{
					printf("Falta realizar los calculos\n");
				}

				break;
			case 5:
				break;
			}
	}while(*eleccionMenu != 5);
	return 0;
}
