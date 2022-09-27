#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Arrays.h"


/**
*\brief: muestra un menu de datos de cargar de jugadores de la seleccion argentina.
*\
*\param: 1 puntero a itn (key), 3 acumuladores printeados en un menu, contadores printeados a un menu
*\
*\return: VOID
*
*/
void mostrarMenu(int *pMenu){

	if(pMenu != NULL){


		printf("\nBievenido al menu\n"
						"1-Inicializar\n"
						"2-Cargar\n"
						"3-Mostrar\n"
						"4-Calcular Promedio\n"
						"5-Ordenar\n");

		getNumber(pMenu,"Opcion: " , "No ingreso un valor valido\n", 1, 6);


	}
}


/**
*\brief: Hace un print informando resultados obtenidos de atraves de distintos valores.
*\
*\param: 6 punteros a float de promedio, 1 puntero a un total, 1 puntero a recargo y un puntero a la suma de los ultimos dos.
*\
*\return: VOID
*
*/

void mostrarSubMenu(int arrayNumeros[]){

	int subOpcion;
	int index;

	do{

		getNumber(&subOpcion,"1-Imprimir Todas\n"
						   "2-Imprimir una edad\n"
						   "3-Salir\n", "Opcion no valida\n", 1, 3);

		switch(subOpcion){

		case 1:
			getNumber(&index, "Indique el ultimo indice", "No existe ese indice", 0, 5);
			imprimirArray(arrayNumeros, index);
			break;

		case 2:
			getNumber(&index, "Indique el indice", "No existe ese indice", 0, 4);
			printf("La edad en el index %d es: '%d'\n",index , arrayNumeros[index]);
			break;

		case 3:
			break;

		}

	}while(subOpcion != 3);

}

