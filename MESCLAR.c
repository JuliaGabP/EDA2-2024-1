#include <stdio.h>
#include <stdlib.h>
#define less(A,B) (A < B)

typedef struct celula {
  int data;
  struct celula *next;
}celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
  celula *end = l3;
  l1 = l1->next; l2 = l2->next;
  while (l1 && l2) {
    if (less(l1->data, l2->data)) {
      end->next = l1;
      end = end->next;
      l1 = l1->next;
      end->next = NULL;
    } else {
      end->next = l2;
      end = end->next;
      l2 = l2->next;
      end->next = NULL;
    }
  }
  if (l1) end->next = l1;
  else end->next = l2;
}