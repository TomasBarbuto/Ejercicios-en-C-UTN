/*
 * validaciones.c
 *
 *  Created on: 24 sep. 2022
 *      Author: barbu
 */
#include <stdio.h>

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

