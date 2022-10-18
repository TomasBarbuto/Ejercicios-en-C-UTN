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

int iniciarTipos(tipo eTipos[]);
int listarTipos(tipo eTipos[], int longitud);


#endif /* TIPO_H_ */
