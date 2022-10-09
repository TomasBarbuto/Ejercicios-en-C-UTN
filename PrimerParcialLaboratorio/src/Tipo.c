#include <stdio.h>
#include "Tipo.h"
#include <string.h>

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

int listTipos(tipo tipos[], int len) {

	int retorno = 0;

	if (tipos != NULL && len > 0) {

		printf("Los Tipos actuales son: \n");

		for (int i = 0; i < len; i++) {

			printf("ID: %d, %s\n", tipos[i].idTipo, tipos[i].descripcion);

		}
		retorno = 1;
	}

	return retorno;
}
