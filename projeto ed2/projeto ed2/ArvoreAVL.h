#include "types.h"
TNodo* InsereAVL(TNodo* pNodo, int ch);
TNodo* Consulta(TNodo* pNodo, char ch);
TNodo* Remove(TNodo* pNodo, char ch);
TNodo* RemoveAVL(TNodo* pNodo);

int Calcula_FB(TNodo* pNodo);
void Seta_FB(TNodo* pNodo);
TNodo* CorrigeAVL(TNodo* pNodo);

TNodo* rotacao_direita(TNodo* pNodo);
TNodo* rotacao_esquerda(TNodo* pNodo);
TNodo* rotacao_dupla_direita (TNodo* pNodo);
TNodo* rotacao_dupla_esquerda (TNodo* pNodo);
