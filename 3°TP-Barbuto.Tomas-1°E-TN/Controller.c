#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Menu.h"
#include "Controller.h"


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
int controller_editarJugador(LinkedList* pArrayListJugador){

	int retorno = 0;
	int idBuscar;
	int indice;
	int opcion;
	char nuevoNombre[100];
	char nuevaPosicion[30];
	char nuevaNacionalidad[30];
	int nuevaEdad;
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL){

		if(controller_listarJugadores(pArrayListJugador)){

			if(getNumber(&idBuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1, 3000)){

				indice = validarExistenciaDeJugador(pArrayListJugador, idBuscar);

				if(indice != -1){

					auxJugador = ll_get(pArrayListJugador, indice);

					if(auxJugador != NULL){

						do{
							printf("|%10s | %25s | %10s | %20s | %10s  |\n", "ID", "NOMBRE JUGADOR", "EDAD",
																				   "POSICION", "NACIONALIDAD");

							imprimirJugador(pArrayListJugador, indice);
							menuModificar();
							if(!getNumber(&opcion,"\nOpcion: ", "\nOpcion no valida\nReingrese: ", 1, 5)){

								printf("Error\nSera Redirigido al menu principal\n");
							}
							switch(opcion){

							case 1:
								if(!getString(nuevoNombre, "\nIngrese el nuevo nombre: ",
										"\nSupero la cantidad de caracteres maximos\nReingrese: ", 100)){

									printf("ERROR\n");
								}
								if(!jug_setNombreCompleto(auxJugador, nuevoNombre)){

									printf("ERROR\n");
								}
								break;

							case 2:
								if(!getNumber(&nuevaEdad, "\nIngrese la nueva edad: ",
										"\nSu edad debe ser mayor a 16 y menor a 40", 16, 40)){

									printf("ERROR\n");
								}
								if(!jug_setEdad(auxJugador, nuevaEdad)){

									printf("ERROR\n");
								}
								break;
							case 3:
								if(!getString(nuevaPosicion, "\nIngrese nueva posicion: ",
										"\nSupero la cantidad de caracteres maximos\nReingrese: ", 30)){

									printf("ERROR\n");
								}
								if(!jug_setPosicion(auxJugador, nuevaPosicion)){

									printf("ERROR\n");
								}
								break;
							case 4:
								if(!getString(nuevaNacionalidad, "\nIngrese nueva Nacionalidad: ",
										"\nSupero la cantidad de caracteres maximos\nReingrese: ", 30)){

									printf("ERROR\n");
								}
								if(!jug_setNacionalidad(auxJugador, nuevaNacionalidad)){

									printf("ERROR\n");
								}
								break;

							case 5:
								printf("Salio del menu modificar\n");
								break;
							}

						}while(opcion != 5);

						retorno = 1;
					}
				}
			}
		}
	}

    return retorno;
}

