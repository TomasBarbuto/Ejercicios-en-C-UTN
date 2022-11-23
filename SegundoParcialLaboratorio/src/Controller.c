#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concesionaria.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Controller.h"
#include "Menu.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_cargarArchivoVentasDesdeTexto(char* path, LinkedList* pArrayListJugador){

	int retorno;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){

			if(parser_ArchivoVentasFromText(pArchivo, pArrayListJugador)){

				retorno = 1;
			}else{

				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_CargarUnaVenta(LinkedList* pListaDeVentas){

	Venta* nuevaVenta;
	int retorno = 0;
	int id;
	int dia;
	int mes;
	int anio;
	char modeloDeAuto[200];
	int cantidadDeVentas;
	float precioDeAuto;
	char tarjetaDeCredito[17];

	if(pListaDeVentas != NULL){

		if(utn_getNumero(&dia, "Ingrese Dia de la venta: ", "ERROR, Reintente...\n", 1, 31, 5)
		&& utn_getNumero(&mes, "Ingrese Mes de la venta: ", "ERROR, Reintente...\n", 1, 12, 5)
		&& utn_getNumero(&anio, "Ingrese Año de la venta: ", "ERROR, Reintente...\n", 2020, 2022, 5)
		&& elegirModelo(modeloDeAuto)
		&& utn_getNumero(&cantidadDeVentas, "Ingrese Cantidad de ventas: ", "ERROR, Reintente...\n", 1, 25, 5)
		&& utn_getNumeroFlotante(&precioDeAuto, "Ingrese el precio de venta: ", "ERROR, Reintente...\n",
								2000000, 35000000, 5)
		&& utn_getTarjetaDeCredito("\nIngrese numeros frontales de tarjeta de credito: ","ERROR, Reintente...\n",
				16, 17, 5, tarjetaDeCredito)){

			 id = idAutoincremental();

			 nuevaVenta = newVenta();

			 if(nuevaVenta != NULL){

				if(setIdVenta(nuevaVenta, id)
				&& setDiaVenta(nuevaVenta, dia)
				&& setMesVenta(nuevaVenta, mes)
				&& setAnioVenta(nuevaVenta, anio)
				&& setModeloDeAuto(nuevaVenta, modeloDeAuto)
				&& setCantidadDeVentas(nuevaVenta, cantidadDeVentas)
				&& setPrecioDeAuto(nuevaVenta, precioDeAuto)
				&& setTarjetaDeCredito(nuevaVenta, tarjetaDeCredito)){


					if(ll_add(pListaDeVentas, nuevaVenta) == 0){

						retorno = 1;
					}else{

						retorno = 0;
					}
				}
			 }else{

				 deleteVenta(nuevaVenta);
			 }
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_removerVenta(LinkedList* pListaDeVentas){

	int retorno = 0;
	int indice;
	int idABuscar;
	int confirmar;
	int maximoId;
	Venta* auxVenta = NULL;


	if(pListaDeVentas != NULL){

		if(controller_listarVentas(pListaDeVentas)){

			maximoId = buscarIdMaximo(pListaDeVentas);

			if(utn_getNumero(&idABuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ",
							1, maximoId, 5)){


				indice = validarExistenciaDeVenta(pListaDeVentas, idABuscar);

				if(indice != -1){

					auxVenta = (Venta*) ll_get(pListaDeVentas, indice);
					printf("| %7s | %8s | %16s | %5s | %10s | %17s |\n", "ID_VENTA", "FECHA_VENTA", "MODELO",
							"CANTIDAD_VENTAS","PRECIO_UNITARIO", "TARJETA_CREDITO");
					if(imprimirVenta(pListaDeVentas, indice) &&
							utn_getNumero(&confirmar, "Ingrese 1 para BORRAR o 0 para volver al menu principal\n",
									"\nOpcion no Valida\nReingrese: ", 0, 1, 5) && auxVenta != NULL){

						if(confirmar == 1){

							deleteVenta(auxVenta);

							if(ll_remove(pListaDeVentas, indice) == 0){

								retorno = 1;
							}
						}else{

							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_modificarUnaVenta(LinkedList* pListaDeVentas){

	int retorno = 0;
	int maximoId;
	int idABuscar;
	int indice;
	int opcion;
	int cantidadDeVentas;
	float precioDeAuto;
	char tarjetaDeCredito[17];
	char modeloDeAuto[200];
	int contadorModificar = 0;
	Venta* auxVenta = NULL;

	if(pListaDeVentas != NULL){

		retorno = 1;
		if(controller_listarVentas(pListaDeVentas)){

			maximoId = buscarIdMaximo(pListaDeVentas);

			if(utn_getNumero(&idABuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID... \n", 1,
					maximoId, 5)){

				indice = validarExistenciaDeVenta(pListaDeVentas, idABuscar);

				if(indice != -1){

					auxVenta = (Venta*) ll_get(pListaDeVentas, indice);

					if(auxVenta != NULL){

						do{
							printf("| %7s | %8s | %16s | %5s | %10s | %17s |\n", "ID_VENTA", "FECHA_VENTA",
											"MODELO","CANTIDAD_VENTAS","PRECIO_UNITARIO", "TARJETA_CREDITO");

							if(!imprimirVenta(pListaDeVentas, indice)){

								retorno = 0;
								break;
							}

							menuModificar();
							if(utn_getNumero(&opcion,"\nOpcion: ", "\nOpcion no valida\nReingrese...", 1, 5, 5)){

								switch(opcion){

								case 1:
									if(utn_getNumero(&cantidadDeVentas, "\nIngrese Nueva cantidad de Ventas (1-25): ",
									"ERROR supero la cantidad de ventas posibles\n", 1, 25, 5)){

										if(!setCantidadDeVentas(auxVenta, cantidadDeVentas)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}else{
											contadorModificar++;
										}
									}
									break;

								case 2:
									if(utn_getNumeroFlotante(&precioDeAuto, "\nIngrese un nuevo precio unitario(2.000.000 - 35.000.000): ",
											"\nEl valor ingresado no corresponde al rango solicitado\n",
											2000000, 35000000, 5)){

										if(!setPrecioDeAuto(auxVenta, precioDeAuto)){

											printf("ERROR\n");
											retorno = 0;
											break;

										}else{
											contadorModificar++;
										}

									}
									break;
								case 3:
									if(elegirModelo(modeloDeAuto)){

										if(!setModeloDeAuto(auxVenta, modeloDeAuto)){

											printf("ERROR\n");
											retorno = 0;
											break;

										}else{
											contadorModificar++;
										}
									}
									break;
								case 4:
									if(utn_getTarjetaDeCredito("\nIngrese numeros frontales de tarjeta de credito(16): ",
											"ERROR, Reintente...\n", 16, 17, 5, tarjetaDeCredito)){

										if(!setTarjetaDeCredito(auxVenta, tarjetaDeCredito)){

											retorno = 0;
											break;

										}else{
											contadorModificar++;
										}
									}
									break;

								case 5:
									printf("Salio del menu modificar\n");
									break;
								}
							}
						}while(opcion != 5);
					}
				}

				if(contadorModificar == 0){

					retorno = 0;
				}
			}else{

				retorno = 0;
				printf("ERROR al seleccionar un ID\n");
			}
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_cargarIdAutoincremental(char* path, char* auxiliarID){

    int retorno = 0;
    FILE* pArchivo = NULL;

    pArchivo = fopen(path,"r");

    if(pArchivo != NULL){

        if(parser_ArchivoIdFromText(pArchivo, auxiliarID)){

            retorno = 1;
        }
    }
    return retorno;
}

/**
* \brief Guarda los datos del ultimo id en el archivo ID.csv (modo texto).
* \param path char*
* \param ultimoId int
* \return int
**/
int controller_guardarIdAutoincremental(char* path, int ultimoId){

	FILE* pArchivo = NULL;
	int retornoFprintf;
	int retorno = 0;

	if(path != NULL){

		pArchivo = fopen(path, "w");

		if (pArchivo != NULL){

			retornoFprintf = fprintf(pArchivo, "%d\n", ultimoId);

			if(retornoFprintf == sizeof(ultimoId)){

				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int validarExistenciaDeVenta(LinkedList* pListaVentas, int idParam){

	int retorno = -1;
	int idDeJugador;
	Venta* pVenta = NULL;

	if(pListaVentas != NULL){

		for(int i = 0; i < ll_len(pListaVentas); i++){

			pVenta = (Venta*) ll_get(pListaVentas, i);

			if(pVenta != NULL){

				if(getIdVenta(pVenta, &idDeJugador)){

					if(idDeJugador == idParam){

						retorno = ll_indexOf(pListaVentas, pVenta);
						break; //Retorno el index.
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int imprimirVenta(LinkedList* pListaDeVentas, int index){

	Venta* nuevaVenta;
	int retorno = 0;
	int id;
	int dia;
	int mes;
	int anio;
	char modeloDeAuto[200];
	int cantidadDeVentas;
	float precioDeAuto;
	char tarjetaDeCredito[17];

	if(pListaDeVentas != NULL && index >= 0 && index < ll_len(pListaDeVentas)){

		nuevaVenta = (Venta*)ll_get(pListaDeVentas, index);

		if(nuevaVenta != NULL){

			if(getIdVenta(nuevaVenta, &id) && getDiaVenta(nuevaVenta, &dia) && getMesVenta(nuevaVenta, &mes)
			&& getAnioVenta(nuevaVenta, &anio) && getModeloDeAuto(nuevaVenta, modeloDeAuto)
			&& getCantidadDeVentas(nuevaVenta, &cantidadDeVentas) && getPrecioDeAuto(nuevaVenta, &precioDeAuto)
			&& getTarjetaDeCredito(nuevaVenta, tarjetaDeCredito)){

				printf("| %8d | %2d/%2d/%5d | %16s | %15d | $%14.2f | %17s |\n", id, dia, mes,
							anio, modeloDeAuto, cantidadDeVentas, precioDeAuto, tarjetaDeCredito);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_listarVentas(LinkedList* pListaDeVentas){

	int retorno = 0;
	Venta* auxVenta = NULL;

	if(pListaDeVentas != NULL){
		retorno = 1;

		printf("| %7s | %8s | %16s | %5s | %10s | %17s |\n", "ID_VENTA", "FECHA_VENTA", "MODELO",
										"CANTIDAD_VENTAS","PRECIO_UNITARIO", "TARJETA_CREDITO");

		for(int i = 0; i < ll_len(pListaDeVentas); i++){

			auxVenta = (Venta*) ll_get(pListaDeVentas, i);

			if(auxVenta != NULL){

				if(!imprimirVenta(pListaDeVentas, i)){

					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_guardarVentasModoTexto(char* path, LinkedList* pListaDeVentas){

	int retorno = 0;
	FILE* pArchivo;
	int longitud; //longitud de linkedList
	Venta *auxVenta;
	//Campos de struct Venta
	int auxId;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxModeloDeAuto[200];
	int auxCantidadDeVentas;
	float auxPrecioDeAuto;
	char auxTarjetaDeCredito[17];

	if(path != NULL && pListaDeVentas != NULL){

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){

			longitud = ll_len(pListaDeVentas);

			fprintf(pArchivo, "ID_Venta,Fecha_Venta,Modelo_Auto,Cantidad,Precio_Unitario,Tarjeta_De_Credito\n");

			for(int i = 0; i < longitud ; i++){

				auxVenta = (Venta*)ll_get(pListaDeVentas, i);

				if(auxVenta != NULL){

					if(getIdVenta(auxVenta, &auxId)
					&& getDiaVenta(auxVenta, &auxDia)
					&& getMesVenta(auxVenta, &auxMes)
					&& getAnioVenta(auxVenta, &auxAnio)
					&& getModeloDeAuto(auxVenta, auxModeloDeAuto)
					&& getCantidadDeVentas(auxVenta, &auxCantidadDeVentas)
					&& getPrecioDeAuto(auxVenta, &auxPrecioDeAuto)
					&& getTarjetaDeCredito(auxVenta, auxTarjetaDeCredito)){

						fprintf(pArchivo, "%d,%d/%d/%d,%s,%d,%.2f,%s\n" , auxId, auxDia, auxMes,
						auxAnio, auxModeloDeAuto, auxCantidadDeVentas, auxPrecioDeAuto, auxTarjetaDeCredito);

						retorno = 1;
					}
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int controller_guardarVentasModoBinario(char* path , LinkedList* pListaDeVentas){

	int retorno = 0;
	FILE* pArchivo;
	Venta* auxVenta;
	int retornoFwrite;

	if(path != NULL && pListaDeVentas != NULL){

		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL){

			for(int i = 0; i < ll_len(pListaDeVentas) ; i++){

				auxVenta = (Venta*) ll_get(pListaDeVentas, i);

				if(auxVenta != NULL){

					//Retorna el número de elementos completos que escribe la función
					retornoFwrite = fwrite(auxVenta, sizeof(Venta), 1, pArchivo);

					if(retornoFwrite == 1){

						retorno = 1;

					}else{

						break;
					}
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int buscarIdMaximo(LinkedList* pListaDeVentas){

	int retorno = 0;
	int idMayor;
	int auxId;
	int flag = 0;
	int retornoId;
	Venta* auxVenta;

	if(pListaDeVentas != NULL){

		for(int i = 0; i < ll_len(pListaDeVentas); i++){

			auxVenta = ll_get(pListaDeVentas, i);

			if(auxVenta != NULL){

				if(getIdVenta(auxVenta, &auxId)){
					retorno = 1;
					if(flag == 0){

						idMayor = auxId;
						flag = 1;

					}else if(idMayor < auxId){

						idMayor = auxId;
					}
				}
			}
		}
	}
	if(retorno == 1){

		retornoId = idMayor;
	}

	return retornoId;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_contarVentasPorCriterio(LinkedList* pListaDeVentas, int* cantidadDeVentas,
						int* cantidadMayorASieteM, int* cantidadMayorAVeinteM, int* cantidadPorModeloQ7){

	int cantidadTotalDeVentas = 0;
	int cantidadTotalMayorASieteMillones = 0;
	int cantidadTotalMayorAVeinteMillones = 0;
	int cantidadDeVentasPorModeloQ7 = 0;
	int retorno = 0;
	int longitudLinkedList;

	longitudLinkedList = ll_len(pListaDeVentas);

	if(pListaDeVentas != NULL && longitudLinkedList >= 0){

		retorno = 1;

		cantidadTotalDeVentas = ll_count(pListaDeVentas, ventasDeUnidadesTotales);
		cantidadTotalMayorASieteMillones = ll_count(pListaDeVentas, ventasMayorASieteMillones);
		cantidadTotalMayorAVeinteMillones = ll_count(pListaDeVentas, ventasMayorAVeinteMillones);
		cantidadDeVentasPorModeloQ7 = ll_count(pListaDeVentas, ventasPorModeloQSiete);

		*cantidadDeVentas =  cantidadTotalDeVentas;
		*cantidadMayorASieteM = cantidadTotalMayorASieteMillones;
		*cantidadMayorAVeinteM = cantidadTotalMayorAVeinteMillones;
		*cantidadPorModeloQ7 = cantidadDeVentasPorModeloQ7;
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int controller_guardarInformeATexto(char* path, LinkedList* pListaDeVentas){

    FILE* pArchivo;
    int retorno = 0;
    int longitudLinkedList;
    int retornoFprintf;
    //Variables de escritura.
    int cantidadDeUnidadesVendidas;
    int cantidadDeUnidadesVendidasMayorASieteMillones;
    int cantidadUnidadesVendidasMayorAVeinteMillones;
    int cantidadVentaPorModeloQ7;

    if(path != NULL && pListaDeVentas != NULL){

    	longitudLinkedList = ll_len(pListaDeVentas);
    	pArchivo = fopen(path, "w");

    	if(pArchivo != NULL && longitudLinkedList >= 0){

			if(controller_contarVentasPorCriterio(pListaDeVentas ,  &cantidadDeUnidadesVendidas ,
			&cantidadDeUnidadesVendidasMayorASieteMillones, &cantidadUnidadesVendidasMayorAVeinteMillones,
			&cantidadVentaPorModeloQ7)){


				retornoFprintf = fprintf(pArchivo, "\n******************\nINFORMES DE VENTA\n******************\n");

				if(retornoFprintf > 0){

					fprintf(pArchivo, "\n-Cantidad de unidades vendidas totales: %d",cantidadDeUnidadesVendidas);
					fprintf(pArchivo, "\n-Cantidad de ventas por un monto mayor a $7000000: %d",cantidadDeUnidadesVendidasMayorASieteMillones);
					fprintf(pArchivo, "\n-Cantidad de ventas por un monto mayor a $20000000: %d",cantidadUnidadesVendidasMayorAVeinteMillones);
					fprintf(pArchivo, "\n-Cantidad de unidades vendidas para el modelo Q7: %d",cantidadVentaPorModeloQ7);

					fprintf(pArchivo, "\n\n******************");
					retorno = 1;
				}
			}
    	}
		fclose(pArchivo);
    }
    return retorno;
}
