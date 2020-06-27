#ifndef guardar_h
#define guardar_h
#include "struct.h"
#include "obtenerproducto.h"

char guardarReporte(){
	FILE *archivo;
	char guardado;
	Producto *productos;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;

	productos = obtenerProductos(&numeroProductos); /* Retorna un vector din�mico de productos */

	if (numeroProductos == 0) {
		guardado = 0;

	} else {
		/* Abre el archivo en modo texto para escritura */
		archivo = fopen("reporte.txt", "w");

		if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
			guardado = 0;

		} else {
			fprintf(archivo, "\n\t\t    ==> LISTADO DE LIBROS <==\n");
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			fprintf(archivo, "%8s\t%-20s%15s%15s%10s\n", "ISBN", "TITULO", "Editorial", "COSTO $", "PRECIO $", "CANTIDAD");
			fprintf(archivo, " ------------------------------------------------------------------------------\n");

			/* Se recorre el vector din�mico de productos */
			costoTotal = 0;
			precioTotal = 0;
			cantidadTotal = 0;
			for (i = 0; i < numeroProductos; i++) {
				if (productos[i].codigo != VALOR_CENTINELA) {
					fprintf(archivo, "%7d \t%-20.20s%15.1s%15.1f%8d\n", productos[i].codigo, productos[i].nombre, productos[i].editorial, productos[i].costo, productos[i].precio, productos[i].cantidad);
					costoTotal += productos[i].costo;
					precioTotal += productos[i].precio;
					cantidadTotal += productos[i].cantidad;
				}
			}
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			fprintf(archivo, "\t\t\t      TOTAL: %15.1f%15.1f%8d", costoTotal, precioTotal, cantidadTotal);

			guardado = 1;

			/* Cierra el archivo */
			fclose(archivo);
		}
	}
	return guardado;
}

#endif
