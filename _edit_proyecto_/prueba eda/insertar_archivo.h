#ifndef insertar_arch_h
#define insertar_arch_h
#include "struct.h"

char insertarProducto(Producto producto)
{
	FILE *archivo;
	char insercion;

	/* Abre el archivo para agregar datos al final */
	archivo = fopen("productos.dat", "ab");	/* A�ade datos al final. Si el archivo no existe, es creado */

	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		insercion = 0;

	} else {
		fwrite(&producto, sizeof(producto), 1, archivo);
		insercion = 1;

		/* Cierra el archivo */
		fclose(archivo);
	}

	return insercion;
}

#endif