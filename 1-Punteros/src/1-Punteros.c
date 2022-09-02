#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int sumarDosEnteros(int primerNumero, int segundoNumero);
int dividirDosEnteros(int primerNumero, int segundoNumero, int * resultadoDivision);

int main(void) {

	char operador;
	int numeroUno;
	int numeroDos;
	int resultado;
	int resultadoDivision = 3456;
	int retornoScanf;

	printf("\nNumero uno en main: %p\n", &numeroUno);

	printf("Ingrese el numero: ");
	retornoScanf = scanf("%d", &numeroUno);
	while (retornoScanf != 1) {
		printf("Le pifiaste al tipo\n");
		__fpurge(stdin);
		printf("Ingrese el numero: ");
		retornoScanf = scanf("%d", &numeroUno);
	}
	__fpurge(stdin);
	//fflush(stdin) SOLO WINDOWS
	printf("Ingrese el operador (+/-): ");
	retornoScanf = scanf("%c", &operador);

	printf("\nIngrese el numero: ");
	scanf("%d", &numeroDos);

	switch (operador) {
	case '+':
		resultado = sumarDosEnteros(numeroUno, numeroDos);
		break;
	case '-':
		resultado = numeroUno - numeroDos;
		break;
	case '/':
		printf("\nAntes de la funcion: %d", resultadoDivision);
		printf("\nPuntero en main de resultadoDivision: %p", &resultadoDivision);
		resultado = dividirDosEnteros(numeroUno, numeroDos, &resultadoDivision);
		if (resultado == -1) {
			printf("\nNo puede dividir por 0");
		}
		if (resultado == -2) {
			printf("\nNo puede ser mayor a 100 el primer numero");
		}
		printf("\nDespues de la funcion: %d", resultadoDivision);

		break;
	}

	//printf("El resultado es: %d", resultado);

	return 0;
}

int sumarDosEnteros(int primerNumero, int segundoNumero) {
	int suma;

	suma = primerNumero + segundoNumero;

	return suma;
}

int dividirDosEnteros(int a, int b, int * pepe) {
	int retorno = 0;

	if (a > 100) {
		retorno = -2;
	}

	if (b != 0) {

		*pepe = a / b;
		//operador de indireccion
	} else {
		retorno = -1;
	}

	return retorno;
}


