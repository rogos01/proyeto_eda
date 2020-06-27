#ifndef admin3_h
#define admin3_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "eliminar.h"

void menuEliminar();

void admin3(){
    char claveadmin[20] ,clavetecleada[20];
    
    strcpy(claveadmin, "cocacola");
    printf("\nPara acceder ingrasa clave admin ");
    gets(clavetecleada);
    if(strcmp(claveadmin,  clavetecleada) == 0){
        menuEliminar();
    }
    else
    printf("clave incorrecta");
}

#endif