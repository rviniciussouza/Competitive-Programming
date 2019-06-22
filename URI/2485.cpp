#include <bits/stdc++.h>
using namespace std;

int n, m;
typedef pair<int, int> ii;
int grid[110][110], vis[110][110];


int BFS(int x, int y) {

    queue<pair<int, int> > fila;
    fila.push(make_pair(x,y));
    vis[x][y] = 1;
    int ans = 1;

    while(!fila.empty()) {
        ii u = fila.front(); fila.pop();
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                    int a = u.first + i;
                    int b = u.second + j;

                    if(a < 0 or a >= n or b < 0 or b >= m) continue;

                    if(grid[a][b] == 1 && vis[a][b] == 0) {
                        vis[a][b] = vis[u.first][u.second] + 1;
                        ans = max(ans, vis[a][b]);
                        fila.push(ii(a, b));
                    }
            }
        }
    }

    return ans;
}

int main() {

    int k,x,y ,ans;

    scanf("%d", &k);

    while(k--) {

        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        memset(vis, 0, sizeof vis);
        scanf("%d %d", &x, &y);
        printf("%d\n", BFS(x-1, y-1) - 1);

    }

    return 0;
}