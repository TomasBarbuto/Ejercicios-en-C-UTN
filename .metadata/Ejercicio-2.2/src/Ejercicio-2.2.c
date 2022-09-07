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

int main(void) {
	setbuf(stdout, NULL);

	//Declaracion.
	int valorIngresado;
	int contadorPares;
	int contadorImpares;
	int menorNumeroIngresado;
	int sumaPositivos;
	int productoNegativos;
	int parMayor;
	int i;
	int flag = 0;

	//Asignacion.
	contadorPares = 0;
	contadorImpares = 0;
	sumaPositivos = 0;
	productoNegativos = 1;

	//Interacion.

	for (i = 0; i < 10; i++) {

		do {
			printf("Ingrese un numero distinto de 0 \n");
			scanf("%d", &valorIngresado);

		} while (valorIngresado == 0);

		if (valorIngresado % 2 == 0) {
			contadorPares++;
			if (flag == 0 || parMayor < valorIngresado) {
				parMayor = valorIngresado;
			}
		} else {
			contadorImpares++;
		}
		if (flag == 0 || menorNumeroIngresado > valorIngresado) {
			menorNumeroIngresado = valorIngresado;
			flag = 1;
		}

		if(valorIngresado > 0){
			sumaPositivos += valorIngresado;
		}else{
			productoNegativos *= valorIngresado;
		}

	}		//For

	printf("Cantidad de numeros pares: %d \n Cantidad de numeros impares : %d \n",contadorPares,contadorImpares);
	printf("El menor numero ingresado es: %d \n", menorNumeroIngresado);
	printf("De los pares el mayor número ingresado es: %d \n", parMayor);
	printf("La suma de los positivos es: %d \n", sumaPositivos);
	printf("El producto de los negativos es: %d \n", productoNegativos);

	return EXIT_SUCCESS;
}

/*
 Ejercicio 2-2:
 Ingresar 10 números enteros, distintos de cero. Mostrar:
 Cantidad de pares e impares.
 El menor número ingresado.
 De los pares el mayor número ingresado.
 Suma de los positivos.
 Producto de los negativos.
 *
 */
