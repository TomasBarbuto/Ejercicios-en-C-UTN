#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Menu.h"
#include "Validaciones.h"

int main(){
	setbuf(stdout,NULL);

	int opcion;
	int ultimoId;
	int opcionListar;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
    		menuPrincipal();

    		if(!getNumber(&opcion, "\nOpcion: ","\nOpcion no valida, REINGRESE: ", 1, 11)){

    			printf("ERROR AL SELECCIONAR UNA OPCION\n");
    			system("pause");
    			break;
    		}

    		switch(opcion){

    		case 1:
    			//ANDUVO GOOD.
    				if(controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores)
    				&& controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)){

    					printf("Anduve bien");

    				}else{

    					printf("Se Rompio\n");
    				}
    			break;

    		case 2:
    			if(controller_agregarJugador(listaJugadores)){

    				printf("Se agrego un jugador\n");
    			}
    			break;

    		case 3:
    			if(controller_editarJugador(listaJugadores)){

    				printf("Se modifico un jugador\n\n");
    			}else{

    				printf("No ingreso un ID existente\nSera redirigido al menu principal\n\n");
    			}
    			system("pause");
    			break;

    		case 4:
    			if(controller_removerJugador(listaJugadores)){

    				printf("Se elimino un jugador\n");
    			}else{

    				printf("no elimine nada amigo\n");
    			}
    			break;

    		case 5:
    			if(getNumber(&opcionListar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 4)){

    				switch(opcionListar){

    				case 1:
						if(!controller_listarJugadores(listaJugadores)){

							printf("ERROR\n");
						}
						break;

    				case 2:
						if(!controller_listarSelecciones(listaSelecciones)){

							printf("ERROR\n");
						}
						break;

    				case 3:
    					if(!controller_ListarConvocados(listaJugadores)){

    						printf("ERROR\n");
    					}
    					break;

    				case 4:
    					break;
    				}
    			}else{

    				printf("ERROR\n");
    			}
    			break;

    		case 6:
    			controller_ConvocarJugadores(listaSelecciones, listaJugadores);

    			break;

    		case 7:

    			break;

    		case 8:
    			if(controller_guardarJugadoresModoBinario("jugadores.bin", listaJugadores)){

					printf("anduve bien en crear el .bin");

				}else{

					printf("Estoy en else");
				}
    			break;

    		case 9:
    			//se rompe revisar.
    			if(controller_cargarJugadoresDesdeBinario("jugadores.bin", listaJugadores)){

    				printf("anduvo bien el cargar\n");

    			}else{

    				printf("No existe tal archivo\n");

    			}
    			break;

    		case 10:
    			if(controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)==1){

    				printf("Se guardaron los cambios Correctamente Seleccion\n");
    			}else{

    				printf("Se rompio seleccion\n");
    			}
    			if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)==1){

    				printf("Se guardaron los cambios Correctamente Jugador\n");

    			}else{

    				printf("ERROR, llame al departamento de sistemas\n");
    			}

    			ultimoId = idAutoincremental()-1;

    			if(controller_guardarIdAutoincremental("ID.csv", ultimoId)){

    				printf("Se Guardaron todos los archivos correctamente\n");
    			}
    			break;
    		case 11:
    			break;
    		}

    	}while(opcion != 11);

    return 0;
}

