#include <stdio.h>
#include <stdlib.h>
#ifndef ESTRUTURAS
#define ESTRUTURAS
typedef struct no{
	int n;
	struct no *prox;
	struct no*ant;
}no;
typedef no *stack;

typedef struct noqueue{
	int senha;
	struct noqueue *prox;
}NoQueue;

typedef struct descritor{
	NoQueue *inicio, *fim;
}Descritor;

typedef Descritor *Queue;

typedef struct Nodo
{
        int info;
        int FB;
        struct Nodo *esq;
        struct Nodo *dir;
}TNodo;


#endif


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif
