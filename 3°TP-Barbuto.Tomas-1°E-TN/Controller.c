#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_cargarJugadoresDesdeTexto(char* path, LinkedList* pArrayListJugador){

	int retorno;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			printf("entre a p!=NULL\n");

			if(parser_JugadorFromText(pArchivo, pArrayListJugador)){

				printf("anduvo el parser\n");
				retorno = 1;

			}else{
				printf("No anduvo el parser\n");
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador){

	int retorno;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL){

			if(parser_JugadorFromBinary(pArchivo, pArrayListJugador)){

				retorno = 1;

			}else{

				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Alta de jugadores
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_agregarJugador(LinkedList* pArrayListJugador){

	    Jugador* NuevoJugador;
		int retorno = 0;
		int auxId;
		char auxNombreCompleto[100];
		int auxEdad;
		char auxPosicion[30];
		char auxNacionalidad[30];
		int auxIdSeleccion = 0;

		if(getString(auxNombreCompleto,"\nIngrese Nombre: ", "\nError reingrese: ", 100) &&
		   getNumber(&auxEdad, "\nIngrese Edad: ", "\nError reingrese: ", 16, 45) &&
		   getString(auxNacionalidad,"\nIngrese Nacionalidad: ", "\nError reingrese: ", 30) &&
	       getString(auxPosicion,"\nIngrese Posicion: ", "\nError reingrese: ", 30)){

			 auxId = idAutoincremental();

			 NuevoJugador = jug_new();

			 if(NuevoJugador != NULL){

				if(jug_setId(NuevoJugador, auxId)
				&& jug_setNombreCompleto(NuevoJugador, auxNombreCompleto)
				&& jug_setEdad(NuevoJugador, auxEdad)
				&& jug_setPosicion(NuevoJugador, auxPosicion)
				&& jug_setNacionalidad(NuevoJugador, auxNacionalidad)
				&& jug_setIdSeleccion(NuevoJugador, auxIdSeleccion)){


					if(ll_add(pArrayListJugador, NuevoJugador) == 0){

						retorno = 1;
					}
				}
			 }else{

				 jug_delete(NuevoJugador);
			 }
		}
		return retorno;
}


/** \brief Modificar datos del jugador
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Baja del jugador
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_listarJugadores(LinkedList* pArrayListJugador){

	int retorno = 0;
	Jugador* Jugadores = NULL;

	if(pArrayListJugador != NULL){

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			Jugadores = ll_get(pArrayListJugador, i);

			if(Jugadores != NULL){

				if(!imprimirJugador(pArrayListJugador, i)){

					retorno = 0;
					break;
				}
				retorno = 1;
			}
		}
	}

	return retorno;
}

/** \brief Ordenar jugadores
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_guardarJugadoresModoTexto(char* path, LinkedList* pArrayListJugador){

	int retorno = 0;
	FILE* pArchivo;
	int longitud; //longitud de linkedList
	Jugador *auxJugador;
	//Campos de struct Jugador.
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){

			longitud = ll_len(pArrayListJugador);
			fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			for(int i = 0; i < longitud ; i++){

				auxJugador = ll_get(pArrayListJugador, i);

				if(auxJugador != NULL){

					if(jug_getId(auxJugador, &auxId)
					&& jug_getNombreCompleto(auxJugador, auxNombreCompleto)
					&& jug_getEdad(auxJugador, &auxEdad)
					&& jug_getPosicion(auxJugador, auxPosicion)
					&& jug_getNacionalidad(auxJugador, auxNacionalidad)
					&& jug_getIdSeleccion(auxJugador, &auxIdSeleccion)){

						//retorna numero de bytes escritos.
						fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n" , auxId, auxNombreCompleto, auxEdad, auxPosicion,
								auxNacionalidad, auxIdSeleccion);//Escribe el archivo.
					}
				}
			}

			retorno = 1;
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador){

	int retorno = 0;
	FILE* pArchivo;
	int longitud;
	Jugador* auxJugador;
	int retornoFwrite;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL){

			longitud = ll_len(pArrayListJugador);

			for(int i = 0; i < longitud ; i++){

				auxJugador = ll_get(pArrayListJugador, i);

				if(auxJugador != NULL){

					//Retorna el número de elementos completos que escribe la función
					retornoFwrite = fwrite(auxJugador, sizeof(Jugador), 1, pArchivo);

					if(retornoFwrite == 1){

						retorno = 1;

					}else{

						break;
					}
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion){

	int retorno;
	FILE* pArchivo;

	if(path != NULL && pArrayListSeleccion != NULL){

		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			printf("entre a p!=Null\n");
			if(parser_SeleccionFromText(pArchivo, pArrayListSeleccion)){
				printf("anduvo el parser\n");
				retorno = 1;

			}else{
				printf("No anduvo el parser\n");
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}


/** \brief Modificar datos de empleado
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_listarSelecciones(LinkedList* pArrayListSeleccion){

	int retorno = 0;
	Seleccion* selecciones = NULL;

	if(pArrayListSeleccion != NULL){

		for(int i = 0; i < ll_len(pArrayListSeleccion); i++){

			selecciones = (Seleccion*) ll_get(pArrayListSeleccion, i);


			if(selecciones != NULL){

				if(!imprimirSeleccion(pArrayListSeleccion, i)){

					retorno = 0;
					break;
				}
				retorno = 1;
			}
		}
	}

	return retorno;
}

/** \brief Ordenar selecciones
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion){

	int retorno = 0;
	FILE* pArchivo;
	int longitud; //longitud de linkedList
	Seleccion *auxSelecion;
	//Campos de struct Jugador.
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	if(path != NULL && pArrayListSeleccion != NULL){

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){

			longitud = ll_len(pArrayListSeleccion);
			fprintf(pArchivo,"id,pais,confederacion,convocados\n");

			for(int i = 0; i < longitud ; i++){

				auxSelecion = ll_get(pArrayListSeleccion, i);

				if(auxSelecion != NULL){

					if(selec_getId(auxSelecion, &auxId)
					&& selec_getPais(auxSelecion, auxPais)
					&& selec_getConfederacion(auxSelecion, auxConfederacion)
					&& selec_getConvocados(auxSelecion, &auxConvocados)){

						//retorna numero de bytes escritos.
						fprintf(pArchivo, "%d,%s,%s,%d,\n" , auxId, auxPais, auxConfederacion, auxConvocados);//Escribe el archivo.
					}
				}
			}

			retorno = 1;
		}
		fclose(pArchivo);
	}
	return retorno;
}


