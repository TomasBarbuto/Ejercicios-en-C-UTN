/*
 Ejercicio 6-3:

 Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el
 apellido). Ninguna de las dos variables se puede modificar.
 Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:

 Por ejemplo:

 Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:

 	 Gomez, Juan Ignacio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout,NULL);

	char firstName[32];
	char lastName[32];
	char auxiliar[64];

	fgets(firstName, sizeof(firstName), stdin);
	fflush(stdin);

	fgets(lastName, sizeof(lastName), stdin);
	fflush(stdin);

		strncpy(auxiliar, lastName, strlen(lastName)-1);


		for(int i = 0; i < strlen(auxiliar); i++){

			if(auxiliar[i] == '\n'){

				auxiliar[i] = '\0';

			}
		}

		strcat(auxiliar, ", ");
		strcat(auxiliar, firstName);
		strlwr(auxiliar);

		for(int j = 0; j < strlen(auxiliar); j++){

			if(j == 0){

				auxiliar[j] = toupper(auxiliar[j]);
			}
			if(auxiliar[j] == ' '){

				auxiliar[j+1] = toupper(auxiliar[j+1]);

			}
		}

	//printf("%s",lastName);
	//printf("%s",firstName);
	//printf("%s",auxiliar);

	//strcpy(fullName, auxiliar);

	//printf("%s %s",firstName,lastName);
	printf("%s", auxiliar);

	return EXIT_SUCCESS;
}

