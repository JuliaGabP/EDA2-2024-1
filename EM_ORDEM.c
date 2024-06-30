#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;
typedef struct stack {
    no *node;
    struct stack *next;
} stack;
void push(stack **top, no *node) {
    stack *new_node = (stack *)malloc(sizeof(stack));
    new_node->node = node;
    new_node->next = *top;
    *top = new_node;
}
no* pop(stack **top) {
    if (*top == NULL) {
        return NULL;
    }
    stack *temp = *top;
    no *node = temp->node;
    *top = (*top)->next;
    free(temp);
    return node;
}
int is_empty(stack *top) {
    return top == NULL;
}
void em_ordem(no *raiz) {
    stack *s = NULL;
    no *current = raiz;
    while (!is_empty(s) || current != NULL) {
        while (current != NULL) {
            push(&s, current);
            current = current->esq;
        }
        current = pop(&s);
        printf("%d ", current->dado);
        current = current->dir;
    }
    printf("\n");
}