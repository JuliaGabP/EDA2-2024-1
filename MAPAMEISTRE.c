#include <stdio.h>
#include <string.h>
char grid[123][123];
int m, n;
typedef struct { int first, second; } ii;
const ii XY[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int mp[256] = {0};
int dfs(int x, int y, int dir) {
    if(grid[x][y] == '*') {
        return 1;
    }
    if(grid[x][y] == 'X' || !grid[x][y]) {
        return 0;
    }
    if(mp[(int)grid[x][y]]) {
        dir = mp[(int)grid[x][y]];
    }
    grid[x][y] = 'X';
    int u = x + XY[dir].first;
    int v = y + XY[dir].second;
    return dfs(u, v, dir);
}
int main() {
    mp['^'] = 0;
    mp['>'] = 1;
    mp['v'] = 2;
    mp['<'] = 3;
    memset(grid, 0, sizeof grid);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%s", &grid[i][1]);
    }
    int ans = dfs(1, 1, mp[(int)grid[1][1]]);
    printf("%s\n", ans ? "*" : "!");
    return 0;
}