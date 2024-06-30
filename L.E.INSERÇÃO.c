#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) { 
    celula *ponteiro = malloc (sizeof (celula));
    if(ponteiro == NULL) exit(EXIT_FAILURE);
    ponteiro->dado = x;
    ponteiro->prox = le->prox;
    le->prox = ponteiro;
}

void insere_antes (celula *le, int x, int y){
    celula *ponteiro = malloc (sizeof (celula));
    if(ponteiro == NULL) exit(EXIT_FAILURE);

    if(le -> prox == NULL || le -> prox -> dado == y){
        ponteiro->dado = x;
        ponteiro->prox = le->prox;
        le->prox = ponteiro;
    }else{
        return insere_antes(le -> prox, x, y);
    }
}