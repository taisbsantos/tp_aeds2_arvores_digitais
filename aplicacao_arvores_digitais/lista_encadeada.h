//
// Created by tais on 4/10/19.
//

typedef int TipoChave;

typedef struct TipoItem{
    int qtd;
    int idDoc;
    /* outros componentes */
}TipoItem;

typedef struct TipoCelula {
    TipoItem Item;
    struct TipoCelula *Prox;
} TipoCelula;

typedef struct TipoLista{
    TipoCelula *Primeiro, *Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void Insere_lista_encadeada(TipoItem x, TipoLista *Lista);
void Retira(TipoCelula *p, TipoLista *Lista, TipoItem *Item);
void Imprime(TipoLista Lista);
