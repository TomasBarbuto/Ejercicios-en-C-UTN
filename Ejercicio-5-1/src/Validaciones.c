#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"


/**
*\brief: Pide un numero y valida que este dentro de un rango y que sea un numero.
*\
*\param: valor ingresado puntero a int, mensaje , error, rango minimo, rango maximo.
*\
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
*
*/


int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo) {

	int retorno = 0;
	int bufferInt; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo) {

				*pResultado = bufferInt;
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);

			}

		} while (retorno == 0);
	}

	return retorno;
}

/**
*\brief: Pide un numero flotante y valida que este dentro de un rango y que sea un numero.
*\
*\param: valor ingresado puntero a float, mensaje , error, rango minimo, rango maximo.
*\
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
*
*/

int getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo,
		float maximo) {

	int retorno = 0;
	float buffer; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &buffer);

			if (buffer >= minimo && buffer <= maximo) {

				*pResultado = buffer;
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);

			}

		} while (retorno == 0);
	}

	return retorno;
}

int esPar(int numero){

	int retorno = 0;

	if(numero % 2 == 0){

		retorno = 1;
	}


	return retorno;
}

int esPositivo(int numero){

	int retorno = 0;

	if(numero > 0){

		retorno = 1;
	}

	return retorno;
}

