//
// Created by tais on 4/4/19.
//


typedef struct {
    char prefixo[100];
    /* outros componentes */
}TipoItem;
typedef struct TipoCelula {
    TipoItem Item;
    struct TipoCelula *Prox;
} TipoCelula;
typedef struct {
    struct TipoCelula *Fundo, *Topo;
    int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha);
int Vazia(TipoPilha Pilha);
void Empilha(TipoItem x, TipoPilha *Pilha);
void Desempilha(TipoPilha *Pilha, TipoItem *Item);
int Tamanho(TipoPilha Pilha);