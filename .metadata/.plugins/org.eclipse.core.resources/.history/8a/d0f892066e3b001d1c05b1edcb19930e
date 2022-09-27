/*
 * Arrays.c
 *
 *  Created on: 23 sep. 2022
 *      Author: barbu
 */
#include <stdio.h>

int imprimirArray(int array[], int len){

	int i;

	if(array != NULL){

		for(i = 0; i < len;i++){
			printf("Iteracion numero: %d\n", i);
			printf("El valor es: %d\n", array[i]);
		}

	}
	return 0;
}

int cargaAleatoriaArray(int array[], int len, int valor, int index){
	int retorno = -1;

	if(array != NULL && len > 0 && index < len){

		array[index] = valor;

		retorno = 0;
	}

	return retorno;
}

int inicializarArray(int array[], int len, int init){
	int i;
	int cargoMal;
	int retorno = 0;

	if(array != NULL && len > 0){

		for(i = 0; i < len;i++){

			cargoMal = cargaAleatoriaArray(array, len, init, i);

			if (cargoMal == -1){

				retorno = -1;
				break;
			}
		}

	}
	return retorno;
}
