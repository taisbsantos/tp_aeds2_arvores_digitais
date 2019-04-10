//
// Created by tais on 4/10/19.
//

#include "lista_encadeada.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoCelula*) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere_lista_encadeada(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoCelula*) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}

void Retira(TipoCelula* p, TipoLista *Lista, TipoItem *Item)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
    TipoCelula* q;
    if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
    { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
        return;
    }
    q = p -> Prox;
    *Item = q -> Item;
    p -> Prox = q -> Prox;
    if (p -> Prox == NULL) Lista -> Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista)
{ TipoCelula* Aux;
    Aux = Lista.Primeiro -> Prox;
    while (Aux != NULL)
    { printf("%d\n", Aux -> Item.idDoc);
        Aux = Aux -> Prox;
    }
}