#include<stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>
#include "patricia.h"

void inicializa_pat(TipoPatNo **no){
    *no=NULL;
}
TipoPatNo *Insere(char *k, TipoPatNo *t, int arquivoID)
{
    TipoLista lista;
    TipoPatNo *p;
    int i;
    TipoPatNo *checagem;
    if (t == NULL){
        
        return (CriaNoExt(k,&lista,arquivoID));

    }else {

        p = t;
        while (!EExterno(p)) {

            if (strlen(k) >= p->NO.NInterno.posicao && k[p->NO.NInterno.posicao] < (p)->NO.NInterno.letra_palavra) {

                p = p->NO.NInterno.Esq;
            } else {

                p = p->NO.NInterno.Dir;
            }

        }


        checagem = ChecagemPalavra(k,p);

        //qtd++;
        for (i = 0; k[i]; i++) {
            if (k[i] != p->NO.NExterno.palavra[i])
                break;
        }

        return (InsereEntre(k,t,i,max(k[i],p->NO.NExterno.palavra[i]),&lista,checagem,arquivoID));

    }
}


TipoPatNo * InsereEntre(char *k, TipoPatNo *t, int i, char letra,TipoLista *lista,TipoPatNo *checagem,int arquivoId)
{
    TipoItem x;
    TipoPatNo *p = NULL;
    if (EExterno(t) || i < t->NO.NInterno.posicao)
    { /* cria um novo no externo */
        if (strcmp(k, t->NO.NExterno.palavra)==0){
            //Precisa dar um jeito de verificar qual o id se o id 
            if(t->lista_palavra.Ultimo->Item.idDoc!=arquivoId){
                x.idDoc=arquivoId;
                x.qtd=1;
                 Insere_lista_encadeada(&x,&t->lista_palavra);
            }
            else t->lista_palavra.Ultimo->Item.qtd++;

            return t;
        }else{
            p = CriaNoExt(k,lista,arquivoId);

            if (k[i]<letra)
                return (CriaNoInt(i, letra, p, t));
            else return (CriaNoInt(i,letra, t, p));
        }


    }
    else
    {
        if (k[t->NO.NInterno.posicao] >=t->NO.NInterno.letra_palavra)
            t->NO.NInterno.Dir =  InsereEntre(k,t->NO.NInterno.Dir,i,letra,lista,checagem,arquivoId);
        else
            t->NO.NInterno.Esq =  InsereEntre(k,t->NO.NInterno.Esq,i,letra,lista,checagem,arquivoId);
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

TipoPatNo * CriaNoExt(char *k,TipoLista *lista,int arquivoId)
{
    TipoPatNo *p;
    TipoItem item;
    p = (TipoPatNo*)malloc(sizeof(TipoPatNo));
    p->nt = Externo;
    strcpy(p->NO.NExterno.palavra, k);

    item.idDoc=arquivoId;
    item.qtd=1;
    FLVazia(&p->lista_palavra);
    Insere_lista_encadeada(&item,&p->lista_palavra);
    return p;
}




void Pesquisa(char *k, TipoPatNo *t){
    if (EExterno(t))
    { if (strcmp(k, t->NO.NExterno.palavra)==0)
            //printf("\nA palavra %s foi encontrada %d vezes\n",t->NO.palavra,t->NO.lista_palavra.Ultimo->Item.qtd);
            printf("\nA palavra %s foi encontrada\n",t->NO.NExterno.palavra);
        else printf("Elemento nao encontrado\n");
        return;
    }
    if(strlen(k) >= t->NO.NInterno.posicao && k[t->NO.NInterno.posicao] < (t)->NO.NInterno.letra_palavra){
        Pesquisa(k, t->NO.NInterno.Esq);
    }else
        Pesquisa(k,t->NO.NInterno.Dir);

}


TipoPatNo *ChecagemPalavra(char *k, TipoPatNo *t){
    if (EExterno(t)){
        if (strcmp(k, t->NO.NExterno.palavra)==0){
            return t;
        }else{
            return 0;
        }
    }
}



char max(char a, char b) {
    if(a>b)
        return a;
    else return b;
}
void Busca(TipoPatNo *t){
    if (EExterno(t))
    { 
            printf("\n %s ",t->NO.NExterno.palavra);
            Imprime(t->lista_palavra);
          
    }

    if( t->NO.NInterno.Dir!=NULL)
        Busca(t->NO.NInterno.Esq);

    if(t->NO.NInterno.Esq!=NULL)
        Busca(t->NO.NInterno.Dir);

}

//Calcula quantas palavras tem em cada arquivo
void Calcula_num_termos(TipoPatNo *arvore,int *qtd_termos){
    TipoCelula* Aux;
    if (EExterno(arvore))
    { 
        Aux = arvore->lista_palavra.Primeiro -> Prox;

        while (Aux != NULL) { 
           //
             qtd_termos[Aux->Item.idDoc-1]++;
             Aux = Aux -> Prox;
        }
 printf("id %d\n",Aux->Item.idDoc);
    }

    if( arvore->NO.NInterno.Dir!=NULL)
        Calcula_num_termos(arvore->NO.NInterno.Esq,qtd_termos);

    if(arvore->NO.NInterno.Esq!=NULL)
        Calcula_num_termos(arvore->NO.NInterno.Dir,qtd_termos);
}

//pede os termos de pesquisa e conta quantas palavras foram pesquisadas
void Guarda_termos(TipoPatNo *arvore,int *total_palavras,Termos *termos){

    char string_busca[100],palavra[50];
    int qtd_termos[5],j,i;
    //zera vetor qtd
    for(i=0;i<5;i++){
        qtd_termos[i]=0;
    }

    printf("O que voce deseja encontrar?\n");
    //pegando os termos de busca separadamente
    j=0;
    while (fscanf(stdin, "%s", palavra) ){
        if(strcmp(palavra,"fim")==0)
           return;
       else{
        strcpy(termos[j].termo,palavra);
        //total de termos que a busca tem
        (*total_palavras)++; 
        j++;
    
       }
     }
//quantidade de termos de cada arquivo
    Calcula_num_termos(arvore,qtd_termos);
      for(i=0;i<10;i++){
        printf(" %d\n",qtd_termos[i]);
    }
}

//Em quantos arquivos cada palavra aparece
int Qtd_arquivos_por_palavra(TipoPatNo *arvore, char *palavra, int*tam){
     TipoCelula* Aux;
    if (EExterno(arvore))
    { 
        if(strcmp(arvore->NO.NExterno.palavra,palavra)==0){     
           (*tam) =Tamanho_lista(arvore->lista_palavra);
           
        }
    }
    if( arvore->NO.NInterno.Dir!=NULL)
        Qtd_arquivos_por_palavra(arvore->NO.NInterno.Esq,palavra,tam);

    if(arvore->NO.NInterno.Esq!=NULL)
            Qtd_arquivos_por_palavra(arvore->NO.NInterno.Dir,palavra,tam);

return (*tam);
}





//quantas vezes a palavra aparece em determinado arquivo
int Qtd_palavras_em_arquivo(TipoPatNo *arvore, char *palavra,int arquivoId,int *qtd_pal_arq)
{ 

    TipoCelula* Aux;
    

    if (EExterno(arvore))
    { 
        Aux = arvore->lista_palavra.Primeiro -> Prox;
        if(strcmp(arvore->NO.NExterno.palavra,palavra)==0){
            if(Aux->Item.idDoc==arquivoId){
                printf("qtd teste %d\n",Aux->Item.qtd );
                (*qtd_pal_arq)=Aux->Item.qtd;
               
            }
            
        }
    }

    if( arvore->NO.NInterno.Dir!=NULL)
        Qtd_palavras_em_arquivo(arvore->NO.NInterno.Esq,palavra,arquivoId,qtd_pal_arq);

    if(arvore->NO.NInterno.Esq!=NULL)
        Qtd_palavras_em_arquivo(arvore->NO.NInterno.Dir,palavra,arquivoId,qtd_pal_arq);
    return (*qtd_pal_arq);
   
}

void ocorrencias(TipoPatNo *arvore,int num_docs, int total_palavras,Termos *termos,int *qtd_pal_arq){
    double ocorrencias;
    double vetor_ocorrencias[num_docs];
    int i=0,j;
    while(i<total_palavras){
            for(j=0;j<num_docs;j++){
                Qtd_palavras_em_arquivo(arvore,termos[j].termo,j+1,qtd_pal_arq);
            }
        i++;
    }

}