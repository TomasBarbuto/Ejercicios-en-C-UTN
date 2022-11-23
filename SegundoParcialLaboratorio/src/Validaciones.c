#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"


/**
 * \brief :
 * \param :
 * \return:
**/
int esUnNumero(char cadena[]){

	int retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		if(cadena[strlen(cadena)] == '\n'){

			cadena[strlen(cadena)] = '\0';
		}

		for (int i = 0; i < strlen(cadena); i++) {

			if (cadena[i] < '0' || cadena[i] > '9') {

				retorno = 1;
				break;
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
int getNumero(int *pResultado) {

	int retorno = 0;
	char buffer[1024];

	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);

	if (esUnNumero(buffer)) {

		*pResultado = atoi(buffer);
		retorno = 1;

	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno;
	int numero;

	while (reintentos > 0) {

		printf("%s", mensaje);

		if (getNumero(&numero)) {

			if (numero <= maximo && numero >= minimo){

				break;
			}
		}
		reintentos--;
		printf("%s", mensajeError);
	}

	if (reintentos == 0) {

		retorno = 0;

	}else{

		retorno = 1;
		*pResultado = numero;
	}
	return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){

	int ret;
	int num;
	while (reintentos > 0) {
		printf("%s", mensaje);
		if (getInt(&num) == 1) {
			if (num <= maximo && num >= minimo) {
				break;
			}
		}
		reintentos--;
		printf("%s", mensajeError);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) && esFlotante(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int esFlotante(char *cadena) {
	int i = 0;
	int retorno = 1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				} else {
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
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
							float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = 0;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {

			if (bufferFloat >= minimo && bufferFloat <= maximo) {

				*pResultado = bufferFloat;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int getString(char *cadena, int longitud) {
	int retorno = 0;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0) {
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
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
int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer)) &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
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
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = 0;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int getInt(int *pResultado) {

	int retorno = 0;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esNumerica(buffer)) {

		*pResultado = atoi(buffer);
		retorno = 1;

	}
	return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int esNumerica(char cadena[]){

	int retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		for (int i = 0; i < strlen(cadena); i++) {

			if (cadena[i] < '0' || cadena[i] > '9') {

				retorno = 1;
				break;
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
int isValidDNI(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int getStringg(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int utn_getTarjetaDeCredito(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{

    int retorno=0;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getStringg(msg,msgError,minSize,maxSize,&reintentos,bufferStr)&&isValidDNI(bufferStr)==1) //==0 sin errores !0
            {
                strncpy(input,bufferStr,maxSize);
                retorno = 1;
                break;
            }
            else
            {
                printf("%s 2",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
