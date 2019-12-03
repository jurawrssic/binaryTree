#include <stdio.h>
#include <stdlib.h>
#include "binarieTree.h"

void startTree(node **T){
	(*T) = NULL;
}

int insertNode(node **T, int x){
	if (*T == NULL){
		(*T) = (node*) malloc(sizeof(node));
		if (*T != NULL){
			(*T)->value = x;
			(*T)->LNode = NULL;
			(*T)->RNode = NULL;
			return 1;
		}else{
			return 2;
		}
    }else{
		if (x < (*T)->value){
			insertNode(&((*T) -> LNode),x);
		}else{
			if (x > (*T)->value){
				insertNode(&((*T) -> RNode),x);
			}else{
				return 3;
			}
		}
	}
}

void removeNode(node **T){
	if((*T) != NULL){
		removeNode(&(*T)->LNode);
		removeNode(&(*T)->RNode);
		free(*T);
		(*T) = NULL;
	}
}

int findAltura(node *T){
    if (T == NULL) return -1;
    int altL = findAltura((T)->LNode);
    int altR = findAltura((T)->RNode);
    if (altL < altR) return altR+1;
    else return altL+1;
}

void sOrder(node *T){
	if (T != NULL){
		sOrder(T->LNode);
		printf("\n %d", T->value);
		sOrder(T->RNode);
	}
}

void fOrder (node *T){
	if (T != NULL){
		fOrder(T -> LNode);
		fOrder(T -> RNode);
		printf("\n %d", T->value);
	}
}

void pOrder(node *T){
	if (T != NULL){
		printf("\n %d", T->value);
		pOrder(T->LNode);
		pOrder(T->RNode);
	}
}

void printTree(node *T){
	if(T != NULL){
		if ((T->LNode == NULL) && (T->RNode == NULL)){
			printf("%d ", T->value);
		}else{
			printTree(T->LNode);
			printTree(T->RNode);
		}
	}
}

node *searchNode(node **T, int x){
	if (*T == NULL) return NULL;
	node *p;
    if((*T)->value == x){
        return *T;
    }else{
        if(x < (*T)->value){
            p = (node*) searchNode(&((*T)->LNode),x);
            return p;
        }else{
            p = (node*)searchNode(&((*T)->RNode),x);
            return p;
        }
    }
}


