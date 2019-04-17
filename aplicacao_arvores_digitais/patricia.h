#include "lista_encadeada.h"

//
// Created by tais on 4/5/19.
//
typedef enum {
    Interno, Externo
} TipoNo;

typedef struct TipoPatNo {
    TipoNo nt;
    TipoLista lista_palavra;
    union {
        struct {
            int posicao;
            char letra_palavra;
            struct TipoPatNo *Esq, *Dir;
        } NInterno ;
        char palavra[50] ;
    } NO;
} TipoPatNo;

void inicializa_pat(TipoPatNo **no);
short EExterno(TipoPatNo * p);
TipoPatNo * CriaNoInt(int i, char letra, TipoPatNo *Esq,  TipoPatNo *Dir);
TipoPatNo * CriaNoExt(char *k,TipoLista *lista, int arquivoId);
TipoPatNo * InsereEntre(char *k,TipoPatNo *t, int i, char letra,TipoLista *lista,TipoPatNo *checagem,int arquivoId);
TipoPatNo * Insere(char *k, TipoPatNo *t, int arquivoID);
void Pesquisa(char *k, TipoPatNo *t);
TipoPatNo *ChecagemPalavra(char *k, TipoPatNo *t);
void Busca(TipoPatNo *t);
char max(char a, char b) ;
