#ifndef insertar_lib_h
#define insertar_lib_h
#include "node.h"
#include "leercad.h"

#define MAX 100

void insert_lib(){			//  09/06/2020  Johan

    node* n = (node*) malloc(sizeof(node));
    char repite = 1;
    char respuesta[80];

    do{

        system("cls");
        tituloPrincipal();
        // n = node creado (new)

        printf("\nISBN: ");
        scanf("%d", &n->ISBN);
        printf("\nTitulo: ");
        scanf("%s", &n->titulo);
        printf("\nAutor: ");
        scanf("%s", &n->autor);
        printf("\nEditorial: ");
        scanf("%s", &n->editorial);
        printf("\nFormato: ");
        scanf("%s", &n->formato);
        printf("\nPrecio: ");
        scanf("%f", &n->precio);
        printf("\nstock: ");
        scanf("%d", &n->stock);

        if(head==NULL){
            head = n;
            head->next = head;
            tail = head;
            head->back = tail;
        }else{
            tail->next = n;
            n->next = head;
            n->back = tail;
            tail = n;
            head->back = tail;
        }
	    printf("\nLibro ingresado\n\n");
        printf("\n\tDesea seguir agregando libros? [S/N]: ");
		leecad(respuesta, MAX);

        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}
    }
    while(repite);
}

#endif