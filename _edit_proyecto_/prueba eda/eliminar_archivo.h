#ifndef eliminar_arch_h
#define eliminar_arch_h
#include "struct.h"

char eliminarProducto(int codigoProducto){
	FILE *archivo;
	FILE *auxiliar;
	Producto producto;
	char elimina;

	/* Abre el archivo para leer */
	archivo = fopen("productos.dat", "r+b");	/* Modo lectura/escritura. Si el archivo no existe, es creado */

	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		elimina = 0;

	} else {
		/* Se busca el registro que se quiere borrar. Cuando se encuentra, se sit�a en esa posici�n mediante la
		funci�n fseek y luego se modifica el campo clave de ese registro mediante alg�n valor centinela, eso se logra
		con fwrite. Hasta all� se ha logrado una eliminaci�n L�GICA. Porque el registro sigue ocupando espacio en el archivo f�sico */

		elimina = 0;
		fread(&producto, sizeof(producto), 1, archivo);
		while (!feof(archivo)) {
			if (producto.codigo == codigoProducto) {
				fseek(archivo, ftell(archivo) - sizeof(producto), SEEK_SET);
				producto.codigo = VALOR_CENTINELA;
				fwrite(&producto, sizeof(producto), 1, archivo);
				elimina = 1;
				break;
			}
			fread(&producto, sizeof(producto), 1, archivo);
		}

		/* Cierra el archivo */
		fclose(archivo);
	}
	return elimina;
}

#endif