/*
 Ejercicio 4-1:
 Realizar un programa que permita calcular y mostrar el factorial de un número.
 Utilizar la función PedirNumero de la ejercitación 3-4.
 Por ejemplo:
 5! = 5*4*3*2*1 = 120
 */

#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeroEntero;
	int acumulador;
	int i;

	printf("Ingrese un numero Entero: \n");
	scanf("%d", &numeroEntero);

	acumulador = validarRango(numeroEntero);

	if (acumulador == -1) {
		printf("El numero no esta dentro del rango");
	} else {
		printf("El numero es: %d \n", acumulador);

	for (i = acumulador; i > 0; i--) {
		if (i == acumulador) {
			i--;
		}

		acumulador *= i;
	}

	printf("El factorial es: %d", acumulador);
	}

	return 0;

}
