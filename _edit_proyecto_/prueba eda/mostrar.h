#ifndef mostrar_h
#define mostrar_h
#include "struct.h"
#include "cadena.h"
#include "guardar_archivo.h"

void menuMostrar(){
	Producto *productos;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;
	char respuesta[MAX];

	system("cls");
	tituloPrincipal();
	productos = obtenerProductos(&numeroProductos); /* Retorna un vector din�mico de productos */
	if (numeroProductos == 0) {
		printf("\n\tEl archivo no contiene datos!!\n");
		system("pause>nul");
	} else {
		printf("\n\t\t    ==> INVENTARIO DE LIBROS  <==\n");
		printf(" ------------------------------------------------------------------------------\n");
		printf("%8s\t%-5s%15s%15s%15s%10s\n", "ISBN", "Titulo","Editorial", "COSTO $", "PRECIO $", "CANTIDAD");
		printf(" ------------------------------------------------------------------------------\n");
		/* Se recorre el vector din�mico de productos */
		costoTotal = 0;
		precioTotal = 0;
		cantidadTotal = 0;
		for (i = 0; i < numeroProductos; i++) {
			if (productos[i].codigo != VALOR_CENTINELA) {
				printf("%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigo, productos[i].nombre, productos[i].costo, productos[i].precio, productos[i].cantidad);
				costoTotal += productos[i].costo;
				precioTotal += productos[i].precio;
				cantidadTotal += productos[i].cantidad;
			}
		}
		printf(" ------------------------------------------------------------------------------\n");
		printf("\t\t\t      TOTAL: %14.1f%15.1f%8d\n", costoTotal, precioTotal, cantidadTotal);
		printf("\n\tDesea guardar el reporte en un archivo de texto? [S/N]: ");
		leecad(respuesta, MAX);
		if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			if (guardarReporte()) {
				printf("\n\tEl reporte fue guardado con exito\n");
			} else {
				printf("\n\tOcurrio un error al guardar el reporte\n");
			}
			system("pause>nul");
		}
	}
}


#endif
