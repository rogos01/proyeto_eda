#include <string.h>
#include "node.h"
#include "mostrar.h"
#include "buscar_cod.h"
#include "borrar.h"
#include "leercad.h"
#include "insertar_lib.h"
#include "titulo.h"


#define MAX 100

void tituloPrincipal();
void insert_lib();
void mostrar();
void buscar_cod();
void borrar();
int leecad(char *cad, int n);

int main(){				//johan 15/06/2020
	int opc = 0;
	
	do{

		system("cls");
		tituloPrincipal();
		printf("\n\t\t\t\tOPCIONES\n");
		printf("\n\t\t[1]. Meter al carrito\n");
		printf("\t\t[2]. Mostar carrito\n");
		printf("\t\t[3]. Buscar libro por ISBN\n");
		printf("\t\t[4]. Eliminar del carrito\n");
		printf("\t\t[6]. Salir\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");
		scanf("%d", &opc);

		switch(opc){
			case 1:
				insert_lib();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				buscar_cod();
				break;
			case 4:
				borrar();
				break;
			case 6:
				break;
			default:
				printf("\n\n eleccion no reconocida \n\n");
		}
		system("pause>nul");
	}while(opc != 6);
	return 0;
}							//edit rodrigo 21/06/2020
