#include "ArvoreAVL.h"
#include "types.h"
TNodo* pNodoA;


int Altura (TNodo* pNodo)
{
	int Alt_Esq, Alt_Dir;
	if (pNodo == NULL) return 0;
	else
	{
		Alt_Esq = Altura (pNodo->esq);
		Alt_Dir = Altura (pNodo->dir);
		if (Alt_Esq > Alt_Dir)
		{
			return (1 + Alt_Esq);
		}
		else
		{
			return (1 + Alt_Dir);
		}
	}
}

int Calcula_FB(TNodo* pNodo)
{
    if(pNodo == NULL)return 0;
    return (Altura(pNodo->esq)- Altura(pNodo->dir));
}

void Seta_FB(TNodo* pNodo)
{
     if (pNodo!= NULL)
     {
		 pNodo->FB=(Altura(pNodo->esq)- Altura(pNodo->dir));
		 Seta_FB(pNodo->esq);
		 Seta_FB(pNodo->dir);
     }
}


TNodo* rotacao_direita(TNodo* N3)
{
       TNodo* N2= N3->esq;
       if(N2->dir) N3->esq = N2->dir;
       else N3->esq=NULL;
       N2->dir=N3;
       return N2;
}

TNodo* rotacao_esquerda(TNodo* N1)
{
       TNodo* N2= N1->dir;
       if(N2->esq) N1->dir= N2->esq;
       else N1->dir=NULL;
       N2->esq=N1;
       return N2;
}

TNodo* rotacao_dupla_direita (TNodo* N3)
{
       TNodo* N1= N3->esq;
       TNodo* N2= N1->dir;

       if(N2->esq) N1->dir= N2->esq;
       else N1->dir=NULL;

       if(N2->dir) N3->esq = N2->dir;
       else N3->esq=NULL;

       N2->esq=N1;
       N2->dir=N3;

       return N2;
}

TNodo* rotacao_dupla_esquerda (TNodo* N1)
{
       TNodo* N3= N1->dir;
       TNodo* N2= N3->esq;

       if(N2->esq) N1->dir= N2->esq;
       else N1->dir=NULL;

       if(N2->dir) N3->esq = N2->dir;
       else N3->esq=NULL;

       N2->esq=N1;
       N2->dir=N3;

       return N2;
}

TNodo* CorrigeAVL(TNodo* pNodo)
{
	if(pNodo != NULL)
	{
		pNodo->FB=Calcula_FB(pNodo);
		if(pNodo->FB == 2)
		{
			pNodo->esq->FB=Calcula_FB(pNodo->esq);
			if(pNodo->esq->FB > 0)
			{
				pNodo = rotacao_direita(pNodo);
			}
			else
			{
				pNodo =  rotacao_dupla_direita(pNodo);
			}
		}
		else if(pNodo->FB == -2)
		{
			pNodo->dir->FB=Calcula_FB(pNodo->dir);
			if(pNodo->dir->FB < 0)
			{
				pNodo = rotacao_esquerda(pNodo);
			}
			else
			{
				pNodo =  rotacao_dupla_esquerda(pNodo);
			}
		}
		pNodo->esq = CorrigeAVL(pNodo->esq);
		pNodo->dir = CorrigeAVL(pNodo->dir);
    }
    return pNodo;
}


TNodo* InsereAVL(TNodo* pNodo, int ch)
{
	if (pNodo == NULL)
	{
		pNodo =(TNodo*)malloc(sizeof(TNodo));
		pNodo->info= ch;
		pNodo->FB= 0;
		pNodo->esq= NULL;
		pNodo->dir= NULL;
		return pNodo;
	}
	else
	{
		if(ch < pNodo->info)
		{
			pNodo->esq = InsereAVL(pNodo->esq,ch);
		}
		else
		{
			pNodo->dir = InsereAVL(pNodo->dir,ch);
		}
	}
	return pNodo;
}


TNodo* Consulta(TNodo* pNodo, char ch)
{
    while (pNodo != NULL)
    {
		if(ch == pNodo->info)
		{
			return pNodo;
		}
		else
		{
			if(ch < pNodo->info)
			{
				pNodo=pNodo->esq;
			}
			else
			{
				pNodo=pNodo->dir;
			}
		}
	}
	return NULL;
}


TNodo* Remove(TNodo* pNodo, char ch)
{
	TNodo* pNodoAux=pNodo;
	TNodo* pNodoPai;
	int bdir=0;

	if(ch == pNodo->info) return RemoveAVL(pNodoAux);

    while (pNodoAux != NULL)
    {
		if(ch == pNodoAux->info)
		{
			if(bdir) pNodoPai->dir= RemoveAVL(pNodoAux);
			else pNodoPai->esq= RemoveAVL(pNodoAux);
			return pNodo;
		}
		else
		{
			if(ch < pNodoAux->info)
			{
				bdir=0;
				pNodoPai=pNodoAux;
				pNodoAux=pNodoAux->esq;
			}
			else
			{
				bdir=1;
				pNodoPai=pNodoAux;
				pNodoAux=pNodoAux->dir;
			}
		}
	}
	return pNodo;
}


TNodo* RemoveAVL(TNodo* pNodo)
{
	TNodo* pNodoAux;
	TNodo* pNodoAuxPai;

	if((pNodo->esq == NULL) && (pNodo->dir == NULL))
	{
        free(pNodo);
    	return NULL;
	}
	else if((pNodo->esq == NULL) && (pNodo->dir != NULL))
	{
		pNodoAux=pNodo->dir;
        free(pNodo);
    	return pNodoAux;
	}
	else if((pNodo->esq != NULL) && (pNodo->dir == NULL))
	{
		pNodoAux=pNodo->esq;
		free(pNodo);
		return pNodoAux;
	}
	else
	{
		if(pNodo->esq->dir == NULL)
        {
			pNodoAux=pNodo->esq;
    	    pNodo->esq->dir=pNodo->dir;
            free(pNodo);
    		return pNodoAux;
        }
        else
        {
    		pNodoAux=pNodo->esq;

    		while (pNodoAux->dir != NULL)
    		{
    			pNodoAuxPai=pNodoAux;
                pNodoAux=pNodoAux->dir;
    		}

    		if(pNodoAux->esq!=NULL) pNodoAuxPai->dir=pNodoAux->esq;
    		else pNodoAuxPai->dir=NULL;

            pNodoAux->dir=pNodo->dir;
    	    pNodoAux->esq=pNodo->esq;

    		free(pNodo);
    		return pNodoAux;
        }
	}

	return NULL;
}
