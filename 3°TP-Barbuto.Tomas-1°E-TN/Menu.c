#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


void menuPrincipal(){

	printf("\t\tBienvenido al Menu FIFA WORLD\n"
		   "\tSeleccione la opcion que desee:\n"
		   "1-CARGA DE ARCHIVOS\n"
		   "2-ALTA DE JUGADOR\n"
		   "3-MODIFICACIÓN DE JUGADOR\n"
		   "4-BAJA DE JUGADOR\n"
		   "5-LISTADOS\n"
		   "6-CONVOCAR JUGADORES\n"
		   "7-ORDENAR Y LISTAR:\n"
		   "8-GENERAR ARCHIVO BINARIO\n"
		   "9-CARGAR ARCHIVO BINARIO\n"
		   "10-GUARDAR ARCHIVOS .CSV\n"
		   "11-SALIR\n");
}

void menuModificar(){

	printf("Seleccione el campo a modificar\n"
		   "1-Nombre\n"
		   "2-Edad\n"
		   "3-Posicion\n"
		   "4-Nacionalidad\n"
		   "5-Salir\n");

}
