
// A node of ternary search tree
#define ALPHABET_SIZE 26
#include<stdbool.h>
struct node {
    int data;
    struct node *array[26];
};


struct node* new_node(struct node *h);
struct node* insert(struct node *h, char *c, int value);
int dfs(struct node *h, char *dat);
void search(struct node *h, char *s, char *dat);
struct node* read_keys(struct node *h, char *file);
