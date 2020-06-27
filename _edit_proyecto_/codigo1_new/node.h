#ifndef node_h
#define node_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX[100]

typedef struct node{		// 06/06/2020   rodrigo
	char editorial[50];
	char buscar[80];
	char formato[20];
	char titulo[50];
	int ISBN;
    float precio;       //edit int a float rodrigo 22/06/2020
    int stock;
	char autor[40];
	struct node* next;
	struct node* back;
} node;						//edit correcion Johan 07/06/2020

node* head = NULL;
node* tail = NULL;

#endif