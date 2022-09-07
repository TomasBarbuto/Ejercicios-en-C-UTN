/*
 Ejercicio 3-1:
 Crear una función que muestre por pantalla el número flotante que recibe como parámetro.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Validaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	float numeroFlotante;
	float respuesta;

	printf("Ingrese un numero Flotante: \n");
	scanf("%f", &numeroFlotante);

	respuesta = validarFlotante(numeroFlotante, &respuesta);

	if(respuesta == 0){
		printf("El resultado es: %f", numeroFlotante);
	}else{
		printf("El numero ingresado no es flotante");
	}

	return 0;
}

