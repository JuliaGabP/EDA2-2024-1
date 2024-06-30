#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main() { 
  int n, m, j; scanf("%d %d %d", &n, &m, &j);
  int matriz[n+1][n+1];
  for (int i = 0; i <= n; i++) 
    for (int k = 0; k <= n; k++) 
      matriz[i][k] = 0;
  for (int v = 0; v < n; v++) {
    int a; scanf("%d", &a);
    for (int k = 0; k < a; k++) {
      int w; scanf("%d", &w);
      matriz[v][w] = 1;
    }
  }
  bool visita[2000] = {false};
  for (int i = 0; i < m; i++) {
    int x; scanf("%d", &x);
    visita[x] = true;
    for(int k = 0; k <= n; k++) {
      if(matriz[x][k]) visita[k] = true;
    }
  }
  for (int i = 0; i < j; i++) {
    int q;
    scanf("%d", &q);
    if(visita[q]) printf("Eu vou estar la\n");
    else printf("Nao vou estar la\n");
  }
  return 0;
}