/*
Ejercicio 3-4:
Especializar la función anterior para que permita validar el entero ingresado en un rango
determinado.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Validaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeroEntero;
	int respuesta;

	printf("Ingrese un numero Entero: \n");
	scanf("%d", &numeroEntero);

	respuesta = validarEntero(numeroEntero, &respuesta);

	if(respuesta == 0){
		printf("El resultado es: %d", numeroEntero);
	}else{
		printf("El numero ingresado no es Entero");
	}

	return 0;
}
