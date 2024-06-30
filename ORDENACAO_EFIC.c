#include <stdio.h>
#include <stdlib.h>
int verificaVetor(int *vetor, int n) {
  int r = 0;
  for (int contador = 1; contador < n; contador++) {
    if (vetor[contador] < vetor[contador - 1]) {
      r = 1;
      return r;
    }
  }
  return r;
}
void intercala(int *vetor, int comeco, int meio, int final) {
  int *w = malloc((final - comeco + 1) * sizeof(int));
  int contador = comeco, contador2 = meio + 1, k = 0;
  while (contador <= meio && contador2 <= final) {
    if (vetor[contador] < vetor[contador2]) {
      w[k++] = vetor[contador++];
    } else {
      w[k++] = vetor[contador2++];
    }
  }
  while (contador <= meio) {
    w[k++] = vetor[contador++];
  }
  while (contador2 <= final) {
    w[k++] = vetor[contador2++];
  }
  for (k = 0, contador = comeco; contador <= final; contador++, k++) {
    vetor[contador] = w[k];
  }
}
void mergeSort(int *vetor, int comeco, int final) {
  int meio = (comeco + final) / 2;
  if (comeco < final) {
    mergeSort(vetor, comeco, meio);
    mergeSort(vetor, meio + 1, final);
    intercala(vetor, comeco, meio, final);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int vetor[n], contador;
  for (contador = 0; contador < n; contador++) {
    scanf("%d", &vetor[contador]);
  }
  if (verificaVetor(vetor, n) == 0) {
    for (contador = 0; contador < n; contador++) {
      if (contador == n - 1) {
        printf("%d", vetor[contador]);
      } else {
        printf("%d ", vetor[contador]);
      }
    }
    return 0;
  } else if (verificaVetor(vetor, n) == 1) {
    mergeSort(vetor, 0, n - 1);
    for (contador = 0; contador < n; contador++) {
      if (contador == n - 1) {
        printf("%d", vetor[contador]);
      } else {
        printf("%d ", vetor[contador]);
      }
    }
    return 0;
  }
  return 0;
}