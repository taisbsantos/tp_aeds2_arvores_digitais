/*   
          AUTORES
Élida Emelly  Matrícula: 3012
Yuri de Faria Matrícula: 3373
Taís B Santos Matricula: 3036

*/

#include "lista_encadeada.h"
#include <math.h>

#ifndef PATRICIA_H
#define PATRICIA_H

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
        struct{
             char palavra[50];
    }NExterno;

             

    } NO;
} TipoPatNo;

typedef struct Termos
{
    char termo[50];
}Termos;

void inicializa_pat(TipoPatNo **no);
short EExterno(TipoPatNo * p);
TipoPatNo * CriaNoInt(int i, char letra, TipoPatNo *Esq,  TipoPatNo *Dir);
TipoPatNo * CriaNoExt(char *k,TipoLista *lista, int arquivoId);
TipoPatNo * InsereEntre(char *k,TipoPatNo *t, int i, char letra,TipoLista *lista,TipoPatNo *checagem,int arquivoId);
TipoPatNo * Insere(char *k, TipoPatNo *t, int arquivoID);
void Pesquisa(char *k, TipoPatNo *t);
TipoPatNo *ChecagemPalavra(char *k, TipoPatNo *t);
void Busca(TipoPatNo *t);
void Guarda_termos(TipoPatNo *arvore,int *total_palavras,Termos *termos, int *qtd_termos);
void ocorrencias(TipoPatNo *arvore,int num_docs, int total_palavras,Termos *termos,int *qtd_pal_arq, int *tam,int arq_atual,double *vetor_ocorrencias);
void relevancia (TipoPatNo *arvore,int num_docs, int total_palavras,Termos *termos,int *qtd_pal_arq, int *tam,int *qtd_termos);
void Calcula_num_termos(TipoPatNo *arvore,int *qtd_termos);
int Qtd_arquivos_por_palavra(TipoPatNo *arvore, char *palavra, int *tam);
int Qtd_palavras_em_arquivo(TipoPatNo *arvore, char *palavra,int arquivoId,int *qtd_pal_arq);
char max(char a, char b) ;

#endif
