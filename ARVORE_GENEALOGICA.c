#include <stdio.h>
#include <string.h>
int M, N;
int adj[300][300];
int visited[300];

void dfs(int person) {
    visited[person] = 1;
    for (int i = 0; i < M; i++) {
        if (adj[person][i] && !visited[i]) {
            dfs(i);
        }
    }
}
int main() {
    scanf("%d %d", &M, &N);
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    char names[M][31];
    int name_to_index[300];
    int name_count = 0;
    for (int i = 0; i < N; i++) {
        char name1[31], relation[11], name2[31];
        scanf("%s %s %s", name1, relation, name2);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < name_count; j++) {
            if (strcmp(names[j], name1) == 0) {
                idx1 = j;
                break;
            }
        }
        if (idx1 == -1) {
            strcpy(names[name_count], name1);
            idx1 = name_count;
            name_count++;
        }
        for (int j = 0; j < name_count; j++) {
            if (strcmp(names[j], name2) == 0) {
                idx2 = j;
                break;
            }
        }
        if (idx2 == -1) {
            strcpy(names[name_count], name2);
            idx2 = name_count;
            name_count++;
        }
        adj[idx1][idx2] = 1;
        adj[idx2][idx1] = 1;
    }
    int families_count = 0;
    for (int i = 0; i < M; i++) {
        if (!visited[i]) {
            dfs(i);
            families_count++;
        }
    }
    printf("%d\n", families_count);
    return 0;
}

