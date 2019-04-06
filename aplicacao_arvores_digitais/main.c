#include <stdio.h>
#include <string.h>
#include "tst.h"
#include "patricia.h"
#include <sys/time.h>
#include <stdlib.h>

int main()
{
    struct Node *root = NULL;
    TipoPilha pilha_arv;
    TipoItem item;

   /* insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "bu")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "cat")? printf("Found\n"): printf("Not Found\n");

    FPVazia(&pilha_arv);
    strcpy(item.prefixo,"ca");

    int comp = print_auto_complete(root,item,&pilha_arv);

    if (comp == 0)
        printf("No string found with this prefix\n");

*/
    TipoArvore a = NULL;
    char c;
    int  i, j, k, n;
    int  min = 1, max = 4;
    char vetor[95];
    /* Gera uma permutacao aleatoria de chaves dos caracteres ASCII 32 a  126 */
    struct timeval semente;
    gettimeofday(&semente,NULL);
    srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));
    for (i = min; i <= max; i++)
        vetor[i - 32] = i;
    for (i = min; i <= max; i++)
    { k = min + (int) ((float)(max - min) * rand()/(RAND_MAX + 1.0));
        j = min + (int) ((float)(max - min) * rand()/(RAND_MAX + 1.0));
        n = vetor[k - 32]; vetor[k - 32] = vetor[j - 32]; vetor[j - 32] = n;
    }
    /* Insere cada chave na arvore */
    for (i = min; i <= max; i++)
    { c = vetor[i - 32]; printf("Inserindo chave: %c\n", c);
        a = Insere(c, &a);
    }
    /* Gera outra permutacao aleatoria de chaves */
    for (i = min; i <= max; i++)
    { k = min + (int) ((float)(max-min) * rand()/(RAND_MAX + 1.0));
        j = min + (int) ((float)(max-min) * rand()/(RAND_MAX + 1.0));
        n = vetor[k - 32]; vetor[k - 32] = vetor[j - 32]; vetor[j - 32] = n;
    }
    /* Pesquisa cada chave na arvore */
    for (i = min; i <= max; i++)
    { c = vetor[i - 32]; printf("Pesquisando chave: %c\n", c);
        Pesquisa(c, a);
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