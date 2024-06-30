#include <stdio.h>
int main () {
  int m, n, x, y, k, direcao, i, minutos = 0, x_atual=0, y_atual=0;
  scanf (" %d %d", &m, &n);
  scanf (" %d %d", &x, &y);
  scanf (" %d", &k);
  for (i = 0; i < k; i++) {
    scanf (" %d", &direcao);
    switch(direcao) {
    case 1: 
      y_atual++;
      break;
    case 2:
      y_atual--;
      break;
    case 3:
      x_atual++;
      break;
    case 4:
      x_atual--;
      break;
    }
    if (x_atual >= x - 1 && x_atual <= x + 1 && y_atual >= y - 1 && y_atual <= y + 1) {
      minutos++;
    }
  }
  printf ("%d\n", minutos);
  return (0);
}
