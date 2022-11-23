#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concesionaria.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Controller.h"
#include "Menu.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int ultimoId;
	char confirmar[2];
	LinkedList* ventaConcesionaria = ll_newLinkedList();


	do{
		menuPrincipal();
		if(utn_getNumero(&opcion, "Opcion: ", "\nValor no valido Reingrese...\n", 1, 8, 5)){

			switch(opcion){

			case 1: 	//cargar archivo
				if(ll_isEmpty(ventaConcesionaria) == 1){

					if(controller_cargarArchivoVentasDesdeTexto("Ventas.csv", ventaConcesionaria)){

						printf("Los archivos se cargaron correctamente\n");

					}else{

						printf("Ocurrio un ERROR, llame a sistemas\n");
					}
				}else{

					printf("Los archivos ya se encuentran cargados...\n");
				}
				break;

			case 2:	//alta
				if(ll_isEmpty(ventaConcesionaria) == 0){

					if(controller_CargarUnaVenta(ventaConcesionaria)){

						printf("Se dio de alta la venta correctamente\n");
					}else{

						printf("Ocurrio un ERROR, llame a sistemas\n");
					}
				}else{

					printf("No se cargo el archivo donde registrar un alta\n");
				}
				break;

			case 3://baja
				if(ll_isEmpty(ventaConcesionaria) == 0){

					if(controller_removerVenta(ventaConcesionaria)){

						printf("Se dio de BAJA la venta correctamente\n");
					}else{

						printf("No se dio de baja nada\nSera redirigido al menu principal\n");
					}
				}else{

					printf("No existen ventas a remover...\n");
				}
				break;

			case 4:
				if(ll_isEmpty(ventaConcesionaria) == 0){

					if(controller_modificarUnaVenta(ventaConcesionaria)){

						printf("Se modifico Correctamente\n");
					}else{

						printf("No se realizaron modificaciones\n");
					}

				}else{

					printf("No existen ventas a modificar...\n");
				}
				break;

			case 5:	//guardar binario
				if(ll_isEmpty(ventaConcesionaria) == 0){

					if(controller_guardarVentasModoBinario("Ventas.bin", ventaConcesionaria)){

						printf("Los datos se Guardaron correctamente\n");
					}else{

						printf("Ocurrio un error y no se pudieron guardar los datos\n");
					}
				}else{

					printf("No hay datos cargados para guardar en el archivo\n");
				}
				break;

			case 6://guarda texto
				if(ll_isEmpty(ventaConcesionaria) == 0){

					ultimoId = buscarIdMaximo(ventaConcesionaria);

					if(controller_guardarVentasModoTexto("Ventas.csv", ventaConcesionaria)
					&& controller_guardarIdAutoincremental("ID.csv", ultimoId)){

						printf("Los datos se Guardaron correctamente\n");
					}else{

						printf("Ocurrio un error y no se pudieron guardar los datos\n");
					}
				}else{

					printf("No hay datos cargados para guardar en el archivo\n");
				}
				break;

			case 7://informes
				if(ll_isEmpty(ventaConcesionaria) == 0){

					if(controller_guardarInformeATexto("Informe.txt", ventaConcesionaria)){

						printf("\nSe creo el archivo con los informes correctamente\n");

					}else{

						printf("\nERROR al crear el archivo\n");
					}
				}else{

					printf("No hay datos cargados para generar un Informe\n");
				}
				break;
			case 8:		//salir
				if(!utn_getNombre(confirmar, 3, "\nIngrese 'Si' si desea finalizar el programa: ",
					"No ingreso algo correcto\nReintente....\n", 3)){

					printf("Demasiados intentos...\nSera redirigido al menu principal...\n");
					break;
				}
				break;
			}
		}else{

			printf("se acabaron los reintentos, por favor verifique que esta ingresando...\n");
		}

	}while(stricmp(confirmar, "Si") != 0);

	ll_deleteLinkedList(ventaConcesionaria);

	printf("\nEl programa ha Finalizado\n");

	return 0;
}
