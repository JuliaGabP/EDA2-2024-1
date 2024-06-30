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
void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    stack *s = NULL;
    push(&s, raiz);

    while (!is_empty(s)) {
        no *current = pop(&s);
        printf("%d ", current->dado);

        if (current->dir != NULL) {
            push(&s, current->dir);
        }
        if (current->esq != NULL) {
            push(&s, current->esq);
        }
    }
    printf("\n");
}