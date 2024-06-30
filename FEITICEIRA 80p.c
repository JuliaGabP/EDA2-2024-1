#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define CAPACIDADE_INICIAL 1000000  
typedef struct Item {
    long codigo, quantidade;
    struct Item* prox;
} Item;
typedef struct {
    Item** tabela;
    long capacidade, tamanho;
} HashTable;
unsigned int hash(long codigo, long capacidade) {
    return ((unsigned int)codigo) % capacidade;
}
HashTable* criarHashTable(int capacidade) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->tabela = (Item**)malloc(capacidade * sizeof(Item*));
    for (int i = 0; i < capacidade; i++) {
        ht->tabela[i] = NULL;
    }
    ht->capacidade = capacidade;
    ht->tamanho = 0;
    return ht;
}
Item* encontrarItem(HashTable* ht, long codigo) {
    unsigned int indice = hash(codigo, ht->capacidade);
    Item* item = ht->tabela[indice];
    while (item != NULL) {
        if (item->codigo == codigo) {
            return item;
        }
        item = item->prox;
    }
    return NULL;
}
void atualizarHashTable(HashTable* ht, long codigo, long quantidade) {
    if (quantidade == 0) return;
    unsigned int indice = hash(codigo, ht->capacidade);
    Item* item = encontrarItem(ht, codigo);
    if (item != NULL) {
        if (quantidade < 0) {
            if (item->quantidade + quantidade >= 0) {
                item->quantidade += quantidade;
            }
        } else {
            item->quantidade += quantidade;
        }
    } else if (quantidade > 0) {
        Item* novoItem = (Item*)malloc(sizeof(Item));
        novoItem->codigo = codigo;
        novoItem->quantidade = quantidade;
        novoItem->prox = ht->tabela[indice];
        ht->tabela[indice] = novoItem;
        ht->tamanho++;
    }
}
int main() {
    long n, codigo, quantidade;
    HashTable* ht = criarHashTable(CAPACIDADE_INICIAL);
    scanf("%li", &n);
    for (int i = 0; i < n; i++) {
        scanf("%li %li", &codigo, &quantidade);
        atualizarHashTable(ht, codigo, quantidade);
    }
    long totalItens = 0;
    for (int i = 0; i < ht->capacidade; i++) {
        Item* item = ht->tabela[i];
        while (item != NULL) {
            totalItens += item->quantidade;
            item = item->prox;
        }
    }
    printf("%li\n", totalItens);
    return 0;
}
