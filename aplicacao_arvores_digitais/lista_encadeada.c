
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

void Insere_lista_encadeada(TipoItem *x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoCelula*) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;

    Lista->Ultimo->Item.qtd = (*x).qtd;
    Lista->Ultimo->Item.idDoc =  (*x).idDoc;
    Lista -> Ultimo -> Prox = NULL;
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
    { printf("IdDoc %d ", Aux -> Item.idDoc);
        printf(" Quantidade %d ", Aux -> Item.qtd);
        Aux = Aux -> Prox;
        
    }
    printf("\n");
    return;
}