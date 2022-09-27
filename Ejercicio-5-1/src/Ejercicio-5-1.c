/*
 Armar un Menú de Opciones con las siguientes opciones

 1-Inicializar
 2-Cargar
 3-Mostrar
 4-Calcular Promedio
 5-Ordenar

 Al ingresar a cada opción del menú deberá imprimir en pantalla el nombre del mismo. Ej: Si se
 presiona la opción 1 mostrar por pantalla “Ud. ha seleccionado lo opción 1-Inicializar”
 */

#include <stdio.h>
#include <stdlib.h>
#include "Mostrar.h"
#include "Validaciones.h"
#include "Arrays.h"
#include "Calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int arrayNumeros[5];
	int sumaTotal;
	float promedio;

	do {

		mostrarMenu(&opcion);


		switch (opcion) {

				case 1:
					printf("Ud. ha seleccionado lo opción 1-Inicializar\n");
					inicializarArraysAleatorio(arrayNumeros, 5);
					system("pause");
					break;

				case 2:
					printf("Ud. ha seleccionado lo opción 2-Cargar\n");
					inicializarArrays(arrayNumeros, 5);
					system("pause");
					break;

				case 3:
					printf("Ud. ha seleccionado lo opción  3-Mostrar\n");
					mostrarSubMenu(arrayNumeros);
					system("pause");
					break;

				case 4:
					printf("Ud. ha seleccionado lo opción 4-Calcular Promedio\n");

					sumarArrays(arrayNumeros, 5, &sumaTotal);

					calcularPromedio(&promedio, 5, sumaTotal);

					printf("El promedio de la suma de los indices es: '%.2f'\n", promedio);
					system("pause");

					break;

				case 5:
					printf("Ud. ha seleccionado lo opción 5-Ordenar\n");
					ordenarArray(arrayNumeros, 5);
					system("pause");

					imprimirArray(arrayNumeros, 5);
					system("pause");
					break;

				case 6:
					printf("Usted a salido del menu");
					break;
				}

	} while (opcion != 6);

	return 0;
}
