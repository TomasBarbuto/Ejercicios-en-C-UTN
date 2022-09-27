/*
 * Mostrar.c
 *
 *  Created on: 22 sep. 2022
 *      Author: barbu
 */
#include <stdio.h>
#include <string.h>

void mostrarMenu(int *menu){

	printf("\nBievenido al menu de productos\n"
			"1-Dar ALTA de producto\n"
			"2-Dar BAJA de prodcuto\n"
			"3-Modificar un producto\n"
			"4-Imprimir Listado de productos\n"
			"5-Imprimir Listado de producto por precio\n"
			"6-Imprimir Listado por descripcion\n");

	if(utn_getNumber(menu, "A ingresado correctamente\n", "Numero no valido\n vuelva a reingresar un numero\n",1,6)){

		scanf("%d",menu);

	}

}

int utn_getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo){

	int retorno = 0;
	int bufferInt; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo){

		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo) {

				*pResultado = bufferInt;
				retorno = 1;
				break;

			}else{

				printf("%s", mensajeError);

			}

		}while(retorno == 0);
	}

	return retorno;
}


