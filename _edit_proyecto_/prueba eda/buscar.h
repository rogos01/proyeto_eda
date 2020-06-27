#ifndef buscar_h
#define buscar_h
#include "struct.h"
#include "cadena.h"
#include "existe.h"

void menuBuscar()
{
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX];

	do {
		system("cls");
		tituloPrincipal();
		printf("\n\t\t\t==> BUSCAR LIBRO POR ISBN <==\n");

		/* Se pide el c�digo del producto a buscar */
		printf("\n\tISBN de libro: ");
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

		} else {
			/* El producto no existe */
			printf("\n\tEl libro con el ISBN %d no existe.\n", codigoProducto);
		}

		printf("\n\tDesea seguir buscando algun libro? [S/N]: ");
		leecad(respuesta, MAX);

		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite);
}


#endif
