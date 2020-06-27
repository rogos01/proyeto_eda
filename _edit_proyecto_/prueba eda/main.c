#include "insertar_archivo.h"
#include "struct.h"
#include "obtenerproducto.h"
#include "guardar_archivo.h"
#include "modificar_archivo.h"
#include "eliminar_archivo.h"
#include "eliminacion_defi.h"
#include "titulo.h"
#include "cadena.h"
#include "existe.h"
//#include "eliminarfisica.h"
#include "modificar.h"
#include "mostrar.h"
#include "eliminar.h"
#include  "buscar.h"
#include "insertar.h"
#include "admin5.h"
#include "admin.h"
#include "admin2.h"
#include "admin3.h"
#include "admin4.h"

#define MAX 100
#define VALOR_CENTINELA -1

void menuPrincipal();
void menuInsertar();
void menuBuscar();
void menuEliminar();
void menuMostrar();
void menuModificar();
//void menuEliminarFisica();

Producto *obtenerProductos(int *n);
char existeProducto(int codigoProducto, Producto *producto);
char insertarProducto(Producto producto);
char eliminarProducto(int codigoProducto);
char eliminacionFisica();
char modificarProducto(Producto producto);
char guardarReporte();

int leecad(char *cad, int n);

/* Titular del programa */
void tituloPrincipal();

char linea[MAX];

int main()
{
	setlocale(LC_ALL, "spanish"); //Permite imprimir caracteres con tilde
	menuPrincipal();

	return 0;
}

void menuPrincipal()
{
	char repite = 1;
	int opcion = -1;
	/* Cuando el usuario ingresa texto en lugar de ingresar una opcion. El programa no modifica
	el valor de opcion. En ese caso, no se debe de ingresar a ninguno de los case, por eso se esta
	inicializando la variable opcion con un valor que no permita ejecutar ningun case. Simplemente,
	volver a interar y pedir nuevamente la opcion. */

	do {
		system("cls");

		tituloPrincipal();

		printf("\n\t\t\t\tOPCIONES\n");
		printf("\n\t\t[1]. Agregar nuevo libro\n");
		printf("\t\t[2]. Mostrar inventario\n");
		printf("\t\t[3]. Eliminar un libro\n");
		printf("\t\t[4]. Buscar producto por ISBN\n");
		printf("\t\t[5]. Modificar un libro\n");
		printf("\t\t[7]. Salir\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");

		/* Lectura segura de un entero */
		leecad(linea, MAX);
		sscanf(linea, "%d", &opcion);

		switch (opcion) {

			case 1:
				admin();
				break;

			case 2:
				admin2();
				break;

			case 3:
				admin3();
				break;

			case 4:
				admin4();
				break;

			case 5:
				admin5();
				break;

			case 6:
				//menuEliminarFisica();
				
				break;

			case 7:
				repite = 0;
				break;
		}

	} while (repite);
}
