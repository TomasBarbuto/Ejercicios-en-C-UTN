#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"



Seleccion* selec_new(){

	Seleccion *nuevaSeleccion = NULL;
	nuevaSeleccion = (Seleccion *) malloc(sizeof(Seleccion));

	if (nuevaSeleccion != NULL){

		nuevaSeleccion->id = 0;
		strncpy(nuevaSeleccion->pais, " ", 30);
		strncpy(nuevaSeleccion->confederacion, " ", 30);
		nuevaSeleccion->convocados = 0;
	}

	return nuevaSeleccion;
}



Seleccion* selec_newParametros(char* idStr, char* paisStr, char* confederacionStr, char* convocadosStr){

	Seleccion *nuevaSeleccion = selec_new();

	if(nuevaSeleccion != NULL){

		if (!selec_setConvocados(nuevaSeleccion, atoi(convocadosStr))){

			selec_delete(nuevaSeleccion);
			nuevaSeleccion = NULL;	//INDICA FUNCION NO ANDUVO BIEN.
		}
	}

	return nuevaSeleccion;
}


void selec_delete(Seleccion *this){

	free(this);
}

int selec_getId(Seleccion* this, int* id){

	int retorno = 0;

	if (this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}
int selec_getPais(Seleccion* this, char* pais){

	int retorno = 0;

	if (this != NULL && pais != NULL){

		strncpy(pais, this->pais, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}
int selec_getConfederacion(Seleccion* this, char* confederacion){

	int retorno = 0;

	if (this != NULL && confederacion != NULL){

		strncpy(confederacion, this->pais, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}
int selec_getIsEmpty(Seleccion* this, int* isEmpty){

	int retorno = 0;

	if (this != NULL && isEmpty != NULL){

		*isEmpty = this->id;
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

int selec_setConvocados(Seleccion* this, int convocados){

	int retorno = 0;

	if(this != NULL && convocados > 0 && convocados <= 22){

		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this, int* convocados){


	int retorno = 0;

	if(this != NULL && convocados != NULL){

		*convocados = this->convocados;
		retorno = 1;
	}

	return retorno;
}




