#ifndef admin4_h
#define admin4_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscar.h"

void menuBuscar();

void admin4(){
    char claveadmin[20] ,clavetecleada[20];
    
    strcpy(claveadmin, "cocacola");
    printf("\nPara acceder ingrasa clave admin ");
    gets(clavetecleada);
    if(strcmp(claveadmin,  clavetecleada) == 0){
        menuBuscar();
    }
    else
    printf("clave incorrecta");
}

#endif