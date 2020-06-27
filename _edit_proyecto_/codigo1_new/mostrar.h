#ifndef mostrar_h
#define mostrar_h
#include "node.h"

void mostrar(){					// 08/06/2020   rodrigo
    // j = node temporal
	node* j = (node*) malloc(sizeof(node));
	j = head;

	system("cls");
	tituloPrincipal();
	if(head!=NULL){
		do{
			printf("\nTitulo :%s", j->titulo);
			printf("\nAutor: %s", j->autor);
			printf("\nEditorial: %s", j->editorial);
			printf("\nFormato: %s", j->formato);
			printf("\nISBN: %d", j->ISBN);
			printf("\nstock: %d\n\n", j->stock);
			printf("\nPrecio: %.02f\n\n", j->precio);       // cambio a float rodrigo 22/06/2020

			j = j->next;
		}while(j != head);
	}else{
		printf("\n La lista esta vacia\n\n");
	}
    system("pause>nul");
}

#endif