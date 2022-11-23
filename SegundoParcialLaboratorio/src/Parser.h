/*
 * Parser.h
 *
 *  Created on: 16 nov. 2022
 *      Author: barbu
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_ArchivoVentasFromText(FILE* pFile, LinkedList* pListaDeVentas);
int parser_ArchivoIdFromText(FILE* pFile , char* auxiliarID);
#endif /* PARSER_H_ */
