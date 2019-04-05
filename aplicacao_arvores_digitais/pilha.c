//
// Created by tais on 4/4/19.
//

#include "pilha.h"
//http://www2.dcc.ufmg.br/livros/algoritmos/cap3/codigo/c/3.13a3.14-pilha-apontadores.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10


void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoCelula*) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); }

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    TipoCelula* Aux;
    Aux = (TipoCelula*) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoCelula* q;
    if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

