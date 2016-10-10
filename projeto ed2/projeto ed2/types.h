#ifndef ESTRUTURAS
#define ESTRUTURAS
typedef struct no{
	int num;
	struct no *prox;
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

#endif


#ifndef TRUE
#define TRUE 1	
#endif

#ifndef FALSE
#define FALSE 0
#endif