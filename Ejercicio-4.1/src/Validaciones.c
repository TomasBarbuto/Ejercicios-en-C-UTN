#include <stdio.h>
int validarFlotante(int numero, float* pResultado){

	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = numero;
		retorno = 0;
	}
	return retorno;
}

int validarNumeroPar (int numero, int* pResultado){

	int retorno = -1;

	if(pResultado != NULL){
		if(numero % 2 == 0){
			*pResultado = numero;
			retorno = 0;

		}else{

			retorno = -1;
		}
	}
	return retorno;
}

int validarEntero(int numero, int* pResultado){

	int retorno = -1;

		if(pResultado != NULL){
			*pResultado = numero;
			retorno = 0;
		}
		return retorno;
}

int validarRango (int numero){

	int retorno;

	if(numero > 0 && numero <= 10){

		retorno = numero;
	}else{

		retorno = -1;
	}

	return retorno;
}

int sumar1(int numero1, int numero2){

	int retorno;

	retorno = numero1 + numero2;

	return retorno;

}

int sumar2(void){

	int primerNumero;
	int segundoNumero;
	int resultadoSuma;

	printf("Ingrese primer numero para ser sumados: ");
	scanf("%d", &primerNumero);
	printf("Ingrese segundo numero para ser sumado: ");
	scanf("%d", &segundoNumero);

	resultadoSuma = primerNumero + segundoNumero;

	return resultadoSuma;
}

void sumar3(int numero1, int numero2){

	int resultado;

	resultado = numero1 + numero2;

	printf("El resultado se sumar3 es: %d", resultado);

}

void sumar4(void){

		int primerNumero;
		int segundoNumero;
		int resultadoSuma;

		printf("Ingrese primer numero para ser sumados: ");
		scanf("%d", &primerNumero);
		printf("Ingrese segundo numero para ser sumado: ");
		scanf("%d", &segundoNumero);

		resultadoSuma = primerNumero + segundoNumero;

		printf("El resultado se sumar4 es: %d", resultadoSuma);

}








