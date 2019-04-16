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

//void Insere_lista_encadeada(TipoItem x, TipoLista *Lista)
//{ Lista -> Ultimo -> Prox = (TipoCelula*) malloc(sizeof(TipoCelula));
//    Lista -> Ultimo = Lista -> Ultimo -> Prox;
//    Lista -> Ultimo -> Item = x;
//    Lista -> Ultimo -> Prox = NULL;
//}

void Insere_lista_encadeada(TipoItem x, TipoLista *Lista,int arquivoId)
{ Lista -> Ultimo -> Prox = (TipoCelula*) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    /*if(checagem == 1){
        printf("\n Repete - Aumenta 1\n");
        Lista->Ultimo->Item.qtd = 2;
    } else{
        printf("\n Nao repete\n");
        Lista->Ultimo->Item.qtd = 1;
    }*/
    Lista->Ultimo->Item.qtd = 1;
    Lista->Ultimo->Item.idDoc = arquivoId;
    printf(" qtd: %d\n IdDoc: %d\n------------\n",Lista->Ultimo->Item.qtd,Lista->Ultimo->Item.idDoc);
    Lista -> Ultimo -> Prox = NULL;
    //printf("%d",x.qtd);
}


//void Imprime(TipoLista Lista)
//{ TipoCelula* Aux;
//    Aux = Lista.Primeiro -> Prox;
//    while (Aux != NULL)
//    { printf("%d\n", Aux -> Item.idDoc);
//        Aux = Aux -> Prox;
//    }
//}

void Imprime(TipoLista Lista)
{ TipoCelula* Aux;
    Aux = Lista.Primeiro -> Prox;
    while (Aux != NULL)
    { printf("%d\n", Aux -> Item.idDoc);
        printf("%d\n", Aux -> Item.qtd);
        Aux = Aux -> Prox;
    }
}