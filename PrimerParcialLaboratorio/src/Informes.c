#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Tipo.h"
#include "Transporte.h"
#include "HojaDeRuta.h"

/**
*\brief: Muestra los datos de un array de tipo transporte cuando haya coincidencia.
*\param: Array de tipo transporte, Longitud del array.
*\return: Retorna 1 si puede mostrar, Retorna 0 si no encontro coincidencias.
**/
int mostrarTransportesPorTipo(transporte transportes[], int len){

	int retorno = 0;
	int tipoId;
	int contador = 0;

	if(transportes != NULL && len > 0){

		getNumber(&tipoId, "\nSeleccione el tipo de transporte que desea visualizar\n"
				"1000-CAMION RECTO\n"
				"1001-CAMION REMOLQUE\n"
				"1002-CAMION SEMIRREMOLQUE\n"
				"1003-CAMION ELEVADOR\n"
				"Seleccion: ", "Tipo inexistente", 1000, 1003);

		for(int i = 0; i < len -1; i++){

			if(tipoId == transportes[i].tipoId && transportes[i].isEmpty == 1){

				printf("\nEl transporte con ID: '%d' , es de del tipo seleccionado %d\n",
						transportes[i].idTransporte, tipoId);
				contador++;
			}
		}

		if(contador > 0){

			retorno = 1;

		}else{

			retorno = 0; // retorna 0 si no hay transporte con ese ID.
		}
	}

	return retorno;
}

/**
*\brief: Muestra los datos de un array de tipo hojaDeRuta cuando haya coincidencia con una fecha ingresada.
*\param: Array de tipo hojaDeRuta, Longitud del array.
*\return: Retorna 1 si puede mostrar, Retorna 0 si no encontro coincidencias.
**/
int mostrarHojasDeRutaPorFecha(hojaDeRuta hojaRuta[], int len) {

	int retorno = 0;
	fechas fecha;
	int contador = 0;

	if (hojaRuta != NULL && len > 0) {

		getNumber(&fecha.dia, "\nSeleccione el dia\nDIA: ", "Dia no valido", 1,
				31);

		getNumber(&fecha.mes, "\nSeleccione el mes\nMES: ", "Dia no valido", 1,
				12);

		getNumber(&fecha.anio, "\nSeleccione el anio\nANIO: ", "Dia no valido",
				1, 22);

		for (int i = 0; i < len - 1; i++) {

			if (fecha.dia == hojaRuta[i].fecha.dia
					&& fecha.mes == hojaRuta[i].fecha.mes
					&& fecha.anio == hojaRuta[i].fecha.anio
					&& hojaRuta[i].isEmpty == 1) {

				printf(
						"\nEn la fecha %d/%d/%d se dio de alta la hoja de ruta: %d\n",
						fecha.dia, fecha.mes, fecha.anio, hojaRuta[i].idHoja);
				contador++;
			}
		}

		if (contador > 0) {

			retorno = 1;

		} else {

			retorno = 0; // retorna 0 si no hay hojas en esa fecha con ese ID.
		}
	}

	return retorno;
}

/**
*\brief: Muestra un dato del array de tipo hojaDeRuta cuando encuentre coincidencia con un campo de transporte.
*\param: Array de tipo hojaDeRuta, Array de tipo transporte, Longitud de primer array, Longitud de segundo array
*\param: Puntero a flotante.
*\return: Retorna 1 si encuentra coincidencias, Retorna 0 si no encuentra coincidencias.
**/
int importePorTransporte(hojaDeRuta hojaRuta[], transporte transportes[],
		int len,int lenT, float *precioTotal) {

	int retorno = 0;
	int id;
	float acumulador = 0;

	if (hojaRuta != NULL && transportes != NULL && len > 0 && lenT > 0) {

		mostrarDatos(transportes, lenT);
		getNumber(&id, "Seleccione el transporte por ID\nSeleccion: ",
				"\nEse ID es inexistente", 1000, 9999);

		for (int i = 0; i < len - 1; i++) {

			if (id == hojaRuta[i].transporteId) {

				acumulador += hojaRuta[i].precioViaje;

			}
		}

		*precioTotal = acumulador;

		retorno = 1;
	}

	return retorno;
}

/**
*\brief:Muestra un dato(Precio) del array de tipo hojaDeRuta, cuando coincida con un campo(tipoID) de transporte.
*\param:Array de tipo hojaDeRuta, Array de tipo transporte, Longitud de primer array, Longitud de segundo array
*\param: Puntero a flotante.
*\return:Retorna 1 si encuentra coincidencias, Retorna 0 si no encuentra coincidencias.
**/
int importePorTipoyFecha(transporte transportes[], hojaDeRuta hojaRuta[], tipo tipos[], int len, int lenT,
		float* precioTotal) {

	int retorno = 0;
	float acumulador = 0;
	int tipo;
	fechas fecha;

	if (transportes != NULL && hojaRuta != NULL && tipos != NULL && len > 0 && lenT > 0) {

		listTipos(tipos, 4);

		getNumber(&tipo, "\nSeleccion un tipo de transporte\nTipo:",
				"\nEse tipo no existe\n", 1000, 1003);

		getNumber(&fecha.dia, "\nSeleccione el dia\nDIA: ", "Dia no valido", 1,
						31);

		getNumber(&fecha.mes, "\nSeleccione el mes\nMES: ", "Dia no valido", 1,
						12);

		getNumber(&fecha.anio, "\nSeleccione el anio\nANIO: ", "Dia no valido",
						1, 22);

		for (int i = 0; i < lenT - 1; i++) {
			for( int j = 0; j < len -1; j++){

				if(tipo == transportes[i].tipoId && transportes[i].idTransporte == hojaRuta[j].transporteId &&
					fecha.dia == hojaRuta[j].fecha.dia && fecha.mes == hojaRuta[j].fecha.mes
						&& fecha.anio == hojaRuta[j].fecha.anio){

					acumulador += hojaRuta[j].precioViaje;

				}
			}
		}

		*precioTotal = acumulador;

		retorno = 1;
	}

	return retorno;
}

