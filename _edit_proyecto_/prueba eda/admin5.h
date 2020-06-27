#ifndef admin5_h
#define admin5_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modificar.h"

void menuModificar();

void admin5(){
    char claveadmin[20] ,clavetecleada[20];
    
    strcpy(claveadmin, "cocacola");
    printf("\nPara acceder ingrasa clave admin ");
    gets(clavetecleada);
    if(strcmp(claveadmin,  clavetecleada) == 0){
        menuModificar();
    }
    else
    printf("clave incorrecta");
}

#endif