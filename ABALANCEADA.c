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
void inserir(no** nos, int pai, int filho) {
    if (nos[pai]->esq == NULL) {
        nos[pai]->esq = nos[filho];
    } else {
        nos[pai]->dir = nos[filho];
    }
}
int verificar_balanceamento(no* raiz, int* balanceada) {
    if (raiz == NULL) {
        return 0;
    }
    int altura_esq = verificar_balanceamento(raiz->esq, balanceada);
    int altura_dir = verificar_balanceamento(raiz->dir, balanceada);
    if (abs(altura_esq - altura_dir) > 1) {
        *balanceada = 0;
    }
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}
int main() {
    int N;
    scanf("%d", &N);
    no** nos = (no**)malloc((N + 1) * sizeof(no*));
    for (int i = 1; i <= N; i++) {
        nos[i] = novo_no(i);
    }
    for (int i = 2; i <= N; i++) {
        int pai;
        scanf("%d", &pai);
        inserir(nos, pai, i);
    }
    int balanceada = 1;
    verificar_balanceamento(nos[1], &balanceada);
    if (balanceada) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    for (int i = 1; i <= N; i++) {
        free(nos[i]);
    }
    free(nos);
    return 0;
}