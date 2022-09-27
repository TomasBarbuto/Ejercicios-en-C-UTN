/*
 Ejercicio 5-1:
 Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "Arrays.h"

int main(void) {
	setbuf(stdout, NULL);

	int arrayNumeros[5];
	int acumulador = 0;

	inicializarArrays(arrayNumeros, 5); // le damos valor en las posiciones.
	sumarArrays(arrayNumeros, 5, &acumulador); // sumamos los valores del array.
	imprimirArray(arrayNumeros, 5); //Imprime en consola la lista arrays.

	printf("La suma de los 5 numeros ingresado es: %d", acumulador);

	return 0;
}
