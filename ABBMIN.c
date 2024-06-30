#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;
no* minimo(no *r) {
    if (r == NULL) {
        return NULL; 
    }
    no *atual = r;
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual; 
}
