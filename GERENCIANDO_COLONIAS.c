#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 1048576
typedef struct AlimentoNode {
    char alimento[11];
    struct AlimentoNode* next;
} AlimentoNode;
typedef struct Colonia {
    int id;
    AlimentoNode* alimentos;
    struct Colonia* next;
} Colonia;
Colonia* tabela[TABLE_SIZE];
unsigned int hash(int id) {
    return id % TABLE_SIZE;
}
AlimentoNode* criar_alimento_node(const char* alimento) {
    AlimentoNode* novo_node = (AlimentoNode*)malloc(sizeof(AlimentoNode));
    strcpy(novo_node->alimento, alimento);
    novo_node->next = NULL;
    return novo_node;
}
Colonia* criar_colonia(int id) {
    Colonia* nova_colonia = (Colonia*)malloc(sizeof(Colonia));
    nova_colonia->id = id;
    nova_colonia->alimentos = NULL;
    nova_colonia->next = NULL;
    return nova_colonia;
}
int inserir_alimento(int id, const char* alimento) {
    unsigned int indice = hash(id);
    Colonia* colonia = tabela[indice];
    while (colonia != NULL) {
        if (colonia->id == id) {
            AlimentoNode* atual = colonia->alimentos;
            while (atual != NULL) {
                if (strcmp(atual->alimento, alimento) == 0) {
                    return 1; 
                }
                atual = atual->next;
            }
            AlimentoNode* novo_alimento = criar_alimento_node(alimento);
            novo_alimento->next = colonia->alimentos;
            colonia->alimentos = novo_alimento;
            return 0;
        }
        colonia = colonia->next;
    }
    Colonia* nova_colonia = criar_colonia(id);
    nova_colonia->next = tabela[indice];
    tabela[indice] = nova_colonia;
    AlimentoNode* novo_alimento = criar_alimento_node(alimento);
    nova_colonia->alimentos = novo_alimento;
    return 0; 
}
int main() {
    int id;
    char alimento[11];
    memset(tabela, 0, sizeof(tabela));
    while (scanf("%d %s", &id, alimento) != EOF) {
        if (inserir_alimento(id, alimento)) {
            printf("%d\n", id);
        }
    }
    return 0;
}
