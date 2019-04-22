/*   
          AUTORES
Élida Emelly  Matrícula: 3012
Yuri de Faria Matrícula: 3373
Taís B Santos Matricula: 3036

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libs/tst.h"
#include "Libs/patricia.h"
#include <ctype.h>



int main() {
     FILE *arquivo;
    char nome_arquivo[20],palavra[50],palavra_aux[50];
    int arquivoId = 0;     
    Termos termos[5];
    int total_palavras=0, tam,qtd_pal_arq,qtd_termos[5];
    TipoPatNo *pat;
    int i = 0;
    int cont;

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
                

                while (palavra[i]) {
                    if (isupper(palavra[i])) {
                        palavra[i] = tolower(palavra[i]);
                    }
                    i++;
                }
                i = 0;

               //verifico se a ultima posição da palavra é um sinal de pontuação se sim substituo por \0
                cont=strlen(palavra);
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
                //chama função que pega os termos de busca 
                Guarda_termos(pat,&total_palavras,termos,qtd_termos);   
                //chama função que calcula relevancia
                relevancia(pat,arquivoId,total_palavras,termos,&qtd_pal_arq,&tam,qtd_termos);
        }
    }
    
return 0;

}

