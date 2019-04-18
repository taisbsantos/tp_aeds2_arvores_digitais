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

                pat = Insere(palavra, pat, arquivoId);
            }
            fclose(arquivo);
        }
    }
                
        }else if(opcao=='b'){
                Busca(pat);
        }else if(opcao=='c'){
                Consulta(pat,arquivoId);
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

