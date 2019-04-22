/*   
          AUTORES
Élida Emelly  Matrícula: 3012
Yuri de Faria Matrícula: 3373
Taís B Santos Matricula: 3036

*/
#include<stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "Libs/patricia.h"

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
//se a palavra que eu to enviando for maior que a posição da palavra na patricia e a letra da palavra for menor que a letra que está no nó manda pra esq, senão pra dir
            if (strlen(k) >= p->NO.NInterno.posicao && k[p->NO.NInterno.posicao] < (p)->NO.NInterno.letra_palavra) {

                p = p->NO.NInterno.Esq;
            } else {

                p = p->NO.NInterno.Dir;
            }

        }


        checagem = ChecagemPalavra(k,p);

        //for pra descobrir a posição duas palavras diferem
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
    { 
//se a palavra que eu to enviando é igual a palavra que esta no nó externo eu verifico se id do documento que eu to passando é diferente ao id que eu tenho na ultima celula da lista encadeada, se sim eu aloco uma nova celula dando 1 pra qtd da palavra e o id do documento, se o id é igual eu só acrescento 1 na variavel qtd da celula
        if (strcmp(k, t->NO.NExterno.palavra)==0){
         
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
{
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

//Cria um nó externo e cria uma lista encadeada associada a cada palavra)
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

//função que verifica qual letra é maior

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
            printf("\n");
    }

    if( t->NO.NInterno.Dir!=NULL)
        Busca(t->NO.NInterno.Esq);
    if(t->NO.NInterno.Esq!=NULL)
        Busca(t->NO.NInterno.Dir);
}

//Calcula quantas palavras tem em cada arquivo: percorro arvore e toda vez que é um nó esterno eu percorro a lista da palavra e somo mais um na posição correspondente ao arquivo. 
void Calcula_num_termos(TipoPatNo *arvore,int *qtd_termos){

     TipoCelula* Aux;

    if (EExterno(arvore))
    { 

        Aux = arvore->lista_palavra.Primeiro -> Prox;
        while (Aux != NULL) { 
             qtd_termos[Aux->Item.idDoc-1]++;
             Aux = Aux -> Prox;
        }
       
    }

    if( arvore->NO.NInterno.Dir!=NULL)
        Calcula_num_termos(arvore->NO.NInterno.Esq,qtd_termos);

    if(arvore->NO.NInterno.Esq!=NULL)
        Calcula_num_termos(arvore->NO.NInterno.Dir,qtd_termos);
}

//pede os termos de pesquisa e conta quantas palavras foram pesquisadas
void Guarda_termos(TipoPatNo *arvore,int *total_palavras,Termos *termos, int *qtd_termos){

    char string_busca[100],palavra[50],nome_arquivo[20];
    FILE *arquivo;
    int j,i;
    //zera vetor qtd
    for(i=0;i<5;i++){
        qtd_termos[i]=0;
    }

    printf("O que voce deseja encontrar?(Entre com seu arquivo de busca)\n");
    scanf("%s", nome_arquivo);
    //pegando os termos de busca e guardando num vetor
       arquivo = fopen(nome_arquivo, "r");
       if (!arquivo) {
            printf("ERRO NA LEITURA OU FIM DE LEITURA\n");
        } else {
            j=0;
            while (fscanf(arquivo, "%s", palavra) != EOF) {
        strcpy(termos[j].termo,palavra);
        //total de termos que a busca tem
        (*total_palavras)++;
        j++;
            }
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

void ocorrencias(TipoPatNo *arvore,int num_docs, int total_palavras,Termos *termos,int *qtd_pal_arq, int *tam,int arq_atual,double *vetor_ocorrencias){
    double ocorrencias;

    int j,qtd_pal_arquivos,qtd_arq_pal;

        for(j=0;j<total_palavras;j++){

             qtd_pal_arquivos = Qtd_palavras_em_arquivo(arvore,termos[j].termo,arq_atual,qtd_pal_arq);
            // printf(" qtd %d ",qtd_pal_arquivos);
             qtd_arq_pal = Qtd_arquivos_por_palavra(arvore, termos[j].termo, tam);
             ocorrencias=qtd_pal_arquivos*(log(num_docs)/qtd_arq_pal);
           //  printf("ocorr %lf \n",ocorrencias);
            //ate a linha acima funciona
            vetor_ocorrencias[arq_atual-1] = vetor_ocorrencias[arq_atual-1] + ocorrencias;
        }
}

void relevancia (TipoPatNo *arvore,int num_docs, int total_palavras,Termos *termos,int *qtd_pal_arq, int *tam, int *qtd_termos){
 int i;
 double vetor_ocorrencias[num_docs],vetor_relevancia[num_docs];
  for(i=0;i<num_docs;i++){
    vetor_ocorrencias[i]=0;
  }
//para cada arquivo eu chamo a função de ocorrencia
  for(i=0;i<num_docs;i++){
       ocorrencias(arvore,num_docs,total_palavras,termos,qtd_pal_arq,tam,i+1, vetor_ocorrencias);
  }

  Calcula_num_termos(arvore,qtd_termos);
//para cada documento eu calculo a relevancia
  for(i=0;i<num_docs;i++){
        float a=1;
        vetor_relevancia[i]=(a/qtd_termos[i])*vetor_ocorrencias[i];
  }


int vetor[num_docs],
      x = 0,
      y = 0,
      aux = 0;      
  //Aqui preenche-se um vetor com o numero dos documentos existentes
  for( x = 0; x < num_docs; x++ ) 
  {
    
    vetor[x] = x+1;
  }
  /*Aqui usa-se um bubble sorte pra ordenar as relevancias, mas se a ordenação fosse do próprio vetor de relevancia se perderia qual é o documento relacionado a determinada  relevancia, então a comparação é feita usando o vetor de relevancia, mas a troca ocorre num vetor auxiliar que foi preenchido anteriormente com o numero
dos documentos
  */   
 

  // coloca em ordem crescente (1,2,3,4,5...)  
  for( x = 0; x < num_docs; x++ )
  {
    for( y = x + 1; y < num_docs; y++ ) // sempre 1 elemento à frente
    {
      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
      if ( vetor_relevancia[x] > vetor_relevancia[y] )
      {
         aux = vetor[x];
         vetor[x] = vetor[y];
         vetor[y] = aux;
      }
    }
  } // fim da ordenação
  
  // exibe elementos ordenados   
  
  for( x = 0; x < num_docs; x++ )
  {
    printf("\nTexto %d",vetor[x]); // exibe o vetor ordenado
  }  
  



}
