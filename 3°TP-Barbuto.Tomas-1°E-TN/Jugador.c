#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"

Jugador* jug_new(){

	Jugador *nuevoJugador = NULL;
	nuevoJugador = (Jugador *) malloc(sizeof(Jugador));

	if (nuevoJugador != NULL){

		jug_setId(nuevoJugador, 0);
		jug_setNombreCompleto(nuevoJugador, " ");
		jug_setEdad(nuevoJugador, 0);
		jug_setPosicion(nuevoJugador, " ");
		jug_setNacionalidad(nuevoJugador, " ");
		jug_setIdSeleccion(nuevoJugador, 0);
	}

	return nuevoJugador;
}




Jugador* jug_newParametros(char* idStr, char* nombreCompletoStr, char* edadStr, char* posicionStr,
						   char* nacionalidadStr, char* idSelccionStr){

	Jugador *nuevoJugador = jug_new();

	if(nuevoJugador != NULL){

	      if (!(jug_setId (nuevoJugador, atoi(idStr))
		    && jug_setNombreCompleto(nuevoJugador, nombreCompletoStr)
		    && jug_setEdad(nuevoJugador, atoi(edadStr))
			&& jug_setPosicion(nuevoJugador, posicionStr)
			&& jug_setNacionalidad(nuevoJugador, nacionalidadStr)
			&& jug_setIdSeleccion(nuevoJugador, atoi(idSelccionStr)))){

	    	  jug_delete(nuevoJugador);
	    	  nuevoJugador = NULL;	//INDICA FUNCION NO ANDUVO BIEN.
	      }
	}

	  return nuevoJugador;
}

///REVISAR
void jug_delete(Jugador *this){

	free(this);
}

///OK
int jug_setId(Jugador* this, int id){

	int retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

///OK
int jug_getId(Jugador* this, int* id){

	int retorno = 0;

	if (this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


///OK
int jug_setNombreCompleto(Jugador* this, char* nombreCompleto){

	int retorno = 0;

	if(this != NULL && nombreCompleto != NULL){

		strncpy(this->nombreCompleto, nombreCompleto, 100);
		retorno = 1;
	}

	return retorno;
}


int jug_getNombreCompleto(Jugador* this, char* nombreCompleto){

	int retorno = 0;

	if (this != NULL && nombreCompleto != NULL){

		strncpy(nombreCompleto, this->nombreCompleto, 100);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


///OK
int jug_setPosicion(Jugador* this, char* posicion){

	int retorno = 0;

	if(this != NULL && posicion != NULL){

		strncpy(this->posicion, posicion, 30);
		retorno = 1;
	}

	return retorno;
}

///OK
int jug_getPosicion(Jugador* this, char* posicion){

	int retorno = 0;

	if (this != NULL && posicion != NULL){

		strncpy(posicion, this->posicion, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


///OK
int jug_setNacionalidad(Jugador* this, char* nacionalidad){

	int retorno = 0;

	if(this != NULL && nacionalidad != NULL){

		strncpy(this->nacionalidad, nacionalidad, 30);
		retorno = 1;
	}

	return retorno;
}

///OK
int jug_getNacionalidad(Jugador* this, char* nacionalidad){

	int retorno = 0;

	if(this != NULL && nacionalidad != NULL){

		strncpy(nacionalidad, this->nacionalidad, 30);
		retorno = 1;
	}

	return retorno;
}


///OK
int jug_setEdad(Jugador* this, int edad){

	int retorno = 0;

	if(this != NULL && edad >= 16){

		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}


///OK
int jug_getEdad(Jugador* this, int* edad){

	int retorno = 0;

	if(this != NULL && edad != NULL){

		*edad = this->edad ;
		retorno = 1;
	}

	return retorno;
}


///OK
int jug_setIdSeleccion(Jugador* this, int idSeleccion){

	int retorno = 0;

	if(this != NULL && idSeleccion > 0){

		this->idSeleccion = idSeleccion;
		retorno = 1;
	}

	return retorno;
}


///OK
int jug_getIdSeleccion(Jugador* this, int* idSeleccion){

	int retorno = 0;

	if(this != NULL && idSeleccion != NULL){

		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}

	return retorno;
}
