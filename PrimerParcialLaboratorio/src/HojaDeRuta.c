#include <stdio.h>
#include <stdlib.h>
#include "Transporte.h"
#include "Tipo.h"
#include "HojaDeRuta.h"
#include "Validaciones.h"

/**
*\brief: Otorga un ID autoincremental.
*\param: ---
*\return: Retorna el id autoincrementado.
**/
int idHojaDeRuta() {

	static int idHojaDeRuta = 20000;
	idHojaDeRuta++;

	return idHojaDeRuta;
}

/**
*\brief: Inicia el campo isEmpty del array de tipo hojaDeRuta en 0.
*\param: Array de tipo hojaDeRUTA, longitud del Array.
*\return: Retorna 1 si funciono y 0 si ocurre algun error.
**/
int inicializarHojaDeRuta(hojaDeRuta hojaRuta[], int len) {

	int retorno = 0;

	if (hojaRuta != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			hojaRuta[i].isEmpty = 0; //0 vacio 1 lleno.
		}

		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Recorre un array de tipo hojaDeRuta buscando algun espacio vacio. (isEmpty = 0)
*\param: Array de tipo hojaDeRuta, longitud del array.
*\return: Retorna el indice vacio  y -1 si no encontro.
**/
int buscarVacioHojaRuta(hojaDeRuta HojaRuta[], int len) {

	int retorno = -1;

	if (HojaRuta != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			if (HojaRuta[i].isEmpty == 0) {

				retorno = i; //ya encontre vacio, break.
				break;
			}

		}

	}

	return retorno;
}

/**
*\brief: Carga datos en el array de tipo hojaDeRuta.
*\param: Array de tipo hojaDeRuta, longitud del array.
*\return: Retorna 1 si encontro espacio y 0 si no encontro.
**/
int darAltaHojaDeRuta(hojaDeRuta HojaRuta[], transporte transportes[], int len, int lenT) {

	int retorno = 0;
	int confirm;
	int indice;
	int validacion;
	hojaDeRuta auxHojaRuta;

	if (HojaRuta != NULL && transportes != NULL && len > 0 && lenT > 0) {

		do {
			indice = buscarVacioHojaRuta(HojaRuta, len);

			if (indice != -1) {

				mostrarDatos(transportes, lenT);
				system("pause");

				getNumber(&auxHojaRuta.transporteId,
						"\nSeleccione un transporte por su ID: ",
						"Ese transporte no existe\n", 1000, 9999);

				validacion = buscarIdTransporte(transportes, lenT, auxHojaRuta.transporteId);

				if (validacion == 1) {

					auxHojaRuta.idHoja = idHojaDeRuta() - 1;

					getNumber(&auxHojaRuta.fecha.dia, "\nIngrese dia: ",
							"Fecha no valida", 1, 31);

					getNumber(&auxHojaRuta.fecha.mes, "\nIngrese mes: ",
							"Fecha no valida", 1, 12);

					getNumber(&auxHojaRuta.fecha.anio, "\nIngrese anio: ",
							"Fecha no valida", 1, 22);

					getFloat(&auxHojaRuta.kmsTotales,
							"\nIngrese cantidad de kilometros: ",
							"kilometros no validos\n", 50, 4000);

					getFloat(&auxHojaRuta.precioViaje,
							"\nIngrese el precio del viaje: ",
							"Precio No valido\n", 1000, 999999);

					auxHojaRuta.isEmpty = 1;

				}else{

					printf("\nEse ID no existe\n");
					system("pause");
				}

			}


		} while (validacion != 1);

		do{
			mostrarUnaHojaDeRUTA(auxHojaRuta);

			getNumber(&confirm,
					"\nIngrese 1 si su seleccion es correcta o 0 si desea volver a elegir\nOpcion: ",
					"\nOpcion no valida", 0, 1);
		}while(confirm != 1);

		HojaRuta[indice] = auxHojaRuta;
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Muestra los datos cargados en el array de tipo hojaDeRuta.
*\param: Array de tipo hojaDeRuta, longitud del array.
*\return: Retorna 1 si puede mostrar, Retorna 0 si ocurrio un error.
**/
int mostrarHojaDeRuta(hojaDeRuta HojaRuta[], int len) {

	int retorno = 0;

	if(HojaRuta != NULL && len > 0){
		for (int i = 0; i < len; i++) {

			if (HojaRuta[i].isEmpty == 1) {

				printf("\nid Hoja de ruta: %d\n", HojaRuta[i].idHoja);
				printf("id transporte: %d\n", HojaRuta[i].transporteId);
				printf("Kilometros: %.2f\n", HojaRuta[i].kmsTotales);
				printf("Precio de viaje: %.2f\n", HojaRuta[i].precioViaje);
				printf("fecha: %d / %d /%d \n", HojaRuta[i].fecha.dia,
						HojaRuta[i].fecha.mes, HojaRuta[i].fecha.anio);
			}

		}
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Muestra los campos de la variable de tipo hojaDeRuta.
*\param: Variable de tipo hojaDeRuta.
*\return: VOID
**/
void mostrarUnaHojaDeRUTA(hojaDeRuta HojaRuta){

		printf("\nID Hoja de ruta: %d\n", HojaRuta.idHoja);
		printf("ID transporte: %d\n", HojaRuta.transporteId);
		printf("Kilometros: %.2fKM\n", HojaRuta.kmsTotales);
		printf("Precio de viaje: $%.2f\n", HojaRuta.precioViaje);
		printf("fecha: %d / %d /%d \n", HojaRuta.fecha.dia, HojaRuta.fecha.mes,
				HojaRuta.fecha.anio);
}

/**
*\brief: Verifica que haya espacio para cargar un nuevo dato de tipo hojaDeRuta.
*\param: Array de tipo hojaDeRuta, Longitud del array.
*\return: Retorna 1 si encuentra espacio, Retorna 0 si no lo encuentra.
**/
int buscarEspacioHojaDeRuta(hojaDeRuta hojaRuta[], int len){

	int retorno = 0;

	if(hojaRuta != NULL && len > 0){
		for(int i = 0; i < len-1; i++){

			if(hojaRuta[i].isEmpty == 0){

				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
