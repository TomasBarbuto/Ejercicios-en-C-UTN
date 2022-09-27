/*
 Ejercicio 5-2:
 Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:

 a) Cantidad de positivos y negativos.
 b) Sumatoria de los pares.
 c) El mayor de los impares.
 d) Listado de los números ingresados.
 e) Listado de los números pares.
 f) Listado de los números de las posiciones impares.

 Anexo 5-2

 g) Los números que se repiten
 h) Los positivos creciente y los negativos de manera decreciente

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Arrays.h"


int main(void){
	setbuf(stdout, NULL);

	int arrayNumeros[10];
	int arrayPositivos[10];
	int arrayNegativos[10];

	int cantidadPositivos = 0;
	int cantidadNegativos = 0;
	int acumuladorPares;
	int mayorImpar;
	int flagImpar = 0;
	int contadorRepetidos = 0;
	int contadorPositivos = 0;
	int contadorNegativos = 0;

	inicializarArrays(arrayNumeros, 10); // le doy valor.
	for(int i = 0; i < 10; i++){

		if(esPositivo(arrayNumeros[i])){
			cantidadPositivos++;

		}else{

			cantidadNegativos++;
		}

		if(esPar(arrayNumeros[i])){

			sumarArrays(arrayNumeros, i+1, &acumuladorPares);

		}else if(flagImpar == 0 || mayorImpar < arrayNumeros[i]){

			mayorImpar = arrayNumeros[i];
			flagImpar = 1;
		}

		if(arrayNumeros[i] > 0){

			arrayPositivos[contadorPositivos] = arrayNumeros[i];

			contadorPositivos++;


		}else{

			arrayNegativos[contadorNegativos] = arrayNumeros[i];

			contadorNegativos++;

		}

	}

	countRepeat(arrayNumeros, 10, &contadorRepetidos); //cuenta los repetidos en el array[].
	imprimirArray(arrayNumeros, 10); //Todos
	system("pause");

	printf("cantidad positivos: %d\n", cantidadPositivos);
	printf("cantidad negativos: %d\n", cantidadNegativos);
	printf("sumatoria de pares es: %d\n", acumuladorPares);
	printf("El mayor impar es: %d\n", mayorImpar);
	esParArray(arrayNumeros, 10);
	esIndexPar(arrayNumeros, 10);
	printf("la cantidad de repetidos son: %d\n", contadorRepetidos);
	system("pause");

	printf("Los positivos ordenados son:\n");
	if(ordenarArray(arrayPositivos, contadorPositivos)){
		imprimirArray(arrayPositivos, contadorPositivos);
	}
	system("pause");

	printf("Los Negativos ordenados son:\n");
	if(ordenarArray(arrayNegativos, contadorNegativos)){
		imprimirArray(arrayNegativos, contadorNegativos);
	}


	return 0;
}














