#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"
#include "patricia.h"
#include <sys/time.h>
#include <ctype.h>


int main() {
    FILE *arquivo;
    char nome_arquivo[20],palavra[50];
    TipoPatNo *pat;

    inicializa_pat(&pat);
    strcpy(nome_arquivo,"a.txt");

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("ERRO NA LEITURA");
    }
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        int i=0;


        while (palavra[i])
        {
            if(isupper(palavra[i]))
            {
                palavra[i]=tolower(palavra[i]);
            }
            i++;
        }

        pat =Insere(palavra,pat);

    }
    fclose(arquivo);
    Pesquisa("pablocleyton",pat);

    }



//TRIE
/* struct node *h = 0;
    h = read_keys(h, "a.txt");
    char s[MAX];
    scanf("%s", s);
    char dat[100] = "";
    search(h, s, dat);*/

