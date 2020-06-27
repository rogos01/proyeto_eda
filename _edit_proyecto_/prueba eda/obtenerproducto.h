#ifndef obtener_h
#define obtener_h
#include "struct.h"

Producto *obtenerProductos(int *n)
{
	FILE *archivo;
	Producto producto;
	Producto *productos; /* Vector din�mico de productos */
	int i;

	/* Abre el archivo en modo lectura */
	archivo = fopen("productos.dat", "rb");

	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		*n = 0; /* No se pudo abrir. Se considera n  */
		productos = NULL;

	} else {

		fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
		*n = ftell(archivo) / sizeof(Producto); /* # de productos almacenados en el archivo. (# de registros) */
		productos = (Producto *)malloc((*n) * sizeof(Producto)); /* Se reserva memoria para todos los productos almacenados en el archivo */

		/* Se recorre el archivo secuencialmente */
		fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
		fread(&producto, sizeof(producto), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			productos[i++] = producto;
			fread(&producto, sizeof(producto), 1, archivo);
		}

		/* Cierra el archivo */
		fclose(archivo);
	}

	return productos;
}

#endif