#ifndef eliminar_fisica_h
#define eliminar_fisica_h
#include "struct.h"
#include "eliminacion_defi.h"
#include "titulo.h"
#include "cadena.h"

void menuEliminarFisica(){
	char respuesta[MAX];


	system("cls");
	tituloPrincipal();
	printf("\n\t\t==> ELIMINAR FISICAMENTE REGISTROS DEL ARCHIVO <==\n");

	/* Se pide el c�digo del producto a eliminar */
	printf("\n\tSeguro que desea proceder con la eliminaci�n f�sica? [S/N]: ");
	leecad(respuesta, MAX);

	if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		if (eliminacionFisica()) {
			printf("\n\tLa eliminaci�n f�sica se realiz� con �xito.\n");
		} else {
			printf("\n\tOcurri� alg�n error en la eliminaci�n f�sica.\n");
		}

		system("pause>nul");
	}
}

#endif