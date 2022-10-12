#include <stdio.h>
#include "Tipo.h"
#include <string.h>

/**
*\brief: Iniciar el campo isEmpty = 0, del array de tipo.
*\param: variable de tipo tipo.
*\return: Retorna 1 si lo inicio correctamente, Retorna 0 si ocurrio algun error.
**/
int initTipos(tipo tipos[]){

	int retorno = 0;

	if(tipos != NULL){

		tipos[0].idTipo = 1000;
		strncpy(tipos[0].descripcion,"Camion Recto", 30);

		tipos[1].idTipo = 1001;
		strncpy(tipos[1].descripcion,"Camion Remolque", 30);

		tipos[2].idTipo = 1002;
		strncpy(tipos[2].descripcion,"Camion Semirremolque", 30);

		tipos[3].idTipo = 1003;
		strncpy(tipos[3].descripcion,"Camion Elevador", 30);

		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Muestra los datos de indices del array de tipo.
*\param: Array de tipo, Longitud del array.
*\return: Retorna 1 si puede mostrarlo, Retorna 0 si ocurrio un error.
**/
int listTipos(tipo tipos[], int len) {

	int retorno = 0;

	if (tipos != NULL && len > 0) {

		printf("Los Tipos actuales son: \n\n");

		for (int i = 0; i < len; i++) {

			printf("ID: %d, %s\n", tipos[i].idTipo, tipos[i].descripcion);

		}
		retorno = 1;
	}

	return retorno;
}
