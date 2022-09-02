/*
 ============================================================================
 Name        : �the.c
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

	int valorIngresado;
	int numeroMenorIngresado;
	int numerosPares = 0;
	int numerosImpares = 0;
	int numeroParMayor = 2;
	int acumuladorPositivos = 0;
	int productoNegativos = 0;
	int flag = 0;

	for (int i = 0; i < 10; i++) {

		printf("Ingrese un numero");
		scanf("%d", &valorIngresado);
		while (valorIngresado == 0) {
			printf("Ingrese un numero distinto de 0");
			scanf("%d", &valorIngresado);
		}

		if (flag == 0 || numeroMenorIngresado > valorIngresado){
			numeroMenorIngresado = valorIngresado;
			flag = 1;
		}

		if(valorIngresado % 2 == 0){
			numerosPares++;
			if(valorIngresado > numeroParMayor){
				numeroParMayor = valorIngresado;
			}
		}else{
			numerosImpares++;
		}

		if(valorIngresado > 0){
			acumuladorPositivos += valorIngresado;
		}else{
			productoNegativos *= valorIngresado;
		}

	return EXIT_SUCCESS;
}
/*Ingresar 10 números enteros, distintos de cero. Mostrar:
 -Cantidad de pares e impares.
 -El menor número ingresado.
 -De los pares el mayor número ingresado.
 -Suma de los positivos.
 -Producto de los negativos.

 */
