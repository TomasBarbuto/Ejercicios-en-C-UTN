/*
 Ejercicio 6-2:

 Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos). Necesito
 generar un listado de los números positivos de manera creciente y negativos de manera decreciente.

 (Como máximo 5 estructuras repetitivas)

 */

#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

int main(void) {
	setbuf(stdout, NULL);

	int arrayNumeros[10];
	int arrayPositivos[10];
	int arrayNegativos[10];
	int contadorNegativos = 0;
	int contadorPositivos = 0;

	inicializarArrays(arrayNumeros, 10);

	for(int i = 0; i < 10; i++){

		if(arrayNumeros[i] >= 0){
			arrayPositivos[contadorPositivos] = arrayNumeros[i];
			contadorPositivos++;
		}else{
			arrayNegativos[contadorNegativos] = arrayNumeros[i];
			contadorNegativos++;
		}

	}

	if(ordenarArray(arrayPositivos, contadorPositivos,1)){
		printf("Se ordeno correctamente los positivos\n");
		imprimirArray(arrayPositivos, contadorPositivos);
	}

	if(ordenarArray(arrayNegativos, contadorNegativos,0)){
		printf("Se ordeno correctamente los negativos\n");
		imprimirArray(arrayNegativos, contadorNegativos);
	}

	return EXIT_SUCCESS;
}
