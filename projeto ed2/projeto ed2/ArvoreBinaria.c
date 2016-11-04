#include<stdio.h>
#include<stdlib.h>
#include"types.h"



void add_ab(no **raiz, int n){
	if (raiz == NULL){
		*raiz = (no*)malloc(sizeof(no));
	}else{
		if (n > (*raiz)->n){
			add_ab(&((*raiz)->prox), n);
		}else{
			add_ab(&((*raiz)->ant), n);
		}
	}
}

void passeio_em_ordem_ab(no *raiz){
	if (raiz != NULL){
		passeio_em_ordem_ab(raiz->ant);
		printf("%d ", raiz->n);
		passeio_em_ordem_ab(raiz->prox);
	}
}

void passeio_pre_ordem_ab(no *raiz){
	printf("%d ", raiz->n);
	passeio_pre_ordem_ab(raiz->ant);
	passeio_pre_ordem_ab(raiz->prox);
}

void passeio_pos_ordem_ab(no *raiz){
	passeio_pos_ordem(raiz->ant);
	passeio_pos_ordem(raiz->prox);
	printf("%d ", raiz->n);
}
void percorrerPorNivel_ab(no * raiz)
{
	Queue fila;
	no * aux;
	if (raiz != NULL)
	{
		initialize(&fila);
		enqueue(fila, raiz);
		while (isEmpty(fila) == FALSE)
		{
			aux = dequeue(fila);
			if (aux->ant != NULL)
				enqueue(fila, aux->ant);
			if (aux->prox != NULL)
				enqueue(fila, aux->prox);
			printf("%d \n", aux->n);
		}
	}
}

void remover_ab(no **raiz, int n)
{
	if (*raiz == NULL)
		printf("valor nao encontrado.\n");
	else if (n == (*raiz)->n)
		remover_no(&(*raiz));
	else
	{
		if (n< (*raiz)->n)
			remover_ab(&((*raiz)->ant), n);
		else
			remover_ab(&((*raiz)->prox), n);
	}
}

void remover_no(no **raiz)
{
	no * pos;
	pos = *raiz;
	if ((*raiz)->ant == NULL && (*raiz)->prox == NULL) // Não tem filhos
		*raiz = NULL;
	else if ((*raiz)->ant == NULL) // Não tem filho a esquerda
		*raiz = (*raiz)->prox;
	else if ((*raiz)->prox == NULL) // Não tem filho a direita
		*raiz = (*raiz)->ant;
	else // Tem ambos os filhos
	{
		pos = maior(&((*raiz)->prox));
		(*raiz)->n = pos->n;
	}
	free(pos);
}

no*maior(no **raiz)
{
	no *aux;
	aux = *raiz;
	if (aux->prox == NULL)
	{
		*raiz = (*raiz)->ant;
		return (aux);
	}
	else
		return maior(&((*raiz)->prox));
}
