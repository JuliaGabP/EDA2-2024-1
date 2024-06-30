#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 1000000
typedef struct {
    int *data, size, capacity;
} MinHeap;
typedef struct {
    int *data, size, capacity;
} MaxHeap;
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->data = (int*) malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;}
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;
    if (smallest != idx) {
        int temp = heap->data[idx];
        heap->data[idx] = heap->data[smallest];
        heap->data[smallest] = temp;
        minHeapify(heap, smallest);}}
int extractMin(MinHeap* heap) {
    if (heap->size <= 0)
        return INT_MAX;
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];}
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;}
void insertMinHeap(MinHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, heap->capacity * sizeof(int));}
    int i = heap->size++;
    heap->data[i] = key;
    while (i != 0 && heap->data[(i - 1) / 2] > heap->data[i]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;}}
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    heap->data = (int*) malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;}
void maxHeapify(MaxHeap* heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;
    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;
    if (largest != idx) {
        int temp = heap->data[idx];
        heap->data[idx] = heap->data[largest];
        heap->data[largest] = temp;
        maxHeapify(heap, largest);}}
int extractMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return INT_MIN;
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];}
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return root;}
void insertMaxHeap(MaxHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, heap->capacity * sizeof(int));}
    int i = heap->size++;
    heap->data[i] = key;
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;}}
int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    MinHeap* Ta = createMinHeap(N);
    MaxHeap* Tb = createMaxHeap(N);
    for (int i = 0; i < N; i++) {
        int Ai;
        scanf("%d", &Ai);
        insertMinHeap(Ta, Ai);}
    int combinedCount = 0;
    int* combined = (int*) malloc(N * sizeof(int));
    int combinedIndex = 0;
    while (Ta->size > 0) {
        int minTa = extractMin(Ta);
        if (Tb->size > 0) {
            int maxTb = Tb->data[0];  
            if (abs(minTa - maxTb) <= X && minTa != maxTb) {
                extractMax(Tb);  
                combined[combinedIndex++] = minTa + maxTb;
                combinedCount++;
                continue;}}
        insertMaxHeap(Tb, minTa);}
    printf("%d\n", combinedCount);
    for (int i = 0; i < combinedIndex; i++) {
        if (i > 0) {
            printf(" ");}
        printf("%d", combined[i]);}
    printf("\n");
    free(combined);
    free(Ta->data);
    free(Ta);
    free(Tb->data);
    free(Tb);
    return 0;}