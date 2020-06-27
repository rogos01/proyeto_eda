#ifndef titulo_h
#define titulo_h
#include "struct.h"

void tituloPrincipal(){
	int i;
	printf("\n     ======================================================================\n");
	printf("\t\t\t\t    LIBRERIA\n");
    printf("\t     Gomez Soriano, Rodrigo\t\tFerrer Trejo, Johan Ariel\n");
    printf("\t\t     UNAM || Estructura de Datos y Algoritmos\n");
	printf("     ======================================================================\n");

	i = 0;
	putchar('\n');
	for (; i < 80; i++) {
		putchar('_');
	}
}

#endif