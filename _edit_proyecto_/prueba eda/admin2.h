#ifndef admin2_h
#define admin2_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mostrar.h"

void menuMostrar();

void admin2(){
    char claveadmin[20] ,clavetecleada[20];
    
    strcpy(claveadmin, "cocacola");
    printf("\nPara acceder ingrasa clave admin ");
    gets(clavetecleada);
    if(strcmp(claveadmin,  clavetecleada) == 0){
        menuMostrar();
    }
    else
    printf("clave incorrecta");
}


#endif