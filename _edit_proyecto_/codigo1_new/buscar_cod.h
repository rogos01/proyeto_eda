#ifndef buscar_cod_h
#define buscar_cod_h
#include "node.h"

void buscar_cod(){			// 11/06/2020   rodrigo
	node* j = (node*) malloc(sizeof(node));
	j = head;
	int s = 0;
	int f = 0;
	system("cls");
	tituloPrincipal();
	if(head!=NULL){
		do{

            printf("\n\t\t\t==> BUSCAR LIBRO POR ISBN <==\n");

            printf("ISBN del libro: ");
            scanf("%d", &s);

			if(j->ISBN == s){
				printf("\nTitulo: %s\nAutor: %s\nEditorial: %s\n", j->titulo,j->autor,j->editorial);
				printf("Formato: %s\nISBN: %d\nPrecio: %d\n", j->formato,j->ISBN,j->precio);
				f = 1;
			}
			j = j->next;
		}while(j != head && f != 1);
		if(f == 0){
			printf("\nNo se encontro\n\n");
		}
	}else{
		printf("\n La lista esta vacia vacia\n\n");
	}
    system("pause>nul");
}

#endif