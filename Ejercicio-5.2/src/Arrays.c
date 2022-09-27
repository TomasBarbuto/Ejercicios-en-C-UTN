/*
 * Arrays.c
 *
 *  Created on: 24 sep. 2022
 *      Author: barbu
 */
#include <stdio.h>
#include "validaciones.h"

void imprimirArray(int array[], int len){

	int i;

	if(array != NULL){

		for(i = 0; i < len; i++){

			printf("Iteracion numero: %d\n", i);
			printf("El valor es: %d\n", array[i]);

		}
	}
}

void inicializarArrays(int array[], int len){

	int i;

	for (i = 0; i < len; i++) {

		if (getNumber(&array[i], "Ingrese un numerpo entre 0-100\n",
				"No ingresaste un numero o no se encuentra dentro del rango\n",
				-100, 100)) {
		}
	}
}

void sumarArrays(int array[], int len, int* pResultado){

	int i;
	int acumulador = 0;

	for (i = 0; i < len; i++){

		acumulador += array[i];

	}

	*pResultado = acumulador;
}

void esParArray(int array[], int len){


	for(int i = 0; i < len; i++){

			if(esPar(array[i])){

				printf("Los numeros pares son: %d\n",array[i]);
			}

		}
}

void esIndexPar(int array[], int len){

	for(int i = 0; i < 10; i++){

			if(!esPar(i)){

				printf("En la posicion '%d' el valor es: %d\n",i,array[i]);
			}
		}

}

int ordenarArray(int array[], int len){
    int flagSwap;
    int i;
    int retorno = 0;
    int buffer;

    if(array != NULL && len > 0){
        do{
            flagSwap = 0;
            for(i = 0; i < len - 1; i++){
                if(array[i] > array[i+1]){
                    flagSwap = 1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
    }
    retorno = 1;
    return retorno;
}

int countRepeat(int array[], int len, int *count){

	int retorno = 0;

		for(int i = 0; i < len; i++){

				if(array[i] == array[i+1]){

					printf("Los numeros que se repiten son: %d\n", array[i]);
					(*count)++;
					retorno = 1;
				}
		}

	return retorno;
}
















