/*
 * Arrays.h
 *
 *  Created on: 24 sep. 2022
 *      Author: barbu
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

void inicializarArrays(int array[], int len);
void sumarArrays(int array[], int len, int* pResultado);
void imprimirArray(int array[], int len);
void esParArray(int array[], int len);
void esIndexPar(int array[], int len);
int ordenarArray(int array[], int len, int direccion);
int countRepeat(int array[], int len, int *count);
int inicializarArraysAleatorio(int array[], int len);

#endif /* ARRAYS_H_ */
