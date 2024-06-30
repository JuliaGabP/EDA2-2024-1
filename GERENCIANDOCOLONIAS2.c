#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE (1 << 20)
typedef struct Node {
    int colony;
    char food[11];
    struct Node* next;
} Node;
typedef struct {
    Node* table[TABLE_SIZE];
} HashTable;
unsigned int hash(int colony, const char* food) {
    unsigned long hash = colony;
    while (*food) {
        hash = (hash * 31) + *food++;}
    return hash % TABLE_SIZE;}
void initTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        ht->table[i] = NULL;}}
int checkAndAdd(HashTable* ht, int colony, const char* food) {
    unsigned int index = hash(colony, food);
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->colony == colony && strcmp(current->food, food) == 0) {
            return 1;}
        current = current->next;}
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->colony = colony;
    strcpy(newNode->food, food);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
    return 0;}
void freeTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);}}}
int main() {
    HashTable ht;
    initTable(&ht);
    int colony;
    char food[11];
    while (scanf("%d %s", &colony, food) != EOF) {
        if (checkAndAdd(&ht, colony, food)) {
            printf("%d\n", colony);
        }
    }
    freeTable(&ht);
    return 0;}