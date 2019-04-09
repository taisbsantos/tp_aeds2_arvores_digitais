#include<stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "patricia.h"

void inicializa_pat(TipoPatNo **no){
    *no=NULL;
}
TipoPatNo *Insere(char *k, TipoPatNo *t)
{
    TipoPatNo *p;
    int i;

    if (t == NULL){

        return (CriaNoExt(k));
    }else {

        p = t;
        while (!EExterno(p)) {

            if (strlen(k) >= p->NO.NInterno.posicao && k[p->NO.NInterno.posicao] < (p)->NO.NInterno.letra_palavra) {

                p = p->NO.NInterno.Esq;
            } else {

                p = p->NO.NInterno.Dir;
            }

        }

        for (i = 0; k[i]; i++) {
            if (k[i] != p->NO.palavra[i])
                break;
        }

        return (InsereEntre(k,t,i,max(k[i],p->NO.palavra[i])));
    }


}
TipoPatNo * InsereEntre(char *k, TipoPatNo *t, int i, char letra)
{

    TipoPatNo *p = NULL;
    if (EExterno(t) || i < t->NO.NInterno.posicao)
    { /* cria um novo no externo */
        p = CriaNoExt(k);

        if (k[i]<letra)
            return (CriaNoInt(i, letra, p, t));
        else return (CriaNoInt(i,letra, t, p));
    }
    else
    {
        if (k[t->NO.NInterno.posicao] >=t->NO.NInterno.letra_palavra)
            t->NO.NInterno.Dir =  InsereEntre(k,t->NO.NInterno.Dir,i,letra);
        else
            t->NO.NInterno.Esq =  InsereEntre(k,t->NO.NInterno.Esq,i,letra);
        return t;
    }

}

short EExterno(TipoPatNo *p)
{ /* Verifica se p^ e nodo externo */
    return( p->nt == Externo);
}

TipoPatNo * CriaNoInt(int i,char letra, TipoPatNo *Esq,  TipoPatNo *Dir)
{
    TipoPatNo *p;
    p = (TipoPatNo*)malloc(sizeof(TipoPatNo));
    p->nt = Interno;
    p->NO.NInterno.Esq = Esq;
    p->NO.NInterno.Dir = Dir;
    p->NO.NInterno.letra_palavra = letra;
    p->NO.NInterno.posicao=i;
    return p;
}

TipoPatNo * CriaNoExt(char *k)
{
    TipoPatNo *p;
    p = (TipoPatNo*)malloc(sizeof(TipoPatNo));
    p->nt = Externo;
    strcpy(p->NO.palavra, k);

    return p;
}

void Pesquisa(char *k, TipoPatNo *t){
    if (EExterno(t))
    { if (strcmp(k, t->NO.palavra)==0)
            printf("\nA palavra %s foi encontrada\n",t->NO.palavra);
      else printf("Elemento nao encontrado\n");
        return;
    }
    if(strlen(k) >= t->NO.NInterno.posicao && k[t->NO.NInterno.posicao] < (t)->NO.NInterno.letra_palavra){
        Pesquisa(k, t->NO.NInterno.Esq);
    }else
        Pesquisa(k,t->NO.NInterno.Dir);

}

char max(char a, char b) {
    return a > b ? a : b;
}


