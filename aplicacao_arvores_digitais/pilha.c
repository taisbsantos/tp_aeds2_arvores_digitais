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
{

    Pilha->Topo = (TipoCelula*) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}


void Empilha(TipoItem x, TipoPilha *Pilha)
{
    TipoCelula* Aux;
    Aux = (TipoCelula*) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}


