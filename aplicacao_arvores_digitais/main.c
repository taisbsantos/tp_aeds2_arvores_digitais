#include <stdio.h>
#include "tst.h"
#include <string.h>
int main()
{
    struct Node *root = NULL;
    TipoPilha *pilha_arv;
    TipoItem item;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "bu")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "cat")? printf("Found\n"): printf("Not Found\n");

    FPVazia(pilha_arv);
    strcpy(item.prefixo,"ca");

    int comp = print_auto_complete(root,item,pilha_arv);

    if (comp == -1)
        printf("No other strings found with this prefix\n") ;

    else if (comp == 0)
        printf("No string found with this prefix\n");

    return 0;
}
