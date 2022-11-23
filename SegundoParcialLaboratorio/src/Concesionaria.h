/*
 * Concesionaria.h
 *
 *  Created on: 16 nov. 2022
 *      Author: barbu
 */

#ifndef CONCESIONARIA_H_
#define CONCESIONARIA_H_

typedef struct{

	int dia;
	int mes;
	int anio;

}Fecha;

typedef struct{

	int id;
	Fecha fechaDeVenta;
	char modeloDeAuto[200];
	int cantidadDeVentas;
	float precioDeAuto;
	char tarjetaDeCredito[17];

}Venta;

Venta* newVenta();
Venta* nuevaVentaParametros(char* idVenta, char* dia, char* mes, char* anio, char* modeloDeAuto,
							char* cantidadDeVentas, char* precioDeAuto, char* tarjetaDeCredito);
void deleteVenta(Venta *this);

int setIdVenta(Venta* this, int id);
int getIdVenta(Venta* this, int* id);

int setDiaVenta(Venta* this, int dia);
int getDiaVenta(Venta* this, int* dia);

int setMesVenta(Venta* this, int mes);
int getMesVenta(Venta* this, int* mes);

int setAnioVenta(Venta* this, int anio);
int getAnioVenta(Venta* this, int* anio);

int setCantidadDeVentas(Venta* this, int cantidadDeVentas);
int getCantidadDeVentas(Venta* this, int* cantidadDeVentas);

int setPrecioDeAuto(Venta* this, float PrecioDeAuto);
int getPrecioDeAuto(Venta* this, float* precioDeAuto);

int setModeloDeAuto(Venta* this, char* modeloDeAuto);
int getModeloDeAuto(Venta* this, char* modeloDeAuto);

int setTarjetaDeCredito(Venta* this, char* tarjetaDeCredito);
int getTarjetaDeCredito(Venta* this, char* tarjetaDeCredito);

int elegirModelo(char pModeloElegido[]);
int idAutoincremental();
int ventasMayorASieteMillones(void* pElement);
int ventasMayorAVeinteMillones(void* pElement);
int ventasDeUnidadesTotales(void* pElement);
int ventasPorModeloQSiete(void* pElement);

#endif /* CONCESIONARIA_H_ */
