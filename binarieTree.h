#ifndef BINARIETREE_H
#define BINARIETREE_H

typedef struct Node{
    int value;
    struct Node *LNode;
    struct Node *RNode
}node;

void startTree(node **T);
int insertNode(node **T, int x);
void removeNode(node **T);
int findAltura(node *T);
void sOrder(node *T);
void fOrder(node *T);
void pOrder(node *T);
void printTree(node *T);
node *searchNode(node **T, int x);

#endif
