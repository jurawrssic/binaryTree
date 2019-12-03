#include <stdio.h>
#include <stdlib.h>
#include "binarieTree.c"
int main()
{
    node *T;
    startTree(&T);
    insertNode(&T, 10);
    insertNode(&T, 20);
    insertNode(&T, 22);
    insertNode(&T, 40);
    insertNode(&T, 44);
    insertNode(&T, 5);
    pOrder(T);
    printf("\nA altura da arvore eh de: %d", findAltura(T));
}
