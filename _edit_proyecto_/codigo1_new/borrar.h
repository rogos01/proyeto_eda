#ifndef borrar_h
#define borrar_h
#include "node.h"

void borrar(){				// 12/06/2020   Johan
	node* j = (node*) malloc(sizeof(node));
	j = head;
	node* prev = (node*) malloc(sizeof(node));
	prev = NULL;
	int s = 0;      // variable para buscar node (search)
    int f = 0;      // variable para encontrar node (found)

    system("cls");
	tituloPrincipal();
	if(head!=NULL){
		do{


            printf("\n\t\t\t==> ELIMINAR LIBRO POR ISBN <==\n");

            printf(" ISBN: ");
            scanf("%d", &s);
			if(j->ISBN == s){
				printf("\nLibro %s eliminado \n", j->titulo);
				j->stock = 0;
				printf("stockstencias jizadas: %d", j->stock);

				if(j==head){
					head = head->next;
					head->back = tail;
					tail->next = head;
				}else if(j==tail){
					tail = prev;
					tail->next = head;
					head->back = tail;
				}else{
					prev->next = j->next;
					j->next->back = prev;
				}
				f = 1;
			}
			prev = j;
			j = j->next;
		}while(j != head && f != 1);
		if(f == 0){
			printf("\n node no encontrado\n\n");
		}else{
			free(prev);
		}
	}else{
		printf("\n La lista esta vacia\n\n");
	}
    system("pause>nul");
}		//edit rodrigo 13/06/2020

#endif