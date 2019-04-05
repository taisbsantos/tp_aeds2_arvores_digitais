
// A node of ternary search tree
#define ALPHABET_SIZE 26
#include<stdbool.h>
#include "pilha.h"
struct Node
{
    char data;

    // True if this character is last character of one of the words
    unsigned isEndOfString: 1;
    struct Node *left, *eq, *right,*children[ALPHABET_SIZE];
}Node;

struct Node* newNode(char data);
void insert(struct Node** root, char *word);
void traverseTSTUtil(struct Node* root, char* buffer, int depth);
void traverseTST(struct Node* root);
int searchTST(struct Node *root, char *word);
bool isLastNode(struct Node* root);
void auto_complete(struct Node *cadeia_caracter,char *atual_prefixo,TipoPilha *pilha_arv);
int print_auto_complete( struct Node *root,  char *prefixo,TipoPilha *pilha_arv);
