#include <stdio.h>
#define fileirastotais 20
#define lugarestotais 25
void sala(char mapa[fileirastotais][lugarestotais], int fileiras, int lugares)
{
  printf("  ");
  for(int i = 1; i <= lugares; i++)
  {
    printf("%02d ", i);
  }
  printf("\n");
  for(int j = fileiras - 1; j >= 0; j--)
  {
    printf("%c ", 'A' + j);
    for (int i = 0; i < lugares; i++)
    {
      if (mapa[j][i] == 'X')
      {
        printf("XX ");
      }
      else
      {
        printf("-- ");
      }
    }
    printf("\n");
  }
}
int main()
{
  int fileiras, lugares, fila;
  char coluna, mapa[fileirastotais][lugarestotais];
  scanf("%d %d", &fileiras, &lugares);
  for (int j = 0; j < fileiras; j++)
  {
    for (int i = 0; i < lugares; i++)
    {
      mapa[j][i] = '-';
    }
  }
  while (scanf(" %c%d", &coluna, &fila) != EOF)
  {
    mapa[coluna - 'A'][fila - 1] = 'X';
  }
  sala(mapa, fileiras, lugares);
  return 0;
}