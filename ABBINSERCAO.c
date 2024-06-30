#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;
no* novo_no(int chave) {
    no* node = (no*)malloc(sizeof(no));
    node->chave = chave;
    node->esq = node->dir = NULL;
    return node;
}
no* inserir(no *r, int x) {
    if (r == NULL) {
        return novo_no(x);
    }
    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    return r;
}