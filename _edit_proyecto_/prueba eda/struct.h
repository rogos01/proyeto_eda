#ifndef struct_h
#define struct_h
#define MAX 100
#include "titulo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>      //setlocale

#define MAX 100
#define VALOR_CENTINELA -1

struct producto {
	int codigo;
	char nombre[MAX], editorial[MAX];
	float costo;
	float precio;
	int cantidad;
};

typedef struct producto Producto;
char linea[MAX];

#endif
