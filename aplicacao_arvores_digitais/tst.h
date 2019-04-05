
// A node of ternary search tree
#define ALPHABET_SIZE 26
#include<stdbool.h>
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
bool isLastNode(struct TrieNode* root);
void auto_complete(struct Node *string,char *atual_prefixo);
int print_auto_complete(Node *root, const char *prefixo);
