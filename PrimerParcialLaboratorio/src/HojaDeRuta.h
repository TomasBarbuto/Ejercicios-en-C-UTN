/*
 * HojaDeRuta.h
 *
 *  Created on: 1 oct. 2022
 *      Author: barbu
 */

#ifndef HOJADERUTA_H_
#define HOJADERUTA_H_

typedef struct{

	int dia;
	int mes;
	int anio;

}fechas;


typedef struct{

	int idHoja; //(comienza en 20000)
	int transporteId; //(debe existir) Validar
	float precioViaje;
	float kmsTotales;
	fechas fecha;
	int isEmpty;

}hojaDeRuta;

int idHojaDeRuta();
int inicializarHojaDeRuta(hojaDeRuta eHojasDeRuta[], int longitud);
int buscarVacioHojasDeRuta(hojaDeRuta eeHojasDeRuta[], int longitud);
int buscarEspacioHojaDeRuta(hojaDeRuta eHojasDeRuta[], int longitud);
int darAltaHojaDeRuta(hojaDeRuta eHojasDeRuta[], transporte transportes[], int longitudHojasDeRuta, int longitudTransporte);
int mostrarHojaDeRuta(hojaDeRuta eHojasDeRuta[], int longitud);
void mostrarUnaHojaDeRUTA(hojaDeRuta eHojasDeRuta);

#endif /* HOJADERUTA_H_ */
