#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void remove_depois (celula *p){
    celula *ptr = p -> prox;
    if(p -> prox == NULL)
        return;
    else{
        p -> prox = p -> prox -> prox;
        free(ptr);
    }
}

void remove_elemento (celula *le, int x){
    celula *ptr = le -> prox;
    if(ptr == NULL)
        return;
    else if(ptr -> dado == x){
        le -> prox = le -> prox -> prox;
        free(ptr);
    }
    else
        return remove_elemento(ptr, x);
}

void remove_todos_elementos (celula *le, int x){
    celula *ptr = le -> prox;
    celula *aux;
    if(ptr == NULL)
        return;
    else if(ptr -> dado == x){
        aux = ptr;
        le -> prox = ptr -> prox;
        free(aux);
    }
    else
        le = ptr;
    return remove_todos_elementos(le, x);
}