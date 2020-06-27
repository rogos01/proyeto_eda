#ifndef modificar_h
#define modificar_h
#include "struct.h"
#include "cadena.h"
#include "existe.h"
#include "modificar_archivo.h"

void menuModificar(){
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX];

	do {
		system("cls");
		tituloPrincipal();
		printf("\n\t\t\t==> MODIFICAR LIBRO POR ISBN<==\n");

		/* Se pide el c�digo del producto a modificar */
		printf("\n\tISBN DEL LIBRO: ");
		leecad(linea, MAX);
		sscanf(linea, "%d", &codigoProducto);

		/* Se verifica que el producto a buscar exista */
		if (existeProducto(codigoProducto, &producto)) {

			/* Se muestran los datos del producto */
			printf("\n\tTitulo del libro: %s\n", producto.nombre);
			printf("\n\tEditorial: %s\n", producto.editorial);
			printf("\tCosto del libro ($): %.1f\n", producto.costo);
			printf("\tPrecio del libro ($): %.1f\n", producto.precio);
			printf("\tCantidad: %d\n", producto.cantidad);

			printf("\n\tElija los datos a modificar\n");

			/* Modificaci�n del nombre del producto */
			printf("\n\tTitulo actual: %s\n", producto.nombre);
			printf("\tDesea modificar el titulo? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				printf("\tNuevo nombre libro: ");
				leecad(producto.nombre, MAX);
			}

			/* Modificaci�n la editorial producto */
			printf("\n\tEditorial actual: %s\n", producto.editorial);
			printf("\tDesea modificar la editorial? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				printf("\tNueva editorial: ");
				leecad(producto.nombre, MAX);
			}

			/* Modificaci�n del costo del producto */
			printf("\n\tCosto actual: %.1f\n", producto.costo);
			printf("\tDesea modificar el costo? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				printf("\tNuevo costo: ");
				leecad(linea, MAX);
				sscanf(linea, "%f", &producto.costo);
			}

			/* Modificaci�n del precio del producto */
			printf("\n\tPrecio actual: %.1f\n", producto.precio);
			printf("\tDesea modificar el precio? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				printf("\tNuevo precio : ");
				leecad(linea, MAX);
				sscanf(linea, "%f", &producto.precio);
			}

			/* Modificaci�n de la cantidad del producto */
			printf("\n\tCantidad de libros actual: %d\n", producto.cantidad);
			printf("\tDesea modificar la cantidad? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				printf("\tNueva cantidad: ");
				leecad(linea, MAX);
				sscanf(linea, "%d", &producto.cantidad);
			}

			printf("\n\tEst� seguro que desea modificar los datos de este libro? [S/N]: ");
			leecad(respuesta, MAX);

			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				/* Se modifica el producto en el archivo */
				if (modificarProducto(producto)) {
					printf("\n\tLos datos del libro se actualizaron\n");

				} else {
					printf("\n\tOcurri� un error al intentar modificar el libro\n");
					printf("\tInt�ntelo mas tarde\n");
				}
			}
		} else {
			/* El producto no existe */
			printf("\n\tEl libro de ISBN %d no existe.\n", codigoProducto);
		}

		printf("\n\tDesea modificar los datos de  otro libro? [S/N]: ");
		leecad(respuesta, MAX);

		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite);
}


#endif
