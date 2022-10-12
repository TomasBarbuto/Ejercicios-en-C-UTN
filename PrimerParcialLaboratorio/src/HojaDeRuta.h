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
int inicializarHojaDeRuta(hojaDeRuta hojaRuta[], int len);
int buscarVacioHojaRuta(hojaDeRuta HojaRuta[], int len);
int buscarEspacioHojaDeRuta(hojaDeRuta hojaRuta[], int len);
int darAltaHojaDeRuta(hojaDeRuta HojaRuta[], transporte transportes[], int len, int lenT);
int mostrarHojaDeRuta(hojaDeRuta HojaRuta[], int len);
void mostrarUnaHojaDeRUTA(hojaDeRuta HojaRuta);

#endif /* HOJADERUTA_H_ */
