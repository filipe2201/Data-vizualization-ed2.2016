#include "types.h"
#include <stdlib.h>

void enqueue(Queue *q, int s){
	NoQueue *aux;
	aux = (NoQueue*)malloc(sizeof(NoQueue));
	aux->senha = s;
	if (isEmpty(*q) == TRUE){
		(*q)->inicio = aux;
		(*q)->fim = aux;
	}
	else{
		(*q)->fim->prox = aux;
		(*q)->fim = aux;
	}
}

int dequeue(Queue *q){
	NoQueue *aux;
	int s;
	aux = (*q)->inicio;
	(*q)->inicio = (*q)->inicio->prox;
	if ((*q)->inicio == NULL)
		(*q)->fim = NULL;
	s = aux->senha;
	free(aux);
	return s;
}
int head(Queue q){
	return q->inicio->senha;
}
int isEmptyF(Queue q){
	if (q->inicio == NULL)
		return TRUE;
	else
		return FALSE;
}
int isFULLF(Queue q){
	return FALSE;
}

Queue initialize(){
	Queue aux;
	aux = (Descritor*)malloc(sizeof(Descritor));
	aux->inicio = NULL;
	aux->fim = NULL;
	return aux;
}
void destroyF(Queue Q){
	NoQueue *aux;
	aux = Q->inicio;
	while (aux != NULL){
		Q->inicio = Q->inicio->prox;
		free(aux);
		aux = Q->inicio;
	}
	free(Q);
}