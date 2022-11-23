/*
 * Controller.h
 *
 *  Created on: 16 nov. 2022
 *      Author: barbu
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_cargarArchivoVentasDesdeTexto(char* path, LinkedList* pArrayListJugador);
int controller_CargarUnaVenta(LinkedList* pListaDeVentas);
int controller_cargarIdAutoincremental(char* path, char* auxiliarID);
int controller_guardarIdAutoincremental(char* path, int ultimoId);
int controller_removerVenta(LinkedList* pListaDeVentas);
int controller_modificarUnaVenta(LinkedList* pListaDeVentas);
int validarExistenciaDeVenta(LinkedList* pListaVentas, int idParam);
int imprimirVenta(LinkedList* pListaDeVentas, int index);
int controller_listarVentas(LinkedList* pListaDeVentas);
int controller_guardarVentasModoTexto(char* path, LinkedList* pArrayListJugador);
int controller_guardarVentasModoBinario(char* path , LinkedList* pListaDeVentas);
int buscarIdMaximo(LinkedList* pListaDeVentas);
int controller_contarVentasPorCriterio(LinkedList* pListaDeVentas, int* cantidadDeVentas,
									int* cantidadMayorASieteM,int* cantidadMayorAVeinteM, int* cantidadPorModeloQ7);
int controller_guardarInformeATexto(char* path, LinkedList* pListaDeVentas);
#endif /* CONTROLLER_H_ */
