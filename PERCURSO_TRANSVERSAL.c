#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no {
    char dado;
    struct no *esq, *dir;
} no;
no* novo_no(char dado) {
    no* node = (no*)malloc(sizeof(no));
    node->dado = dado;
    node->esq = node->dir = NULL;
    return node;
}
int encontrar_posicao(char* str, char valor, int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        if (str[i] == valor) {
            return i;
        }
    }
    return -1;
}
no* construir_arvore(char* pre_ordem, char* in_ordem, int inicio, int fim, int* indice_pre) {
    if (inicio > fim) {
        return NULL;
    }
    char atual = pre_ordem[*indice_pre];
    (*indice_pre)++;
    no* node = novo_no(atual);
    if (inicio == fim) {
        return node;
    }
    int pos = encontrar_posicao(in_ordem, atual, inicio, fim);
    node->esq = construir_arvore(pre_ordem, in_ordem, inicio, pos - 1, indice_pre);
    node->dir = construir_arvore(pre_ordem, in_ordem, pos + 1, fim, indice_pre);

    return node;
}
void imprimir_pos_ordem(no* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimir_pos_ordem(raiz->esq);
    imprimir_pos_ordem(raiz->dir);
    printf("%c", raiz->dado);
}
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int N;
        char S1[53], S2[53];
        scanf("%d %s %s", &N, S1, S2);
        int indice_pre = 0;
        no* raiz = construir_arvore(S1, S2, 0, N - 1, &indice_pre);
        imprimir_pos_ordem(raiz);
        printf("\n");
    }
    return 0;
}
