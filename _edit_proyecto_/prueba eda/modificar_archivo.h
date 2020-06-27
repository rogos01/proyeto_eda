#ifndef modificar_arch_h
#define modificar_arch_h
#include "struct.h"

char modificarProducto(Producto producto){
	FILE *archivo;
	char modifica;
	Producto producto2;

	/* Abre el archivo para lectura/escritura */
	archivo = fopen("productos.dat", "rb+");

	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		modifica = 0;

	} else {
		modifica = 0;
		fread(&producto2, sizeof(producto2), 1, archivo);
		while (!feof(archivo)) {
			if (producto2.codigo == producto.codigo) {
				fseek(archivo, ftell(archivo) - sizeof(producto), SEEK_SET);
				fwrite(&producto, sizeof(producto), 1, archivo);
				modifica = 1;
				break;
			}
			fread(&producto2, sizeof(producto2), 1, archivo);
		}

		fclose(archivo);
	}

	/* Cierra el archivo */
	return modifica;
}

#endif