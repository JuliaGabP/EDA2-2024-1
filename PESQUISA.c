#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int var;
    char value[30];
} instrucao;
#define T instrucao
#define menos(a, b) a.var < b.var
#define troca(a, b) \
    T t = a;       \
    a = b;         \
    b = t;

void sort(T *v, int size)
{
    for (int i = size - 1; i > 0; i--)
        if (menos(v[i], v[0]))
        {
            troca(v[0], v[i]);
        }
    for (int i = 2, j; i < size; i++)
    {
        T t = v[i];
        for (j = i; menos(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

char *find(T *v, int size, int var)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m].var == var)
            return v[m].value;

        if (v[m].var > var)
            r = m - 1;
        else
            l = m + 1;
    }
    return "undefined";
}

int main()
{
    int n;
    scanf(" %d", &n);
    T *v = (T *)malloc(n * sizeof(T));

    for (int i = 0; i < n; i++)
        scanf("%d %s", &v[i].var, v[i].value);

    sort(v, n);

    for (int code; scanf(" %d", &code) == 1;)
        printf("%s\n", find(v, n, code));

    return 0;
}