/*
 * Informes.h
 *
 *  Created on: 12 oct. 2022
 *      Author: barbu
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int mostrarTransportesPorTipo(transporte transportes[], int len);
int mostrarHojasDeRutaPorFecha(hojaDeRuta hojaRuta[], int len);
int importePorTransporte(hojaDeRuta hojaRuta[], transporte transportes[], int len,int lenT, float *precioTotal);
int importePorTipoyFecha(transporte transportes[], hojaDeRuta hojaRuta[], tipo tipos[], int len, int lenT,
		float* precioTotal);

#endif /* INFORMES_H_ */
