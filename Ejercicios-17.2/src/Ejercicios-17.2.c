/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int* pArrayNumeros = NULL;
    int sizeArray = 2;
    int* pArrayNumAux = NULL;

    pArrayNumeros = (int*)malloc(sizeof(int) * sizeArray);
    if(pArrayNumeros != NULL){
        initArray(pArrayNumeros, sizeArray);
        //printArray(pArrayNumeros, sizeArray);
    }

    pArrayNumAux = (int*)realloc(pArrayNumeros, sizeof(int) * (sizeArray + 3));
    if (pArrayNumAux != NULL) {
        pArrayNumeros = pArrayNumAux;
        sizeArray = sizeArray + 3;
        printArray(pArrayNumeros, sizeArray);
    }


    return 0;
}


int printArray(int *pArrayNumeros,int sizeArray){
    int i;

    if(pArrayNumeros != NULL && sizeArray > 0){
        for(i = 0; i < sizeArray; i++){
            printf("Numero: %d\n",*(pArrayNumeros+i));
        }
    }
    return 0;
}



int initArray(int *pArrayNumeros,int sizeArray){
    int i;

    if(pArrayNumeros != NULL && sizeArray > 0){
        for(i = 0; i < sizeArray; i++){
            *(pArrayNumeros+i) = 0;
        }
    }
    return 0;
}


int moverValor (arrayNumeros[], int len, int numero){

	int retorno = 0;
	int pAux;

	if(arrayNumeros != NULL && len > 0){

		for(int i = 0; i < len; i++){

			if(*(arrayNumeros + i) == numero){

				pAux = *(arrayNumeros + i);
				*(arrayNumeros + i)  = *(arrayNumeros + i + 1);
				*(arrayNumeros + i + 1) = pAux;

			}
		}

	}
	return 0;
}













