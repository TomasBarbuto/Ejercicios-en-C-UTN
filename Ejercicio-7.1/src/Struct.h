/*
 * Struct.h
 *
 *  Created on: 28 sep. 2022
 *      Author: barbu
 */

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct{ //con esto creo la struct no le doy valores

		int idproducto;
		char descripcion[1024];
		int nacionalidad;
		int tipo;
		int precio;
		int isEmpty;

	} producto;

#endif /* STRUCT_H_ */
