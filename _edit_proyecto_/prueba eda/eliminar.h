#ifndef eliminar_h
#define eliminar_h
#include "struct.h"
#include "cadena.h"
#include "existe.h"
#include "eliminar_archivo.h"

void menuEliminar(){
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX];

	do {
		system("cls");
		tituloPrincipal();
		printf("\n\t\t\t==> ELIMINAR LIBRO POR ISBN <==\n");

		/* Se pide el c�digo del producto a eliminar */
		printf("\n\tISBN del libro: ");
		leecad(linea, MAX);
		sscanf(linea, "%d", &codigoProducto);

		/* Se verifica que el producto a buscar, exista */
		if (existeProducto(codigoProducto, &producto)) {

			/* Se muestran los datos del producto */
				printf("\n\tISBN del libro: %d\n", producto.codigo);
				printf("\n\tEditorial: %s\n", producto.editorial);
			printf("\tTItulo del libro: %s\n", producto.nombre);
			printf("\tCosto del libro: %.1f $\n", producto.costo);
			printf("\tPrecio del libro: %.1f $\n", producto.precio);
			printf("\tCantidad de libros: %d\n", producto.cantidad);


			printf("\n\tSeguro que desea eliminar el libro? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
				if (eliminarProducto(codigoProducto)) {
					printf("\n\tLibro eliminado satisfactoriamente.\n");
				} else {
					printf("\n\tEl libro no pudo ser eliminado\n");
				}
			}

		} else {
			/* El producto no existe */
			printf("\n\tEl libro de ISBN %d no existe.\n", codigoProducto);
		}

		printf("\n\tDesea eliminar algun otro libro? [S/N]: ");
		leecad(respuesta, MAX);

		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite);
}


#endif
