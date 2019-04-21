#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"
#include "patricia.h"
#include <ctype.h>

TipoPatNo * arquivo(TipoPatNo *pat);
void menu();

int main() {
     FILE *arquivo;
    char nome_arquivo[20],palavra[50],palavra_aux[50];
    int arquivoId = 0;
    TipoPatNo *pat;

    inicializa_pat(&pat);
    char opcao;
    while(opcao!='d'){
     fflush(stdin);
     printf(" \n            MENU\n");
     printf("a) construir o índice invertido\n");
     printf("b) imprimir o índice invertido\n");
     printf("c) buscar palavra (s) no(s) texto (s)\n");
     printf("d) sair\n");
     scanf("%c",&opcao);
        if(opcao=='a'){
               while(strcmp(nome_arquivo,"sair")!=0){
        printf("Digite o nome arquivo \n");
        printf("Quando nao quiser mais ler arquivos digite sair\n");
        scanf("%s", nome_arquivo);
   
        arquivo = fopen(nome_arquivo, "r");
       if (!arquivo) {
            printf("ERRO NA LEITURA OU FIM DE LEITURA\n");
        } else {
            arquivoId += 1; 
            while (fscanf(arquivo, "%s", palavra) != EOF) {
                int i = 0;

                while (palavra[i]) {
                    if (isupper(palavra[i])) {
                        palavra[i] = tolower(palavra[i]);
                    }
                    i++;
                }

               //verifico se a ultima posição da palavra é um sinal de pontuação se sim substituo por \0
                int cont=strlen(palavra);
                if((palavra[cont-1]>=33 && palavra[cont-1]<=47 )|| (palavra[cont-1]>=58 && palavra[cont-1]<=64)){
                    palavra[cont-1]='\0';
                   
                }
                strcpy(palavra_aux,palavra);

                pat = Insere(palavra_aux, pat, arquivoId);
            }
            fclose(arquivo);
        free(arquivo);
        }
    }
                
        }else if(opcao=='b'){
                Busca(pat);
        }else if(opcao=='c'){
              //  Consulta(pat,arquivoId);
            Termos termos[5];
            int total_palavras=0, tam,qtd_pal_arq;
                Guarda_termos(pat,&total_palavras,termos);
                //Qtd_palavras_em_arquivo(TipoLista Lista,int arquivoId, char *palavra);
                printf(" Total de palavras %d\n",total_palavras);
               // printf("%d\n",Qtd_palavras_em_arquivo(pat,"casa",1));


                    for(int i=0;i<total_palavras;i++){
                     printf("%s",termos[i].termo);
                      tam=0;
                     printf(" APARECE EM %d  ARQUIVOS",Qtd_arquivos_por_palavra(pat, termos[i].termo, &tam));
                    }
            strcpy(palavra_aux,"quer");
            
          printf("A palavra aparece x vezes no documento y %d \n",Qtd_palavras_em_arquivo(pat, palavra_aux,arquivoId,&qtd_pal_arq));
        

}
    }
    
return 0;

}



//TRIE
/* struct node *h = 0;
    h = read_keys(h, "a.txt");
    char s[MAX];
    scanf("%s", s);
    char dat[100] = "";
    search(h, s, dat);*/

