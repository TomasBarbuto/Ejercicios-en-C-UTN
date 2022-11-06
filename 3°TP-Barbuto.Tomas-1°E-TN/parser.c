#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Controller.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile, LinkedList* pArrayListJugador){

	int retorno = 0;
	char auxId[100];
	char auxNombreCompleto[100];
	char auxEdad[100];
	char auxPosicion[100];
	char auxNacionalidad[100];
	char auxIdSeleccion[100];
	Jugador* pAuxJugador = NULL;
	int retornoVariable;

	if(pFile != NULL && pArrayListJugador != NULL){

		//fscanf lee el archivo.
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombreCompleto, auxEdad, auxPosicion,
				auxNacionalidad, auxIdSeleccion); //LECTURA FANTASMA

		do{

			retornoVariable = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombreCompleto, auxEdad,
									 auxPosicion, auxNacionalidad, auxIdSeleccion);

			if(retornoVariable == 6){

				pAuxJugador = jug_newParametros(auxId, auxNombreCompleto, auxEdad, auxPosicion,
														auxNacionalidad, auxIdSeleccion);
				if(pAuxJugador != NULL){

				  if(ll_add(pArrayListJugador, pAuxJugador) == 0){

					  retorno = 1;
				  }
				}

			}else{

				retorno = 0;
				break; //si no leyo 6 variables break. se rompe
			}

		}while(!feof(pFile));
	}

	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile, LinkedList* pArrayListJugador){

	int retorno = 0;
	int axuId;
	char auxNombreCompleto[100];
	int auxEdad;
	char axuPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	Jugador* pAuxJugador = NULL;
	int retornoVariable;

	if(pFile != NULL && pArrayListJugador != NULL){

		do{

			retornoVariable = fread(pAuxJugador, sizeof(Jugador), 1, pFile);

			if(retornoVariable == 1){

				if(jug_getId(pAuxJugador, &axuId)
				&& jug_getNombreCompleto(pAuxJugador, auxNombreCompleto)
				&& jug_getEdad(pAuxJugador, &auxEdad)
				&& jug_getPosicion(pAuxJugador, axuPosicion)
				&& jug_getNacionalidad(pAuxJugador, auxNacionalidad)
				&& jug_getIdSeleccion(pAuxJugador, &auxIdSeleccion)){

					//ACA LLAMO A LA FUNCION DONDE VA A PASAR ALGO...
					controller_cargarJugadoresDesdeBinario("Jugadores.bin", pArrayListJugador);

				}

			   retorno = 1;

			}else{

				retorno = 0;
				break; //si no leyo bien el archivo.
			}

		}while(!feof(pFile));
	}

	return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion){

	int retorno = 0;
	char auxId[100];
	char auxPais[100];
	char auxConfederacion[100];
	char auxConvocados[100];
	Seleccion* pAuxSeleccion;
	int retornoVariable;

	if(pFile != NULL && pArrayListSeleccion != NULL){

		//fscanf lee el archivo.
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxPais, auxConfederacion, auxConvocados); //LECTURA FANTASMA
		printf("entre a pfile!=null\n");
		do{

			retornoVariable = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxPais, auxConfederacion,
									 auxConvocados);

			if(retornoVariable == 4){
				printf("retorno var = 4\n");

				pAuxSeleccion = selec_newParametros(auxId, auxPais, auxConfederacion, auxConvocados);

				if(pAuxSeleccion != NULL){


				   if(ll_add(pArrayListSeleccion, pAuxSeleccion) == 0){

					   printf("ll_add\n");
				   }

				}
				retorno = 1;

			}else{
				printf("No lei 4 variables\n");
				retorno = 0;
				break; //si no leyo 4 variables break. se rompe
			}

		}while(!feof(pFile));
	}

	return retorno;
}

