#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x);
celula *busca_rec (celula *le, int x);

celula *busca (celula *le, int x){
    celula *ponteiro;
    ponteiro = le;
    while (ponteiro != NULL && ponteiro->dado != x){
        ponteiro = ponteiro->prox;
    }
    return ponteiro;
}

celula *busca_rec (celula *le, int x){
    if(le != NULL && le->dado != x)
        busca_rec(le->prox, x);
    else return le;
}