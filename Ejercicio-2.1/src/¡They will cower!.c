/*
 ============================================================================
 Name        : �They.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int acumulador = 0;
	int valorIngresado;
	float resultado;
	int contador = 0;

	for (int i = 0; i < 5; i++) {
		printf("Ingrese un numero \n");
		scanf("%d", &valorIngresado);
		acumulador += valorIngresado;
		printf("Guardado con exito \n");
		contador++;
	}

	resultado = (float)acumulador / contador;

	printf("El promedio de los valores ingresados es: %.2f", resultado); // %.2f te da dos decimales float.

	return EXIT_SUCCESS;
}
/*
 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números.
 Probar la aplicación con distintos valores.
 Ejemplo 1:  3 - 5 - 7 - 9 - 1
 Ejemplo 2:  2 - 1 - 8 - 1 - 2
*/
