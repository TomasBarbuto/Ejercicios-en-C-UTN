
#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

typedef struct{

	int idTransporte;
	char descripcion[1024];
	int pesoCarga;
	int cantidadBultos;
	int tipoId;
	int isEmpty;

}transporte;


int idTransportes();
int inicializarTransporte(transporte transportes[], int len);
int buscarVacio(transporte transportes[], int len);
int darAltaTransporte(transporte transportes[], int len);
int buscarIdDeTransporte(transporte transportes[], int len, int id);
int darBajaTransporte(transporte transportes[], int len);
int mostrarDatos(transporte transportes[], int len);
void mostrarDato(transporte transportes);
int listarTransportes(transporte transportes[], int len);
int modificartransporte(transporte transportes[], int len);
int orderStructByID(transporte transportes[], int len);
int orderStructByDes(transporte transportes[], int len);
int buscarEspacio(transporte transportes[], int len);
int buscarIdTransporte(transporte transportes[], int len, int id);


#endif /* TRANSPORTE_H_ */
