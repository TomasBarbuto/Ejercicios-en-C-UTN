#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"



Seleccion* selec_new(){

	Seleccion *nuevaSeleccion = NULL;
	nuevaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	if (nuevaSeleccion != NULL){

		nuevaSeleccion->id = 0;
		strncpy(nuevaSeleccion->pais, " ", 30);
		strncpy(nuevaSeleccion->confederacion, " ", 30);
		selec_setConvocados(nuevaSeleccion, 0);

	}

	return nuevaSeleccion;
}



Seleccion* selec_newParametros(char* idStr, char* paisStr, char* confederacionStr, char* convocadosStr){

	Seleccion* nuevaSeleccion = selec_new();

	if(nuevaSeleccion != NULL){

		if (!(selec_setConvocados(nuevaSeleccion, atoi(convocadosStr)))){

			selec_delete(nuevaSeleccion);
			nuevaSeleccion = NULL;	//INDICA FUNCION NO ANDUVO BIEN.

		}else{

			nuevaSeleccion->id = atoi(idStr);
			strncpy(nuevaSeleccion->pais, paisStr, 30);
			strncpy(nuevaSeleccion->confederacion, confederacionStr, 30);


		}
	}

	return nuevaSeleccion;
}


void selec_delete(Seleccion *this){

	free(this);
}


///OK
int selec_getId(Seleccion* this, int* id){

	int retorno = 0;

	if (this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


///OK
int selec_getPais(Seleccion* this, char* pais){

	int retorno = 0;

	if (this != NULL && pais != NULL){

		strncpy(pais, this->pais, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

///OK
int selec_getConfederacion(Seleccion* this, char* confederacion){

	int retorno = 0;

	if (this != NULL && confederacion != NULL){

		strncpy(confederacion, this->pais, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

///OK
int selec_setConvocados(Seleccion* this, int convocados){

	int retorno = 0;

	if(this != NULL && convocados >= 0 && convocados <= 22){

		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}


///OK
int selec_getConvocados(Seleccion* this, int* convocados){

	int retorno = 0;

	if(this != NULL && convocados != NULL){

		*convocados = this->convocados;
		retorno = 1;
	}

	return retorno;
}

int imprimirSeleccion(LinkedList* pArrayListaSelecciones, int index){

	int retorno = 0;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	Seleccion* unaSeleccion = NULL;

	if(pArrayListaSelecciones != NULL && index >= 0 && index < ll_len(pArrayListaSelecciones)){

		unaSeleccion = ll_get(pArrayListaSelecciones, index);

		if(selec_getId(unaSeleccion, &auxId)
		&& selec_getConvocados(unaSeleccion, &auxConvocados)
		&& selec_getConfederacion(unaSeleccion, auxConfederacion)
		&& selec_getPais(unaSeleccion, auxPais)){

			printf("|%10d | %25s | %10d | %20s |\n", auxId, auxConfederacion, auxConvocados, auxPais);
			retorno = 1;
		}
	}

	return retorno;
}

int validarExistenciaDeSeleccion(LinkedList* pArrayListaSelecciones, int idParam){

	int retorno = -1;
	int idDeSeleccion;
	Seleccion* unaSeleccion = NULL;

	if(pArrayListaSelecciones != NULL){

		for(int i = 0; i < ll_len(pArrayListaSelecciones); i++){

			unaSeleccion = ll_get(pArrayListaSelecciones, i);

			if(selec_getId(unaSeleccion, &idDeSeleccion)){

				if(idDeSeleccion == idParam){

					retorno = ll_indexOf(pArrayListaSelecciones, unaSeleccion);
					break; //Retorno el index.
				}
			}
		}
	}

	return retorno;
}


