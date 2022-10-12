#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Transporte.h"
#include "Validaciones.h"
#include "Tipo.h"

/**
*\brief: Inicia el campo isempty del array de tipo transporte en 0.
*\param: Array de tipo transporte, longitud del Array.
*\return: Retorna 1 si funciono y 0 si ocurre algun error.
**/
int inicializarTransporte(transporte transportes[], int len) {

	int retorno = 0;

	if (transportes != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			transportes[i].isEmpty = 0; //0 vacio 1 lleno.
		}
		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Recorre un array de tipo transporte buscando algun espacio vacio. (isempty = 0)
*\param: Array de tipo transporte, longitud del array.
*\return: Retorna el indice vacio  y -1 si no encontro.
**/
int buscarVacio(transporte transportes[], int len) {

	int retorno = -1;

	if (transportes != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			if (transportes[i].isEmpty == 0) {

				retorno = i; //ya encontre vacio, break.
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief: Carga datos en el array de tipo transporte. y
*\param: Array de tipo transporte, longitud del array.
*\return: Retorna 1 si encontro espacio y 0 si no encontro.
**/
int darAltaTransporte(transporte transportes[], int len) {

	int retorno = 0;
	int indice;
	int confirm;
	transporte auxtransporte;

	if (transportes != NULL && len > 0) {

		do{
			indice = buscarVacio(transportes, len);

			if(indice != -1){

				auxtransporte.idTransporte = idTransportes()-1;

				getString(auxtransporte.descripcion, "\nIngrese descripcion: ",
						"Se paso de texto", 1024);

				getNumber(&auxtransporte.pesoCarga, "\nIngrese el pesoCarga: ",
						"Imposible llevar esos KG", 50, 100000);

				getNumber(&auxtransporte.cantidadBultos,
						"\nIngrese cantidadBultos:",
						"Imposible llevar esa cantidad de bultos", 1, 1000);

				getNumber(&auxtransporte.tipoId, "\nSeleccione tipo de transporte\n"
						"\n1000: 'CAMION RECTO'\n"
						"1001: 'CAMION REMOLQUE'\n"
						"1002: 'CAMION SEMIRREMOLQUE'\n"
						"1003: 'CAMION ELEVADOR'\nTIPO: ", "\nID No valido\n", 1000, 1003);

				auxtransporte.isEmpty = 1;

			}
			mostrarDato(auxtransporte);
			getNumber(&confirm, "\nIngrese 1 si los datos ingresados son correctos o 0 si desea volver a cargar\n"
					"Opcion: ", "\nNo ingreso algo valido\n",0 , 1);

		}while(confirm != 1);

		transportes[indice] = auxtransporte;
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Muestra los campos de la variable de tipo transporte.
*\param: Variable de tipo transporte.
*\return: VOID
**/
void mostrarDato(transporte transportes){

	printf("\nid transporte: %d\n", transportes.idTransporte);
	printf("descripcion: %s\n", transportes.descripcion);
	printf("pesoCarga: %d\n", transportes.pesoCarga);
	printf("cantidadBultos: %d\n", transportes.cantidadBultos);
}

/**
*\brief: Muestra los datos cargados en el array de tipo transporte.
*\param: Array de tipo transporte, longitud del array.
*\return: Retorna 1 si puede mostrar, Retorna 0 si ocurrio un error.
**/
int mostrarDatos(transporte transportes[], int len) {

	int retorno = 0;

	if(transportes != NULL && len > 0){

		for (int i = 0; i < len; i++) {

			if (transportes[i].isEmpty == 1) {

				printf("\nid transporte: %d\n", transportes[i].idTransporte);
				printf("descripcion: %s\n", transportes[i].descripcion);
				printf("pesoCarga: %d\n", transportes[i].pesoCarga);
				printf("cantidadBultos: %d\n", transportes[i].cantidadBultos);

				switch (transportes[i].tipoId) {

				case 1000:
					printf("tipo: %d 'CAMION RECTO'\n", transportes[i].tipoId);
					break;

				case 1001:
					printf("tipo: %d 'CAMION REMOLQUE'\n", transportes[i].tipoId);
					break;

				case 1002:
					printf("tipo: %d 'CAMION SEMIRREMOLQUE'\n", transportes[i].tipoId);
					break;

				case 1003:
					printf("tipo: %d 'CAMION ELEVADOR'\n", transportes[i].tipoId);
					break;
				}
			}
		}

		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Otorga un ID autoincremental.
*\param: ---
*\return: retorna el id autoincrementado.
**/
int idTransportes() {

	static int idTransporte = 1000;
	idTransporte++;

	return idTransporte;
}

/**
*\brief: Busca una coincidencia entre id y el array transportes.
*\param: Array de tipo transporte, logintud de tipo int, id de tipo int
*\return: retorna la posicion donde encontro la coincidencia, si no encuentra retorna -1.
**/
int buscarIdDeTransporte(transporte transportes[], int len, int id) {

	int retorno = -1;

	if (transportes != NULL && len > 0 && id > 0) {

		for (int i = 0; i < len; i++) {

			if (transportes[i].idTransporte == id) {

				retorno = i; //ya encontre el id, break.
				break;
			}

		}
	}

	return retorno;
}

/**
*\brief: Otorga la baja a un indice del array de tipo transporte.
*\param: Array de tipo transporte, longitud del array de tipo int.
*\return: Retorna 0 si fue exitoso, Retorna -1 si ocurrio un error.
**/
int darBajaTransporte(transporte transportes[], int len) {

	int retorno = -1;
	int id;
	int indice;

	if (transportes != NULL && len > 0) {

		printf("\nQue id quiere dar de baja?: ");

		listarTransportes(transportes, len);

		getNumber(&id, "\nNumero: ", "Numero no valido\nReingrese El ID", 1000,
				9999);
		indice = buscarIdDeTransporte(transportes, len, id);

		if (indice != -1) {

			transportes[indice].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

/**
*\brief: Muestra una lista del array de tipo transporte que esten activos.
*\param: Array de tipo transporte , Longitud del array.
*\return: Retorna 1 si pudo recorrer bien el array, Retorna 0 si hubo algun error.
**/
int listarTransportes(transporte transportes[], int len) {

	int retorno = 0;

	if (transportes != NULL && len > 0) {

		printf("Los transportes actuales son: \n");

		for (int i = 0; i < len; i++) {

			if (transportes[i].isEmpty == 1) {

				printf("ID: %d\n", transportes[i].idTransporte);
			}
		}
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Modifica valores de una variable de tipo transporte seleccionada.
*\param: Array de tipo transporte, Longitud del array.
*\return: Retorna 1 si se pudo modificar, Retorna 0 si no se logro.
**/
int modificartransporte(transporte transportes[], int len) {

	int retorno = 0;
	int id;
	int indice;
	int opcion;

	if (transportes != NULL && len > 0) {

		listarTransportes(transportes, len);
		getNumber(&id, "\nQue id quiere modificar: ", "\nEse transporte no existe\n", 1000, 9999);

		indice = buscarIdDeTransporte(transportes, len, id);

		if (indice == -1) {

			printf("No se encontro el ID seleccionado\n");
			system("pause");

		} else {

			getNumber(&opcion, "\n¿Que opcion desea modificar?\n"
					"1-PesoCarga\n"
					"2-CantidadBultos\n"
					"3-Ambos\n"
					"4-Volver\n"
					"opcion: ", "Opcion no valida", 1, 4);

			switch (opcion) {

			case 1:
				getNumber(&transportes[indice].pesoCarga, "\nIngrese nuevo peso de carga: ",
						"\nNo es posible lleva tanto peso\n", 50, 100000);
				break;

			case 2:
				getNumber(&transportes[indice].cantidadBultos, "\nIngrese nueva cantidad de bultos: ",
						  "\nNo es posible llevar tanta cantidad\n", 1, 1000);
				break;

			case 3:
				getNumber(&transportes[indice].pesoCarga, "\nIngrese nuevo peso de carga: ",
						  "\nNo es posible lleva tanto peso\n", 50, 1000);

				getNumber(&transportes[indice].cantidadBultos, "\nIngrese nueva cantidad de bultos: ",
						  "\nNo es posible llevar tanta cantidad\n", 1, 1000);
				break;

			}

		}
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Ordena un array de tipo transporte por su campo tipoID.
*\param: Array de tipo transporte, Longitud del array.
*\return: retorna 1 si se logro correctamente, retorna 0 si ocurrio algun error.
**/
int orderStructByID(transporte transportes[], int len) {

	int flagSwapId;
	int i;
	int retorno = 0;
	transporte buffer;

	if (transportes != NULL && len > 0) {

		do {
			flagSwapId = 0;

			for (i = 0; i < len - 1; i++) {

				if (transportes[i].tipoId > transportes[i + 1].tipoId) {

					flagSwapId = 1;
					buffer = transportes[i];
					transportes[i] = transportes[i + 1];
					transportes[i + 1] = buffer;

				}
			}

		} while (flagSwapId);

		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Ordena un array de tipo transporte por su campo descripcion.
*\param: Array de tipo transporte, Longitud del array.
*\return: Retorna 1 si tuvo exito, Retorna 0 si ocurrio un error.
**/
int orderStructByDes(transporte transportes[], int len){

	int retorno = 0;
	int flagSwapDes;
	transporte buffer;

	if(transportes != NULL && len > 0){

		do{
			flagSwapDes = 0;

			for(int i = 0; i < len -1; i++){

				if (transportes[i].tipoId == transportes[i+1].tipoId){

					if (strcmp(transportes[i].descripcion, transportes[i+1].descripcion) > 0) {

						flagSwapDes = 1;
						buffer = transportes[i];
						transportes[i] = transportes[i+1];
						transportes[i+1] = buffer;

					}
				}
			}

		}while(flagSwapDes);
		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Verifica que haya espacio para cargar un nuevo dato de tipo transporte.
*\param: Array de tipo transporte, Longitud del array.
*\return: Retorna 1 si encuentra espacio, Retorna 0 si no lo encuentra.
**/
int buscarEspacio(transporte transportes[], int len){

	int retorno = 0;

	if(transportes != NULL && len > 0){

		for(int i = 0; i < len-1; i++){

			if(transportes[i].isEmpty == 0){

				retorno = 1;
			}
		}
	}

	return retorno;
}

/**
*\brief: Recorre un array de tipo transporte y busca que coincida con el param id.
*\param: Array de tipo transporte, Longitud del array.
*\return: Retorna 1 si encontro coincidencia, Retorna 0 si no la hay.
**/
int buscarIdTransporte(transporte transportes[], int len, int id){

	int retorno = 0;

	if(transportes != NULL && len > 0){
		for(int i = 0; i < len-1; i++){

			if(transportes[i].idTransporte == id && transportes[i].isEmpty == 1){

				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

