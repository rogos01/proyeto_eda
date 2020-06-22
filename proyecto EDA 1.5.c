#include <string.h>

typedef struct node{		// 06/06/2020   rodrigo
	char editorial[50];
	char buscar[80];
	char formato[20];
	char titulo[50];
	int ISBN;
    int precio;
    int stock;
	char autor[40];
	struct node* next;
	struct node* back;
} node;						//edit correcion Johan 07/06/2020

node* head = NULL;
node* tail = NULL;

void insert_lib();
void mostrar();
void buscar_cod();
void borrar();

int main(){				//johan 15/06/2020
	int opc = 0;
	do{
		printf("\n\t1.Insertar \n\t2.Mostar \n\t3.Buscar \n\t4.Eliminar \n\t5.Cerrar programa\n\t");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				insert_lib();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				buscar_cod();
				break;
			case 4:
				borrar();
				break;
			case 5:
				break;
			default:
				printf("\n\n eleccion no reconocida \n\n");
		}
	}while(opc != 5);
	return 0;
}							//edit rodrigo 21/06/2020

void insert_lib(){			//  09/06/2020  Johan
    // n = node creado (new)
	node* n = (node*) malloc(sizeof(node));
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
	scanf("%d", &n->precio);
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
}

void mostrar(){					// 08/06/2020   rodrigo
    // j = node temporal
	node* j = (node*) malloc(sizeof(node));
	j = head;
	if(head!=NULL){
		do{
			printf("\nTitulo :%s", j->titulo);
			printf("\nAutor: %s", j->autor);
			printf("\nEditorial: %s", j->editorial);
			printf("\nFormato: %s", j->formato);
			printf("\nISBN: %d", j->ISBN);
			printf("\nstockstencias: %d\n\n", j->stock);
			printf("\nPrecio: %d\n\n", j->precio);

			j = j->next;
		}while(j != head);
	}else{
		printf("\n La lista esta vacia\n\n");
	}

}

void buscar_cod(){			// 11/06/2020   rodrigo
	node* j = (node*) malloc(sizeof(node));
	j = head;
	int s = 0;
	int f = 0;
	printf("ISBN: ");
	scanf("%d", &s);
	if(head!=NULL){
		do{
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
}

void borrar(){				// 12/06/2020   Johan
	node* j = (node*) malloc(sizeof(node));
	j = head;
	node* prev = (node*) malloc(sizeof(node));
	prev = NULL;
    // variable para buscar node (search)
	int s = 0;
    // variable para encontrar node (found)
    int f = 0;
	printf(" ISBN: ");
	scanf("%d", &s);
	if(head!=NULL){
		do{
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
}		//edit rodrigo 13/06/2020
