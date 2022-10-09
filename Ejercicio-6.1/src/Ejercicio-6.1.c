/*
 Ejercicio 6-1:

 Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio de
 valores de dichas variables

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int a = 1;
	int b = 8;
	int auxint; // se crea auxiliar para no perder el dato de a o b;

	printf("El valor en A: '%d' y el valor en B es: '%d'\n", a, b);

	auxint = a;
	a = b;
	b = auxint;
	system("pause");

	printf("El valor en A: '%d' y el valor en B es: '%d'\n", a, b);


	return EXIT_SUCCESS;
}
