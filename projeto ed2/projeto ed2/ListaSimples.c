#include"types.h"
#include<stdlib.h>


void alocar(no**aux, int valor){
	*aux = (no*)malloc(sizeof(no));
	(*aux)->num = valor;
	(*aux)->prox = NULL;
}

void add(no **pont, int valor){

	no *aux, *primeiro, *segundo;
	if (*pont == NULL){
		alocar(*pont, valor);
	}if (valor == (*pont)->num){
		printf("valor repetido\n");
	}
	else if (valor < (*pont)->num){
		alocar(aux, valor);
		aux->prox = *pont;
		*pont = aux;

	}
	else{
		primeiro = *pont;
		segundo = primeiro->prox;
		while (segundo != NULL)
		{
			if (valor == primeiro->num){
				printf("valor repetido\n");
				return;
			}
			else if (valor > primeiro->num){
				alocar(aux, valor);
				primeiro->prox = aux;
				aux->prox = segundo;
				return;
			}
			else{
				primeiro = segundo;
				segundo = segundo->prox;
			}
		}

	}
}
/


