#ifndef MAIN_H // Guardia para evitar include circulares
#define MAIN_H
/* ------ Se hacen todos los includes necesarios ------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000
/* ------ Definición de tus estructuras ------ */
typedef struct word {
	char* s;
	int n;
} word;

/* ------ Definición de tus funciones ------ */
/*Imprime las instrucciones de uso del programa*/
void imprime_instrucciones();

#endif //MAIN_H