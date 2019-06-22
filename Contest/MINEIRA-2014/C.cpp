#include <stdio.h>
#include <cstring>

int v[1025][1025], vis[1025][1025];

int n;

void dfs(int i, int j, int t) {

    vis[i][j] = true;
    if(!vis[i][j+1] && v[i][j+1] < t && j + 1 < n) dfs(i, j + 1, t);
    if(!vis[i+1][j] && v[i+1][j] < t && i + 1 < n) dfs(i + 1, j, t);
    if(!vis[i][j-1] && v[i][j-1] < t && j - 1 >= 0) dfs(i, j - 1, t);
    if(!vis[i-1][j] && v[i-1][j] < t && i - 1 >= 0) dfs(i - 1, j, t);

}

int main() {

    int t;

    while(true) {

        scanf("%d %d", &n, &t);
        if(n == 0) break;

        for(int i = 0; i < n;+ ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &v[i][j]);
            }
        }

        memset(vis, false, sizeof vis);

        for(int j = 0; j < n; ++j) {
            if(!vis[0][j] && v[0][j] < t) {
                dfs(0, j, t);
            }

            if(!vis[n-1][j] && v[n-1][j] < t) {
                dfs(n-1, j, t);
            }

            if(!vis[j][0] && v[j][0] < t) {
                dfs(j, 0, t);
            }

            if(!vis[j][n-1] && v[j][n-1] < t) {
                dfs(j, n-1, t);
            }
        }


        int ans = 0;
        for(int i = 0; i < n;+ ++i) {
            for(int j = 0; j < n; ++j) {
                if(!vis[i][j]) {
                    ans++;
                }
            }
        }

        printf("%d\n", ans);

    }


    return 0;

}