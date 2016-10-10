#include<stdio.h>
#include<stdlib.h>
#include"types.h"


no* alocar(int v){
	no*aux;
	aux = (no*)malloc(sizeof(no));
	aux->n = v;
	aux->prox = NULL;
	aux->ant = NULL;
	return aux;
}

void add_lc(no **ptr, int v){
	no *aux, *ult;

	if (*ptr == NULL){
		aux = alocar(v);
		aux->prox = aux;
		aux->ant = aux;
		*ptr = aux;
	}
	else{
		aux = *ptr;
		while (aux->prox != *ptr)
		{
			aux = aux->prox;
		}

		aux->prox = alocar(v);
		aux->prox->ant = aux;
		aux = aux->prox;
		aux->prox = *ptr;
		aux->prox->ant = aux;
	}
}

void remover_lc(no **ptr, int v){
	no*aux;
	if (*ptr == NULL){
		printf("lista vazia\n");
	}
	else if ((*ptr)->n == v){
		aux = *ptr;
		*ptr = (*ptr)->prox;
		if (*ptr != NULL){
			(*ptr)->ant = NULL;
		}
		free(aux);
	}
	else{
		aux = (*ptr)->prox;
		while (aux != NULL)
		{
			if (aux->n == v){
				if (aux->prox == NULL){
					aux->ant->prox = NULL;
					free(aux);
				}
				else{
					aux->ant->prox = aux->prox;
					aux->prox->ant = aux->ant;
					free(aux);
				}
			}
			else
			{
				aux = aux->prox;
			}
		}
	}
}

void listar_lc(no*ptr){
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
