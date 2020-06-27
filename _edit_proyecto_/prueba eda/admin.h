#ifndef admin_h
#define admin_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insertar.h"

void menuModificar();

void admin(){
    char claveadmin[20] ,clavetecleada[20];
    
    strcpy(claveadmin, "cocacola");
    printf("\nPara acceder ingrasa clave admin ");
    gets(clavetecleada);
    if(strcmp(claveadmin,  clavetecleada) == 0){
        menuInsertar();
    }
    else
    printf("clave incorrecta");
}

#endif