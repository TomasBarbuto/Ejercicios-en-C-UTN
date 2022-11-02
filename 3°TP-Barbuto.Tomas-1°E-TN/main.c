#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main(){
	setbuf(stdout,NULL);

    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{

    	//getnumber,
        switch(option){
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("Selecciones.csv", listaSelecciones);
                break;
            case 2:
            	controller_agregarJugador(listaJugadores);
            	break;
            case 3:
            	controller_editarJugador(listaJugadores);
            	break;
            case 4:
            	controller_removerJugador(listaJugadores);
            	break;

        }
    }while(option != 10);

    return 0;
}

