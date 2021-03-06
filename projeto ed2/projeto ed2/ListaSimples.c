#include"types.h"
#include<stdlib.h>
#include<stdio.h>


no* alocar(int v){
	no*aux;
	aux = (no*)malloc(sizeof(no));
	aux->n = v;
	aux->prox = NULL;
	return aux;
}

void add_ls(no **ptr, int v){
	no *aux, *ult;
	if (*ptr == NULL){
		aux = alocar(v);
		*ptr = aux;
	}
	else{
		aux = *ptr;
		while (aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = alocar(v);
	}
}

void remover_ls(no **ptr, int v){
	no*aux, *pri, *seg;
	if (*ptr == NULL){
		printf("lista vazia\n");
	}
	else if (v == (*ptr)->n){
		aux = *ptr;
		*ptr = (*ptr)->prox;
		free(aux);
	}
	else{
		pri = *ptr;
		seg = pri->prox;
		while (seg != NULL){
			if (seg->n == v){
				aux = seg;
				pri->prox = seg->prox;
				free(aux);
				return;
			}
			else{
				pri = seg;
				seg = seg->prox;
			}
		}
		printf("valor nao encontrado\n");
	}
}

void listar_ls(no*ptr){
	if (ptr == NULL){
		printf("lista vazia\n");
	}
	else{
		while (ptr != NULL){
			printf("%d ", &ptr->n);
			ptr = ptr->prox;
		}
	}
}
