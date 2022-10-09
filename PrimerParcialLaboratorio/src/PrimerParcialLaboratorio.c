/*
 A. ALTA TRANSPORTE
 B. MODIFICAR TRANSPORTE: Se ingresará el idTransporte, permitiendo en un submenú modificar:
 ● pesoCarga
 ● cantidadBultos
 C. BAJA TRANSPORTE: Se ingresará el id del transporte y se realizará una baja lógica.
 D. LISTAR TRANSPORTES: Hacer un único listado de todos los transportes ordenados por tipo y por
 descripción.
 E. LISTAR TIPOS
 F. ALTA HOJA DE RUTA: Se dará de alta cada ocurrencia de la hoja de Ruta pidiéndole al usuario que
 elija un Transporte.
 G. LISTAR HOJAS DE RUTA
 H. INFORMES
 1- Mostrar transportes de un tipo seleccionado
 2- Mostrar todas las hojas de ruta efectuadas en una fecha seleccionada 3- Informar
 importe total de las hojas de ruta realizadas en un transporte seleccionado 4- Inf
 */

#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Tipo.h"
#include "Transporte.h"
#include "HojaDeRuta.h"

#define CANT_TRANSPORTE 5

int main(void) {
	setbuf(stdout, NULL);

	int opcion; //variable de control del menu.
	int flagListarTransportes = 0;
	int flagHojaDeRuta = 0;

	//declaramos las struct.
	transporte transportes[CANT_TRANSPORTE];
	tipo tipos[4];
	hojaDeRuta hojasRuta[CANT_TRANSPORTE];

	//inicializamos todas las struct.
	inicializarTransporte(transportes, CANT_TRANSPORTE); // le doy a todos los isEmpty valor 0.
	initTipos(tipos);
	inicializarHojaDeRuta(hojasRuta, CANT_TRANSPORTE);

	do {

		getNumber(&opcion, "\n\tBienvenido al Menu de transporte \n\n"
				"¿Que accion desea realizar?\n\n"
				"1-DAR DE ALTA\n"
				"2-MODIFICAR\n"
				"3-DAR DE BAJA\n"
				"4-LISTAR TRANSPORTES\n"
				"5-LISTAR TIPOS\n"
				"6-DAR DE ALTA HOJA DE RUTA\n"
				"7-INFORMES\n"
				"8-SALIR\n\nIngrese una opcion: ", "Opcion no valida\n", 1, 8);

		switch (opcion) {

		case 1:
			if(buscarEspacio(transportes, CANT_TRANSPORTE)){

				printf("Ya no hay espacios para mas transportes\n");
				system("pause");

			}else{

				darAltaTransporte(transportes, CANT_TRANSPORTE);
				flagListarTransportes = 1;
			}
			break;
		case 2:
			if(flagListarTransportes == 1){
				modificartransporte(transportes, CANT_TRANSPORTE);

			}else{

				printf("Todavia no se cargaron datos\n");
				system("pause");
			}
			break;

		case 3:
			if(flagListarTransportes == 1){
				darBajaTransporte(transportes, CANT_TRANSPORTE);

			}else{
				printf("Todavia no se cargaron datos\n");
				system("pause");
			}

			break;

		case 4:
			if(flagListarTransportes == 1){
				orderStructByID(transportes, CANT_TRANSPORTE);
				orderStructByDes(transportes, CANT_TRANSPORTE);
				mostrarDatos(transportes, CANT_TRANSPORTE);
			}else{
				printf("Todavia no se cargaron datos\n");
				system("pause");
			}
			break;

		case 5:
			listTipos(tipos, 4);
			system("pause");
			break;

		case 6:
			//mostrarDatos(transportes, CANT_TRANSPORTE);
			darAltaHojaDeRuta(hojasRuta, transportes, CANT_TRANSPORTE);
			flagHojaDeRuta = 1;

			break;

		case 7:
			if(flagHojaDeRuta == 1){
				mostrarHojaDeRuta(hojasRuta, CANT_TRANSPORTE);
			}else{
				printf("Todavia no se cargaron datos\n");
				system("pause");
			}
			break;

		case 8:
			break;

		case 9:
			getNumber(&opcion,
					"\nEsta seguro que desea salir del menu?\n\nIngrese 8 para confirmar...\n"
							"Ingrese 9 para continuar\nOPCION: ",
					"Opcion no valida\n", 8, 9);
			printf("Usted a salido del MENU\n");
			break;
		}

	} while (opcion != 9);

	return EXIT_SUCCESS;
}
