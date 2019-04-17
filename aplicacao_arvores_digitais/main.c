#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"
#include "patricia.h"
#include <ctype.h>


int main() {
    FILE *arquivo;
    char nome_arquivo[20],palavra[50];
    int arquivoId = 0;
    TipoPatNo *pat;

    inicializa_pat(&pat);


    //printf("Nome arquivo: ");
    //scanf("%s", nome_arquivo);
    strcpy(nome_arquivo,"a.txt");

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("ERRO NA LEITURA");
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

            //printf("\n\n --> %s <--\n\n",pat->NO.palavra);

        }
    }

    fclose(arquivo);
    Pesquisa("lua", pat);

    }



//TRIE
/* struct node *h = 0;
    h = read_keys(h, "a.txt");
    char s[MAX];
    scanf("%s", s);
    char dat[100] = "";
    search(h, s, dat);*/

