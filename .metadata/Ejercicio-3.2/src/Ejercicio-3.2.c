/*
Ejercicio 3-2:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeroPar;
	int respuesta;

	printf("Ingrese un numero Par: \n");
	scanf("%d", &numeroPar);

	respuesta = validarNumeroPar(numeroPar, &respuesta);

	if(respuesta == 0){
		printf("El resultado es: %d", numeroPar);
	}else{
		printf("El numero no es par");
	}
	return 0;
}
