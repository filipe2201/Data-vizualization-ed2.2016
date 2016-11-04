#include "types.h"
#include <stdlib.h>
#include<stdio.h>



void empilhar(stack *s, int num){
	no *aux;
	aux = (no*)malloc(sizeof(no));
	aux->n = num;
	aux->prox = *s;
	*s = aux;
}
void desempilhar(stack *s){
	no *aux;
	aux = *s;
	*s = (*s)->prox;
	free(aux);
}
void inicializar(stack *s){
	*s = NULL;
}
int isempety(stack s){
	if (s == NULL){
		return TRUE;
	}
	else{
		return FALSE;
	}
}
int isfull(stack s){
	return FALSE;
}
int top(stack s){
	int valor;
	valor = s->n;
	return valor;
}
void destroy(stack *pdl){
	no*aux;
	while (*pdl != NULL)
	{
		aux = *pdl;
		*pdl = (*pdl)->prox;
		free(aux);

	}
}
