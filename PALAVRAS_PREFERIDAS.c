#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 65540 
#define WORD_SIZE 18  
typedef struct HashNode {
    char palavra[WORD_SIZE];
    int contagem;
    struct HashNode* next;
} HashNode;
HashNode* tabela[TABLE_SIZE];
unsigned int hash(const char* palavra) {
    unsigned int hash = 0;
    while (*palavra) {
        hash = (hash << 5) + *palavra++;
    }
    return hash % TABLE_SIZE;
}
HashNode* encontrar_ou_criar_node(const char* palavra) {
    unsigned int indice = hash(palavra);
    HashNode* node = tabela[indice];
    while (node != NULL) {
        if (strcmp(node->palavra, palavra) == 0) {
            return node;
        }
        node = node->next;
    }
    node = (HashNode*)malloc(sizeof(HashNode));
    strcpy(node->palavra, palavra);
    node->contagem = 0;
    node->next = tabela[indice];
    tabela[indice] = node;
    return node;
}
void computar_voto(const char* palavra) {
    HashNode* node = encontrar_ou_criar_node(palavra);
    node->contagem++;
}
void retornar_contagem(const char* palavra) {
    HashNode* node = encontrar_ou_criar_node(palavra);
    printf("%d\n", node->contagem);
}
void resetar_contagem(const char* palavra) {
    HashNode* node = encontrar_ou_criar_node(palavra);
    node->contagem = 0;
}

int main() {
    int comando;
    char palavra[WORD_SIZE];
    memset(tabela, 0, sizeof(tabela));
    while (scanf("%d %s", &comando, palavra) != EOF) {
        switch (comando) {
            case 1:
                computar_voto(palavra);
                break;
            case 2:
                retornar_contagem(palavra);
                break;
            case 3:
                resetar_contagem(palavra);
                break;
        }
    }
    return 0;
}