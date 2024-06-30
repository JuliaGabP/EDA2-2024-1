#include <stdio.h>
#include <stdlib.h>
#define MAXN 200005
int parent[200005], rank[200005], value[200000],n, m;
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}
void union_sets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
            value[root_u] |= value[root_v];
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
            value[root_v] |= value[root_u];
        } else {
            parent[root_v] = root_u;
            value[root_u] |= value[root_v];
            rank[root_u]++;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        value[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        union_sets(u, v);
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            result ^= value[i];
        }
    }
    printf("%d\n", result);
    return 0;
}