#ifndef existe_h
#define existe_h
#include "struct.h"

char existeProducto(int codigoProducto, Producto *producto){
	FILE *archivo;
	char existe;
	/* Abre el archivo en modo lectura */
	archivo = fopen("productos.dat", "rb");
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		existe = 0;
	} else {
		existe = 0;
		/* Se busca el producto cuyo c�digo coincida con codigoProducto */
		fread(&(*producto), sizeof(*producto), 1, archivo);
		while (!feof(archivo)) {
			if ((*producto).codigo == codigoProducto) {
				existe = 1;
				break;
			}
			fread(&(*producto), sizeof(*producto), 1, archivo);
		}
		/* Cierra el archivo */
		fclose(archivo);
	}
	return existe;
}

#endif