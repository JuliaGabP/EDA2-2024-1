#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula; 

void imprime (celula *le) {
  for (celula *ptr = le -> prox; ptr != NULL; ptr = ptr->prox){
    printf("%d -> ", ptr->dado);
  }
  printf("NULL\n");
}

void imprime_rec (celula *le){
  if(le -> prox != NULL){
    printf("%d -> ", le -> prox -> dado);
    imprime_rec(le -> prox);
  }else
    printf("NULL\n");
}