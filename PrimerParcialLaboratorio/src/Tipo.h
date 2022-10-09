/*
 * Tipo.h
 *
 *  Created on: 1 oct. 2022
 *      Author: barbu
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

	int idTipo;
	char descripcion[30];

}tipo;

int initTipos(tipo tipos[]);
int listTipos(tipo tipos[], int len);


#endif /* TIPO_H_ */
