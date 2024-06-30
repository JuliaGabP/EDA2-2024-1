#include <stdio.h>
#include <stdlib.h>
typedef struct {
  double v;
  int i, j;
} a;
static void merge(a *v, int l, int m, int r) {
  a *aux;
  aux = malloc((r - l) * sizeof(a));
  int i = l, j = m, k = 0;
  while (i < m && j < r) {
    if (v[i].v > v[j].v){
      aux[k++] = v[i++];
    }
    else if (v[i].v == v[j].v && v[i].i < v[j].i){
      aux[k++] = v[i++];
    }
    else if (v[i].v == v[j].v && v[i].i == v[j].i && v[i].j < v[j].j){
      aux[k++] = v[i++];
    }
    else
      aux[k++] = v[j++];
  }
  while (i < m) aux[k++] = v[i++];
  while (j < r) aux[k++] = v[j++];
  for (i = l; i < r; ++i) v[i] = aux[i - l];
  free(aux);
}
void mergeSort(a *v, int l, int r) {
  if (l < r - 1) {
    int middle = (l + r) / 2;
    mergeSort(v, l, middle);
    mergeSort(v, middle, r);
    merge(v, l, middle, r);
  }
}
int main() {
  int casos;
  scanf("%d", &casos);
  while (casos--) {
    int m, n, cont = 0;
    scanf("%d %d", &m, &n);
    a vect[n * m];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        scanf("%lf", &vect[cont].v), vect[cont].i = i, vect[cont].j = j, cont++;
    mergeSort(vect, 0, n * m);
    for (int i = 0; i < n * m; i++)
      (i < ((n * m) - 1) ? printf("%d,%d ", vect[i].i + 1, vect[i].j + 1)
                         : printf("%d,%d\n", vect[i].i + 1, vect[i].j + 1));
  }
}