/** \brief Baja del jugador
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
//Mandar un do while mas lindo.
int controller_removerJugador(LinkedList* pArrayListJugador){

	int retorno = 0;
	int indice;
	int idBuscar;
	int confirmar;
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL){

		if(controller_listarJugadores(pArrayListJugador)){

			if(getNumber(&idBuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1, 3000)){

				indice = validarExistenciaDeJugador(pArrayListJugador, idBuscar);

				if(indice != -1){

					if(imprimirJugador(pArrayListJugador, indice)&&
							getNumber(&confirmar, "Ingrese 1 para BORRAR o 0 para volver al menu principal\n",
									"\nOpcion no Valida\nReingrese: ", 0, 1)){

						if(confirmar == 1){

							jug_delete(auxJugador);
							if(ll_remove(pArrayListJugador, indice)==0){

								retorno = 1;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
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

		printf("|%10s | %25s | %10s | %20s | %10s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
																"POSICION", "NACIONALIDAD");

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

		printf("|%10s | %25s | %10s | %20s |\n", "ID", "CONFEDERACION", "CONVOCADOS", "PAIS");
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

//A) CONVOCAR: siempre y cuando el jugador no esté convocado en otra selección y la
//selección a donde será convocado no haya llegado a la cantidad máxima de
//convocados, se deberá asociar al jugador el id de la selección y en dicha selección
//se deberá aumentar el contador de convocados en 1. Al momento de tener que
//elegir qué dato ingresar se deberá mostrar un listado con las opciones disponibles.

int controller_ConvocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador){

	int retorno = -1;
	int idSeleccion;
	int buscarId;
	int indice;
	int indiceSeleccion;
	int convocados = 0;
	Jugador* auxJugador = NULL;
	Seleccion* auxSeleccion = NULL;

	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL){

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			auxJugador = ll_get(pArrayListJugador, i);

			jug_getIdSeleccion(auxJugador, &idSeleccion);

			if(idSeleccion == 0){

				imprimirJugador(pArrayListJugador, i);
			}
		}

		if(getNumber(&buscarId, "\nSeleccione el Jugador a convocar por su ID\n",
				"\nError Reingrese el ID: ", 1, 3000)){

			indice = validarExistenciaDeJugador(pArrayListJugador, buscarId);

			if(indice != -1){

				auxJugador = ll_get(pArrayListJugador, indice);
				printf("%d", auxJugador->idSeleccion);
				controller_listarSelecciones(pArrayListSeleccion);
				//------------------------------------------------------//

					if(getNumber(&idSeleccion, "\nIngrese a que seleccion sera convocado: ",
								"\nNo existe una seleccion con ese ID\nReingrese: ", 1, 32)){

						printf("pase el getNumber\n");

						indiceSeleccion = validarExistenciaDeSeleccion(pArrayListSeleccion, idSeleccion);

						auxSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);

						if(selec_getConvocados(auxSeleccion, &convocados)){

							printf("anduve bien el get convocados\n");
						}

						//auxSeleccion = ll_get(pArrayListSeleccion, idSeleccion);

							jug_setIdSeleccion(auxJugador, idSeleccion);
							convocados++;
							//Si selec da 0 retorna -1.
							if(selec_setConvocados(auxSeleccion, convocados)){

								printf("hice todo\n");
								retorno = 0;
							}else{
								retorno = -1;
							}

						printf("%d",auxJugador->idSeleccion);
					}
				}
			}
		}

	return retorno;
}

int controller_ListarConvocados(LinkedList* pArrayListJugador){

	int retorno = 0;
	Jugador* Jugadores = NULL;
	int convocado;

	if(pArrayListJugador != NULL){

		printf("|%10s | %25s | %10s | %20s | %10s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
																"POSICION", "NACIONALIDAD");

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			Jugadores = ll_get(pArrayListJugador, i);

			if(Jugadores != NULL){

				jug_getIdSeleccion(Jugadores, &convocado);

				if(convocado != 0){

					if(!imprimirJugador(pArrayListJugador, i)){

						retorno = 0;
						break;
					}
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}


int controller_cargarIdAutoincremental(char* path, char* auxid){

	FILE* pArchivo = NULL;
	int retornoFscanf;
	int retorno = 0;

	pArchivo = fopen(path, "r");

	if(path != NULL && auxid != NULL){

		if(pArchivo != NULL){

			retornoFscanf = fscanf(pArchivo, "%[^\n]\n", auxid);

			if(retornoFscanf == 1){

				printf("Se otorgo Su ID Correctamente\n");
			}else{

				printf("ERROR\n");
			}
			retorno = 1;
		}
		fclose(pArchivo);
	}

	return retorno;
}

int controller_guardarIdAutoincremental(char* path, int ultimoId){

	FILE* pArchivo = NULL;
	int retornoFprintf;
	int retorno = 0;

	if(path != NULL){

		pArchivo = fopen(path, "w");

		if (pArchivo != NULL){

			retornoFprintf = fprintf(pArchivo, "%d\n", ultimoId);

			if(retornoFprintf == sizeof(ultimoId)){

				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}



