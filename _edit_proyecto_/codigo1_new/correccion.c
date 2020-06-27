#include <string.h>
#include "node.h"


#define MAX 100

void insert_lib();
void mostrar();
void buscar_cod();
void borrar();
int leecad(char *cad, int n);

int main(){				//johan 15/06/2020
	int opc = 0;
	do{

		system("cls");
		printf("\n\t\t\t\tOPCIONES\n");
		printf("\n\t\t[1]. Meter al carrito\n");
		printf("\t\t[2]. Mostar carrito\n");
		printf("\t\t[3]. Buscar libro por ISBN\n");
		printf("\t\t[4]. Eliminar del carrito\n");
		printf("\t\t[6]. Salir\n");
		printf("\n\t\tIngrese su opcion: [ ]\b\b");
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
			case 6:
				break;
			default:
				printf("\n\n eleccion no reconocida \n\n");
		}
	}while(opc != 6);
	return 0;
	system("pause>nul");
}							//edit rodrigo 21/06/2020


int leecad(char *cad, int n){
	int i, c;
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}
	if (c == '\n') {
		i = 0;
	} else {
		cad[0] = c;
		i = 1;
	}
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		cad[i] = c;
	}
	cad[i] = '\0';
	if (c != '\n' && c != EOF) /* es un caracter */
		while ((c = getchar()) != '\n' && c != EOF);

	return 1;
}

void insert_lib(){			//  09/06/2020  Johan

    node* n = (node*) malloc(sizeof(node));
    char repite = 1;
    char respuesta[80];

    do{

        system("cls");

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

void mostrar(){					// 08/06/2020   rodrigo
    // j = node temporal
	node* j = (node*) malloc(sizeof(node));
	j = head;

	system("cls");

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

void buscar_cod(){			// 11/06/2020   rodrigo
	node* j = (node*) malloc(sizeof(node));
	j = head;
	int s = 0;
	int f = 0;
	system("cls");

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

void borrar(){				// 12/06/2020   Johan
	node* j = (node*) malloc(sizeof(node));
	j = head;
	node* prev = (node*) malloc(sizeof(node));
	prev = NULL;
	int s = 0;      // variable para buscar node (search)
    int f = 0;      // variable para encontrar node (found)

    system("cls");

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
