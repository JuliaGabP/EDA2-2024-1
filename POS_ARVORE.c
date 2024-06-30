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
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    stack *s = NULL;
    no *current = raiz;
    no *last_visited = NULL;
    while (!is_empty(s) || current != NULL) {
        if (current != NULL) {
            push(&s, current);
            current = current->esq;
        } else {
            no *peek_node = s->node;
            if (peek_node->dir != NULL && last_visited != peek_node->dir) {
                current = peek_node->dir;
            } else {
                printf("%d ", peek_node->dado);
                last_visited = pop(&s);
            }
        }
    }
    printf("\n");
}
