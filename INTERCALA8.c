#include <stdio.h>
#include <stdlib.h>
#define compmenor(A, B) ((A) <= (B))
#define menor(A, B) ((A) < (B))
#define troca(A, B) \
  {                \
    int temp;      \
    temp = A;      \
    A = B;         \
    B = temp;      \
  }
#define comp_troca(A, B)        \
  {                              \
    if (menor(B, A)) troca(A, B); \
  }
int particao(int *vetor, int inicio, int fim) {
  int pivo = vetor[fim], i = inicio - 1, j = fim;
  while (1) {
    while (menor(vetor[++i], pivo));
    while (menor(pivo, vetor[--j]))
      if (j == inicio){ 
        break;
      }
    if (i >= j){ 
      break;
    }
    troca(vetor[i], vetor[j]);
  }
  troca(vetor[i], vetor[fim]);
  return i;
}
void ordena_rapido(int *vetor, int inicio, int fim) {
  if (fim <= inicio) return;
  comp_troca(vetor[(inicio + fim) / 2], vetor[fim]);
  comp_troca(vetor[inicio], vetor[(inicio + fim) / 2]);
  comp_troca(vetor[fim], vetor[(inicio + fim) / 2]);
  int pivo = particao(vetor, inicio, fim);
  ordena_rapido(vetor, inicio, pivo - 1);
  ordena_rapido(vetor, pivo + 1, fim);
}
int main() {
  int *vetor, j = 0, total_elementos = 0;
  int num_elementos = 9 * 1000000;
  vetor = malloc(num_elementos * sizeof(int));
  for (int i = 0; i < 8; i++) {
    int n;
    scanf("%d", &n);
    total_elementos += n;
    while (n--) scanf("%d", &vetor[j++]);
  }
  ordena_rapido(vetor, 0, total_elementos - 1);
  for (int i = 0; i < total_elementos; i++) {
    if (i == total_elementos - 1)
      printf("%d\n", vetor[i]);
    else
      printf("%d ", vetor[i]);
  }
  return 0;
}