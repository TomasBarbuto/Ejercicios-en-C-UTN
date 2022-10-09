/*
 Ejercicio 16-1:

 Realizar una función que reciba un puntero a char y dos char. La función deberá reemplazar en la
 cadena cada ocurrencia del primer carácter recibido, por el segundo. Retornando la cantidad de
 reemplazos o -1 en caso de error.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swapearChar(char arrayNombre[], char char1, char char2);
int remplazo(char primerCaracter, char segundoCaracter, int (*pFuncion)(char*, char,char));

int main(void) {
	setbuf(stdout, NULL);

	int funcion;

	funcion = remplazo('t','m',swapearChar);


	printf("%d\n", funcion);

	return 0;
}


int remplazo(char primerCaracter, char segundoCaracter, int (*pFuncion)(char*, char,char)){

	char nombre[] = "tomas";
	int retorno;

	retorno = pFuncion(nombre, primerCaracter, segundoCaracter);

	printf("%s\n", nombre);

	return retorno;
}

int swapearChar(char arrayNombre[], char char1, char char2){

	int retorno = -1;

	if(arrayNombre != NULL && char1 > 1 && char2 > 1){

		for(int i = 0; i < strlen(arrayNombre)-1; i++){

			if(arrayNombre[i] == char1){

				arrayNombre[i] = char2;
			}

		}

		retorno = 0;
	}


	return retorno;

}













