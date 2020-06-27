#ifndef insertar_h
#define insertar_h
#include "struct.h"
#include "cadena.h"
#include "existe.h"
#include "insertar_archivo.h"

void menuInsertar()
{
	Producto producto;
	int codigoProducto = 0;
	char repite = 1;
	char respuesta[MAX];

	do {
		system("cls");
		tituloPrincipal();
		printf("\n\t\t\t==> AGREGAR LIBRO <==\n");

		/* Se pide el c�digo del producto a insertar */
		printf("\n\tISBN del libro: ");
		leecad(linea, MAX);
		sscanf(linea, "%d", &codigoProducto);

		/* Se verifica que el producto no haya sido almacenado anteriormente */
		if (!existeProducto(codigoProducto, &producto)) {

			producto.codigo = codigoProducto;

			/* Se piden los dem�s datos del producto a insertar */
			printf("\tTitulo del libro: ");
			leecad(producto.nombre, MAX);

			printf("\tEditorial: ");
			leecad(producto.editorial, MAX);

			printf("\tCosto del libro ($): ");
			leecad(linea, MAX);
			sscanf(linea, "%f", &producto.costo);

			printf("\tPrecio del libro ($): ");
			leecad(linea, MAX);
			sscanf(linea, "%f", &producto.precio);

			printf("\tCantidad: ");
			leecad(linea, MAX);
			sscanf(linea, "%d", &producto.cantidad);

			/* Se inserta el producto en el archivo */
			if (insertarProducto(producto)) {
				printf("\n\tEl libro fue agregado correctamente\n");

			} else {
				printf("\n\tOcurri� un error al intentar agregar el libro\n");
				printf("\tInt�ntelo mas tarde\n");
			}
		} else {
			/* El producto ya existe, no puede ser insertado. */
			printf("\n\tEl libro de ISBN %d ya existe.\n", codigoProducto);
			printf("\tNo puede ingresar dos libros distintos con el mismo ISBN.\n");
		}

		printf("\n\tDesea seguir agregando libros? [S/N]: ");
		leecad(respuesta, MAX);

		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite);
}


#endif
