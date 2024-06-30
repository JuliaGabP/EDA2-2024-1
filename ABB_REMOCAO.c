#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;
no* maximo(no *r) {
    while (r->dir != NULL) {
        r = r->dir;
    }
    return r;
}
no* remover(no *r, int x) {
    if (r == NULL) {
        return NULL; 
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x);
    } else {
        if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        }
        no *temp = maximo(r->esq);
        r->chave = temp->chave;
        r->esq = remover(r->esq, temp->chave);
    }

    return r;
}