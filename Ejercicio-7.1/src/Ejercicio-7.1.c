/*
 Ejercicio 7-1:

 Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los
 siguientes datos:

 ● idProducto (numerico)
 ● descripcion (alfanumérico)
 ● nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 ● tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
 ● precio (numérico decimal)

 Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:

 i) ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
 disponible en el array.

 j) BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
 dejando espacio disponible para un nuevo producto.

 k) MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o
 el tipo.

 l) LISTADO Productos.
 m) LISTADO ordenado por precio.
 n) LISTADO ordenado por descripción.

 */

#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Struct.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int subOpcion;



	producto unProducto; // Con esto juego todo...

	do{
		printf("\tBienvenido al Menu de APPLE\n\n"
			   "¿Que accion desea realizar?\n\n"
			   "1-ALTA\n"
			   "2-BAJA\n"
			   "3-MODIFICAR\n"
			   "4-IMPRIMIR\n"
			   "5-Salir\n");

		getNumber(&opcion, "\nIngrese una opcion: ", "Opcion no valida\n", 1, 5);

		switch(opcion){

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:

			printf("\n\tBienvenido al SubMenu de Listas\n\n"
				   "¿Que desea Imprimir?\n\n"
				   "1-LISTADO Productos\n"
				   "2-LISTADO ordenado por precio\n"
				   "3-LISTADO ordenado por descripción\n"
				   "4-Salir\n");
			do{

			getNumber(&subOpcion, "\nIngrese una opcion: ", "Opcion no valida\n", 1, 5);

				switch(subOpcion){

				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					printf("Salio del submenu Listas\n\n"
						   "*******************************************************\n\n");
					system("pause");
					break;

				}

			}while(subOpcion != 4);

			break;

		case 5:
			printf("Usted a salido del MENU\n");
			break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}




