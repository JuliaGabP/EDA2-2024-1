#include <stdio.h>

int main()
{
    int n, m; 
    int p;   
    int A, B;
    scanf("%d %d", &n, &m);
    scanf("%d", &p);
    int aposicaox = 1, aposicaoy = 1, bposicaox = n, bposicaoy = m; 
    for (int passo = 1; passo <= p; passo++)
    {
        scanf("%d %d", &A, &B);
        switch (A)
        {
        case 1:
            aposicaoy++;
            break;
        case 2:
            aposicaoy--;
            break;
        case 3:
            aposicaox++;
            break;
        case 4:
            aposicaox--;
            break;
        }
        if (aposicaox < 1 || aposicaox > n || aposicaoy < 1 || aposicaoy > m)
        {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", aposicaox, aposicaoy, passo);
            return 0;
        }
        switch (B)
        {
        case 1:
            bposicaoy++;
            break;
        case 2:
            bposicaoy--;
            break;
        case 3:
            bposicaox++;
            break;
        case 4:
            bposicaox--;
            break; 
        }
        if (bposicaox < 1 || bposicaox > n || bposicaoy < 1 || bposicaoy > m)
        {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", bposicaox, bposicaoy, passo);
            return 0;
        }
        if (aposicaox == bposicaox && aposicaoy == bposicaoy)
        {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", aposicaox, aposicaoy, passo);
            return 0;
        }
    }
    printf("Nao se encontraram\n");
    return 0;
}