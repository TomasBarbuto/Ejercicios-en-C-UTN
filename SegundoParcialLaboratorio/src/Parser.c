#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "concesionaria.h"
#include "Controller.h"


/**
 * \brief :
 * \param :
 * \return:
**/
int parser_ArchivoVentasFromText(FILE* pFile, LinkedList* pListaDeVentas){

	int retorno = 0;
	char auxId[100];
	char auxFecha[100];
	char auxDia[10];
	char auxMes[10];
	char auxAnio[10];
	char auxModeloDeAuto[200];
	char auxCantidadDeVentas[100];
	char auxPrecioDeAuto[100];
	char auxTarjetaDeCredito[17];
	Venta* pVenta = NULL;
	int retornoVariable;

	if(pFile != NULL && pListaDeVentas != NULL){
		//fscanf lee el archivo.
		fscanf(pFile,  "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxFecha,
				auxModeloDeAuto, auxCantidadDeVentas, auxPrecioDeAuto, auxTarjetaDeCredito); //LECTURA FANTASMA

		do{
											 //id    dia  mes    anio modelo vent
			retornoVariable = fscanf(pFile, "%[^,],%[^/]/%[^/]/%[^,], %[^,],%[^,],%[^,],%[^\n]\n", auxId, auxDia,
					auxMes, auxAnio, auxModeloDeAuto, auxCantidadDeVentas, auxPrecioDeAuto, auxTarjetaDeCredito);
			if(retornoVariable == 8){

				pVenta = nuevaVentaParametros(auxId, auxDia, auxMes, auxAnio, auxModeloDeAuto, auxCantidadDeVentas,
											auxPrecioDeAuto, auxTarjetaDeCredito);

				if(pVenta != NULL && ll_add(pListaDeVentas, pVenta) == 0){

					retorno = 1;
				}

			}else{

				retorno = 0;
				break; //si no leyo 8 variables break. se rompe
			}

		}while(!feof(pFile));
	}

	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int parser_ArchivoIdFromText(FILE* pFile , char* auxiliarID){

	int retorno = 0;
	int retornoVariable;

	if(pFile != NULL && auxiliarID != NULL){

		retornoVariable = fscanf(pFile,"%[^\n]\n", auxiliarID);

		if(retornoVariable == 1){

			retorno = 1;
		}
	}
	return retorno;
}
