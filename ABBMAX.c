#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;
no* maximo(no *r) {
    if (r == NULL) {
        return NULL;  
    }
    no *atual = r;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual; 
}