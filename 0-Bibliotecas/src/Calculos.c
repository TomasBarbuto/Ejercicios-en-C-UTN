/*
 * Calculos.c
 *
 *  Created on: 15 sep. 2022
 *      Author: barbu
 */

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


